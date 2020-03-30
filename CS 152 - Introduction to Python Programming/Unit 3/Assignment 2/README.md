# Introduction
This assignment lets you practice with writing and using functions. You are rewriting existing code to use functions so the behavior of the program should not change throughout this exercise.

## Preparation
Download and run the program PracticeFunctions.py.Preview the document Look at what it does and look at the code to get an idea of the program structure.

## Directions
The programming assignment for this unit has two functions.

1. Use these two functions as models for the functions you are to write.  
*You will be removing code from main() and putting it in several separate functions. The behavior of the program will not change throughout the exercise, so you can always tell if your program is correct.*
2. Use the non-fruitful function `drawRect` as a model. Write another non-fruitful function that moves a turtle forward without drawing a line. The function is defined as
```python
def skipForward(t, len):

    """ Moves the turtle t forward len units without drawing anything. """
```
and called with a statement like
```python
skipForward(alex, 20)
```
*The contents of the function are to lift the pen, move the turtle, then lower the pen.*

3. Write another non-fruitful function skipTo, which is defined as
```python
def skipTo(t, x, y):

    """ Moves the turtle t to coordinates (x,y) without drawing anything. """
```
and is called with
```python
skipTo(alex, xpos, ypos)
```
Make sure to use the parameters `x` and `y` in the body of this function.

*Next, you'll work with fruitful functions. Look at the function to calculate the next y-position for drawing a set of shapes. This function is called near the bottom of the program:*

```ypos = next_y_position(ypos, width)```

4. Using this function as a model, add a fruitful function to calculate the perimeter of a rectangle. The function is defined with
```python
def perimeter(len,wid):
    """ Returns the perimeter of rectangle with sides len and wid. """
```
and  it is called with the statement
```python
p = perimeter(length, width)
```
*Make sure you use the parameters `len` and `wid` in the body of the function.*

5. Again, using this function as a model, add a fruitful function to calculate the value `math.sqrt(length*width/math.pi)` which appears near the end of the program. The function should be defined as
```python
def circ_rad(len, wid):
    """ Returns the radius of a circle with an area of len * wid """
```
Mimic the call from what you did in the previous step.

6. Make sure that your main function is calling skipForward and skipTo in at least two different statements. This is one of the benefits of using functions is that you can call them multiple times, often with different parameters. Ask if you are unsure what this means.
7. Make sure your functions have the same parameters and the same comment as in the assignment description. Write a complete header comment.
