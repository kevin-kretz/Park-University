# Introduction
This assignment lets you practice with writing and using conditional statements, boolean functions, and while loops.

## Preparation
Download the program [RandomTurtle-book-main.py](../RandomTurtle-book.main.py) which is the program from the book, but with a main function and better variable and parameter names. Make sure you can run the program before you do anything else.

## Directions
Modify the program in the following ways:

1. Write appropriate comments for this program and function. Include:
    1. A header comment for the program
    2. A header for the function describing the parameters and return value.
    3. Comment the blocks of code. 
    *The text has descriptions of all this, so reread that if necessary.*
2. Create a second turtle and start it at a different location than the current one. The location should be 50 units away, either horizontally or vertically. Have both turtles move randomly, but independently, so you will have to flip a coin for each turtle.
3. Modify the while loop so that the program stops when either turtle leaves the screen. This is pretty easy, once you see it.
4. After the loop, print a message indicating which turtle won. You decide whether it was the one still in the screen or the one that left. Use the turtle that left the screen to write the message (see the write() function in the turtle module).
5. Write a Boolean function that has two turtles as parameters, and returns True if the turtles are at exactly the same location, and False otherwise.
6. Call your Boolean function from Step 5 to also stop the program when the two turtles end up at the same location. In this case, print there was no winner. This is very much like step 3.
7. Add another feature to your program. Some ideas are a) a fancier ending message, b) a third turtle, c) more randomness, like letting a random turtle go first each time or having a turtle randomly skip a turn, or ???

*This doesn't have to be too fancy, but should be more than just adding one line of code.*
