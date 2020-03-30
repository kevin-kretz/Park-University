# Draws 3 sets of shapes of varying lengths
#   Draw a rectangle
#   Draw a line the length of the rectangle's perimeter
#   Draw a circle with the same area as the rectangle

import turtle
import math

def next_y_position(y,ht):
    """ Returns the next y-position, given current position y and height ht """
    next = y + ht + 30
    return next

def drawRect(t, len, wid):
   """ Draws a rectangle using turtle t with sides len and wid """
   for side in [len, wid, len, wid]:
      t.forward(side)
      t.left(90)

def skipForward(t, len):
    """ Moves the turtle t forward len units without drawing anything. """
    t.up()
    t.forward(len)
    t.down()

def skipTo(t, x, y):
    """ Moves the turtle t to coordinates (x,y) without drawing anything. """
    t.up()
    t.goto(x, y)
    t.down()

def perimeter(len,wid):
    """ Returns the perimeter of rectangle with sides len and wid. """
    return (len * 2) + (wid * 2)

def circ_rad(len, wid):
    """ Returns the radius of a circle with an area of len * wid """
    return math.sqrt(len*wid/math.pi)

def main():
    # named constants
    screen_size = 500
    screen_startx = 60 # x coordinate of the left edge of the graphics window

    # Set up the window and its attributes
    wn = turtle.Screen()              
    wn.bgcolor("lightblue")
    wn.setup(screen_size, screen_size, screen_startx, 0)

    alex = turtle.Turtle()

    # Initial turtle position near left edge, toward the bottom
    xpos = -screen_size/2 + 20 
    ypos = -screen_size/2 + 50
    
    skipTo(alex, xpos, ypos)
    
    # y-dimension of each rectangle
    width = 50
    
    # draw three sets of shapes - same width(y-dimension) but different lengths
    for length in [25, 50, 75]:

        # Draw the rectangle
        drawRect(alex, length, width)

        # Move a little to the right of the rectangle
        skipForward(alex, length + 10)

        # Draw the line the same length as the perimeter of the rectangle
        alex.forward(perimeter(length, width))

        # Move a little to the right of the line
        skipForward(alex, 20)

        # Draw a circle with the same area as the rectangle
        alex.begin_fill()
        rad = circ_rad(length, width)
        alex.circle(rad)
        alex.end_fill()

        # Next vertical position for a set of shapes
        ypos = next_y_position(ypos, width)
        
        # Put turtle to left side of screen at correct height
        skipTo(alex, xpos, ypos)      

# Run the main function. This should be the last statement in the file.
main()
