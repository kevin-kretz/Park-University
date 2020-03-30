# Introduction
This assignment lets you practice with reading from a file and manipulating lists.

## Preparation
This assignment must be done in a standalone Python environment, not the textbook. See the Textbooks and Materials page for instructions on installing the compiler on your local computer or using Park’s virtual desktop.

1.  Download the following all to the same folder:
    1. The program [Lab9-start.py](./Lab9-start.py)
    2. The data files [health-no-head-sample.csv](./health-no-head-sample.csv) and [health-no-head.csv](./health-no-head.csv) 
    
    *The big data file contains records of some infectious diseases from 1928 to 2011. The  small one only includes data from 3 years from 5 states. Run the python program. It should print something like this*
    ```
    MEASLES,206.98,COLORADO,2099,1014000,1928

    ['MEASLES', '206.98', 'COLORADO', '2099', '1014000', '1928\n']
    MEASLES,634.95,CONNECTICUT,10014,1577000,1928 

    ['MEASLES', '634.95', 'CONNECTICUT', '10014', '1577000', '1928\n']
    MEASLES,256.02,DELAWARE,597,233000,1928

    ['MEASLES', '256.02', 'DELAWARE', '597', '233000', '1928\n']
    ...
    ```
2. Make sure that you get output like this before starting the assignment or writing any additional code.

## Directions
Modify the program in the following ways:

1. Write each line as part of a table, include a header before the table, and a summary line at the end. Use a fixed width for each column (don’t try to find the largest width like you did in the previous unit). You should end up with something like
```
State                 Disease        Number      Year

COLORADO              MEASLES         2,099      1928
CONNECTICUT           MEASLES        10,014      1928
DELAWARE              MEASLES           597      1928
…
DELAWARE              SMALLPOX            0      1930
DISTRICT OF COLUMBIA  SMALLPOX            0      1930
FLORIDA               SMALLPOX           28      1930
                      Total          52,307  
```
*Not every field of the original line is used in the output. You will have to do some research about the .format() function to print the number of cases with a comma. If you can’t get the comma in the number column, move on and come back to that once you have more of the program written. The key is to have all the columns line up.*

2. Use some if statements to add three filters to your program that let the user select exactly one state, disease and year to include in the report. Prompt the user to enter these values.
```
Enter state: Colorado
Enter disease: smallpox
Enter year: 1928
State                 Disease        Number      Year

COLORADO              SMALLPOX          340      1928
                      Total             340
```
*Unfortunately, this isn’t very flexible.*

3. Change your program so that if the user just hits return for a prompt, the program includes all the data for that field. For example:
```
Enter state (Empty means all): Colorado
Enter disease (Empty means all):
Enter year (Empty means all): 1928
State                 Disease        Number      Year
 
COLORADO              MEASLES         2,099      1928
COLORADO              POLIO              71      1928
COLORADO              SMALLPOX          340      1928
                      Total           2,510    
```
*Your program should run as expected using this small data set*

4. Change the open statement in the program to use the full data set, health-no-head.csv.
5. Write down the answers to the following queries:
    1. How many cases of Hepatitis A were reported in Utah in 2001?
    2. How many cases of polio have been reported in California?
    3. How many cases of all diseases were reported in 1956?
6. Add another feature to your program. 
*This could be something like printing the highest and lowest numbers for each query, or allowing the user to just type the first part of value, so that entering 20 for the year generates a table for years 2000, 2001, 2002, … 2011, or entering D for a state gives information on Delaware and the District of Columbia. Or maybe leverage your previous assignment and make the column only as wide as they need to be for the data. Try to make it something useful.*

7. Comment your code.
*Be sure to add a header comment to your program and any functions, and appropriate comments before other blocks of code.*
