## Project 1 - Warehouse Project
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
