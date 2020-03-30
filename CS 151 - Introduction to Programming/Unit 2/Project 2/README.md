## Project 2 - GPA Calculator
### Instructions
Suppose you are developing an app that calculates the grade point average (GPA) of students for Park University. For this project, you are to provide a pseudocode algorithm that calculates and prints the GPA of a student for a semester (if you prefer to use Java code, that’s OK, but it’s not required). Your algorithm should ask the user for the number of courses they are taking that semester. Use a counter loop such that each time through the loop, the user is prompted to enter a grade for a course and the credit hours of that course. In entering a grade, use 4 for an A, 3 for a B, 2 for a C, 1 for a D, and 0 for an F.

Here’s the formula for calculating GPA:

GPA = ∑ (course grade * course credit hours) ÷ total credit hours

In other words, for each course, you should multiply its grade (4, 3, 2, 1, or 0) by its credit hours. Find the sum of all those products. Divide that sum by the total number of credit hours.

### Sample Session
```
How many courses did you take this past semester? 2
Enter the grade for a course (A=4, B=3, C=2, D=1, F=0): 4
Enter the credit hours for that course: 3
Enter the grade for a course (A=4, B=3, C=2, D=1, F=0): 3
Enter the credit hours for that course: 4
Your GPA for this semester is 3.428571
```

Provide a graceful response if the user enters 0 for the number of courses:

```
How many courses did you take this past semester? 0
Sorry, your GPA cannot be calculated.
```
