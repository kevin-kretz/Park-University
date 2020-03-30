# Introduction
This assignment lets you practice with reading from a file, writing to a file, and using dictionaries.

## Preparation
This assignment must be done in a standalone Python environment, not the textbook. See the Textbooks and Materials page for instructions on installing the compiler on your local computer or using Park’s virtual desktop.

Download the data file [state_crime.csv](./state_crime.csv). This data file contains records of different types of reported crimes. The first line of the file contains a description of each column of data.

## Directions
Write a python program to read the file, and produce a summary of the total reported crimes for each state. The report will look something like this, though don't worry if your list is not in alphabetical order:
```
State            Reported Crimes      
Alabama                8,133,055
Alaska                 1,198,047
...
Wyoming                  834,588
United States        563,841,249
```

There are a lot of fields in the data file, but you can simplify your life by using subtotal fields, `Totals.Property.All` and `Totals.Violent.All`.

Once you  have the summary, change your program so it writes the summary to a file, `crime_summary.txt`.

Make sure you use a dictionary for this assignment. The obvious case is to use a key of state names and the value is the accumulated count of reported crimes. There might be a place for another dictionary as well, though you only need to use one.

Be sure to add a header comment to your program and any functions, and appropriate comments before other blocks of code.
