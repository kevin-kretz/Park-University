## Project 1
### Instructions
A warehouse holds items in “racks,” where each rack has multiple shelves. The racks are referred to by single uppercase letters (e.g., C or P), the shelves are referred to by integers, and items are referred to with a short description (e.g., popcorn maker, linens).

In the warehouse, workers receive requests to retrieve items. Each request is formatted “rack-shelf item”. For example: C-3 popcorn maker.

Write a Java program that handles creating an item request. Your program should ask the user for the item, the rack letter, and the shelf number. For the rack letter, your program must be able to accept the letter by itself or the associated word in the military phonetic alphabet such as Alpha for A, Bravo for B, and so on. If the user enters a military phonetic word, your program uses the first character from the word.

Although you could get your program to work using all string variables, for practice purposes, **you are required to store the rack letter in a char variable and the shelf number in an int variable.**

You should assume that the user enters valid inputs, including uppercase for the rack letter.

Note the sample session below. As always, you must mimic the sample session precisely. In particular, note the colons, blank spaces, etc. To generate the blank line, use an empty println statement like this:

```Java
System.out.println();
```
### Sample Session
```
Enter the item: food processor
Enter the item's rack letter: Bravo
Enter the item's shelf number: 5

Sending a request for B-5 food processor.
```


## Project 2
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
