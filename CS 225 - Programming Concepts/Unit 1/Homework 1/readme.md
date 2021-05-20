# Instructions

Employees in Great Company are given a pay raise each year based on their performance.  Write a program for their HR department to automatize the pay raise.  Your program will read the current salary data from a text file called curSalary.txt with unknown number of records (... indicates there may be more records):
```
   Jacobs Tom 56789.50 6.2
   Nichols Mary 42010.87 2
   Carpenter Nathan 67400.25 5
   ...
```
Each line of the input file consists of an employee’s **last name, first name**, current salary, and pay increase percent. For example, in the first line, the last name of the employee is Jacob, the first name is Tom, the current salary is 56789.50, and the pay increase is 6.2%.  Your program will calculate the salary after the raise and store the data in another text file called `newSalary.txt`.  For each employee, the result will be saved in the format of: **firstName lastName** updatedSalary.  Format the salary result to two decimal digits.

For the given data, your program should report # of records processed and the output file should contain those lines:
```
   Tom Jacobs 60310.45
   Mary Nichols 42851.09
   Nathan Carpenter 70770.26
   5 records processed and saved in "newSalary.txt".
```
If the input file is empty, you should leave the output file empty and notify the user with a proper message:
```
   Warning: Empty input file. Output file created but is empty.
```
When working with files, you should always check whether the opening operation was successful, as shown in examples in Unit 1 slides.

Comment your program appropriately.  Pay attention to the standard stuff like coding style, indention, heading, and curly braces.  
