# Introduction
This assignment lets you practice using strings, including slices and other string methods.

## Preparation
Review the string functions in section 9.5 of the text. You should be able to complete the assignment using these functions and string slices, although there are many other possible approaches. You may also find the function `isdigit()` helpful, though it is not necessary. Download the starter program, [CityState.py](./CityState.py), compile and run. This gives you the list of data to use to test your program.

## Directions
Your assignment is to take a list of strings representing [city, state, and zip code] and print them in a nice table, one per line. However, the data was input on a keyboard that had a temperamental space bar. Sometimes it doesn't work and other times it generates multiple spaces, so the data may look like
```
'Rolla,MO   65402'
```
or
```
'Springfield, MO65897'
```
The one thing that is consistent is that there is a comma after the city name, the state is always two upper case characters, and the zip code is 5 adjacent characters 0-9.

Your program needs to find the individual components [city, state, zip] in the string, then print them lined up in columns.

One problem is the length of the city name. A simple way to start is to always make the city name be 15 characters long. Look at the string methods in section 9.5 for how to do this. You may have to look on the web for some additional examples. Here is what your output would look like doing that:
```
Cape Girardeau  MO 63780
Columbia        MO 65201
Kansas City     MO 64108
Rolla           MO 65402
Springfield     MO 65897
St Joseph       MO 64504
St Louis        MO 63111
Ames            IA 50010
Enid            OK 73773
West Palm Beach FL 33412
International F MN 56649
Frostbite Falls MN 56650
```
A nicer table would always print out the full city name, not just the first 15 characters, but still line things up nicely. For full credit, make it so that there is exactly one space after the longest city name and the start of the state column, like this:
```
Enid                OK 73773
West Palm Beach     FL 33412
International Falls MN 56649
Frostbite Falls     MN 56650
```
To make things interesting, add two more cities of your own at the end of the list.

## Notes
Be sure to document your program with an appropriate header comment, including your name, date, and description of what the program does. Also add comments before blocks of code, rather than at the end of a line.

There are two pieces to this assignment, getting slices of one string and printing the pieces in a table. Work on one of these at a time.

Since the data in the list is right in front of you, you'll be tempted to count the number of characters in the longest city by hand and hard code that value into your program. That's not going to earn full credit. An easy way to check your program is to get it working with the current data, then delete the line with International Falls and rerun your program. If it still prints the state one space after the longest city, then you figured out a good solution.
