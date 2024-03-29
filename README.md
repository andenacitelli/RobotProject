# Robot Project

## Overview

This is the codebase for a 3-month-long project completed as part of ENGR 1281.02H (Fundamentals of Engineering for Honors II - Robotics), a project class in Ohio State's College of Engineering Honors Program. 

There was an official website completed as part of the project, but is inaccessible without an Ohio State account, so I made a website to highlight the project on my own. Videos and pictures of the project as well as more documentation can be found on my website, located at https://andenacitelli.com/robotproject (Note: The website is not yet written, but I plan to build it sometime Fall 2019). 

## Project Description 

Each team, made of 4 people, was to conceive, design, build, and program a small robot that navigates through a roughly 4' by 8' obstacle course. The robot intelligently completed tasks like dropping a token into a slot, measuring light sensor output and pathfinding to a button based on that output, pulling foosball score counters, and pressing a lever, among others. The course was important, but a large focus of the project was on documentation, project management, and the design process.

### Team Members' Roles

Anden - Wrote the code, with Jason helping out briefly with one of the performance tests and some very early code. Was responsible for making sure the robot performed well on-course during performance tests and during the competition itself. 

Jason - Did most of the construction and fixed most mechanical issues. Occasionally helped with the code and with debugging. Worked some on documentation, report-writing, and the website. 

Joe - Worked heavily on documentation, report-writing, and the website, alongside helping often with testing. 

Keely - Worked heavily on documentation, report-writing, and the website. Did the CAD models for the robot. 

## Competition and End-Of-Project Results 

By the end of the project, the robot performed very well, able to complete a perfect run about 60% of the time. Occasional consistency issues accounted for the rest of the runs, where we would usually get 80-90% of the points. Only about ~20 teams out of the total 66 were able to complete a perfect run by the end of the project. Our runs took about 1:10, which was faster than maybe 6-7 of those teams, leaving us as something like the ~8-9th best robot (estimate). 

We made an incredible amount of progress in the week before the competion. However, we were seeded very poorly, as seeding was done a full week beforehand, and we were put up against a top-4 team first round and subsequently eliminated despite a near-perfect run. 

We also won two out of our three round-robin tournament runs. Our first run was a win, where we didn't have a perfect run but performed very well, beating everyone else out. Our second run was also a win, which was also almost a perfect run but stopped just short of the end button due to an error I never figured out, but tracing the logs, the microcontroller must have lost power unexpectedly. Our last run highlighted a fault in our code where our calibration procedure could accept invalid GPS coordinates, which allowed us to fix that for our more important tournament runs. Overall, we were very happy with our round-robin results. 

## Technical Specifications 

Regarding less technical aspects of the project, like report-writing, documentation, and the website, please refer to our website, linked above. This README will go much more in-depth into the technical aspects of the code. This README will go into several of the most notable systems implemented in the code. 

### Navigation & Robot Positioning System
Our robot had access to something called the "Robot Positioning System" (RPS) which was basically just a GPS system that gave you (x, y) coordinates for where the robot was. Our robot worked heavily off of a function where you could feed in a (x, y) coordinate and the robot would intelligently turn towards it, drive towards it while intelligently autocorrecting, and stop within a specified tolerance of that point. Our "Final Routine", which is our robot going from task to task and doing them, is largely just calls to this function, because it's what does essentially all of our positioning. 

Also of note is the fact that RPS has a "deadzone" for the top quarter of the course, where it just wouldn't give you RPS data. This could be circumvented by holding down a button earlier on in the course, which would give you access to RPS in a deadzone for a specified amount of time. We hit this button, but implemented backup strategies should the robot be in the deadzone when the RPS deadzone timer ran out and the robot was again left with RPS. Our robot semi-intelligently paths around a large dodecahedron located nearby, and goes south until it gets RPS back. It then completes the rest of the course. 

### Code Organization & Documentation

With a project with so many moving parts, it became quickly apparent that we wouldn't be able to shove everything in one file. We split up the code into ~10 header files in order to make development quicker and make it easier to find and tweak functions when debugging. This paid huge dividends later in the project when we had thousands of lines of code and had to tweak small, specific parts of the code. 

We also documented each function with a format similar to JavaDoc, where parameters were listed, the function was described, and return values were explained. This allowed the members of our team that hadn't worked with the code much to more quickly understand specific functions. It made it so our team didn't necessarily have to understand the code itself to understand what it does and how it accomplishes that. 

### Modularity

Modularity, with respect to general programming philosophy and function structure, was a huge part of the code for our project. The main goal of our code was to be simple, but able to be used for a wide variety of use cases. Our code could do a huge assortments of tasks intelligently. Our code would automatically make adjustments if the robot screwed up one part of the routine. 

This focus on modularity also paid huge dividends towards the end of our project. It made development much quicker. Our first performance test needed us to place the robot down at just the right position in order to do the performance test right due to the hardcoding involved. We improved on that, and during later performance tests, the individual competition, and the competition in the RPAC. We were able to just make a single call to a function, pass it in an (x, y) coordinate, and watch it work as intended, automatically making corrections whenever it made something wrong. 

