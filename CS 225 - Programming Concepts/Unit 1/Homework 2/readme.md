# Instructions

To make telephone numbers easier to remember, some companies use digits and letters (or only letters) to show their telephone number. In some cases, to make a telephone number meaningful, companies might use more than seven digits and letters. Here are some examples: 
Phone Number in Display | Note | Actual Phone Number
----------------------- | ---- | -------------------
GET LOAN | - | 438-5626
CALL HOME | More than seven digits/letters used for ease of remembrance. | 225-5466
111 GOLD | - | 111-4653
Glass4u | - | 452-7748

Write a program that prompts the user to enter a telephone number expressed in letters (or digits and letters) and outputs the corresponding telephone number in digits. If the user enters more than seven characters, then process only the first seven valid digits. Also output a - (hyphen) after the third digit. Allow the user to use digits, both uppercase and lowercase letters, and spaces between words.

If a number contains invalid letters such as a number GOT $$99, your program should report and terminate the processing of that phone number (do not terminate the whole program) and ask for another number. 

Your program should process as many telephone numbers as the user wants.  You may use any valid approach to allow multiple sessions until user chooses to stop, such as `CTRL+Z`, enter y/n, enter q and so on.  Whatever approach you use, provide proper prompt message(s) to users so they know how to use your program.Provide at least three testing cases (sample input and expected output for each testing case) and explain why you picked those three (how they test different parts/functionality of your program).  Provide screenshots of execution of your program for those testing cases.

You may want to use the string class (<string>) for this assignment.  To access individual characters, use [].  For example, str[2] will retrieve the char at index 2 (index starts at 0) in string str.  See ch7, p492-495 for examples of how to use the string class.
  
Comment your program appropriately.  Pay attention to the standard stuff like coding style, indention, heading, and curly braces.  
