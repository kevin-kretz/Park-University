#Kevin Kretz | June 20, 2019 | Creates four Ohio State block O logos.  Ensure you make the window full screen if necessary.

import turtle
import random

wn = turtle.Screen() #creates "wn" Screen object
kevin = turtle.Turtle() #creates "kevin" Turtle object

wn.bgcolor("#666666") #sets window background color to official Ohio State gray
wn.screensize(1200, 900) #sets screen size to fit all 4 drawings

kevin.penup() #picks up the pen to not draw while moving to starting position
kevin.goto(-500, -134.4) #moves kevin to the starting position
kevin.color("#bb0000") #changes kevin to official Ohio State scarlet
 #changes width of kevin to 50

def change_pen_width(scale):
        """Changes pen width based on the scale."""
        kevin.width(50 * scale)

def change_short_length(scale):
        """Changes length of the short line based on the scale."""
        short = 100 * scale
        return short

def change_side_length(scale):
        """Changes the length of the side line based on the scale."""
        side = 175 * scale
        return side

def change_corner_length(scale):
        """Changes the length of the corner lines based on the scale."""
        corner = 62.5 * scale
        return corner

def draw_block_o(): #defines a function to draw the Ohio State block O when called.
        """Chooses a random scale percentage, changes the length of the lines, width of the pen and then draws an Ohio State block O."""
        scale = random.randint(10, 100) / 100 #chooses a scale for the size of the O between 1% - 100%;
        change_pen_width(scale) #changes the pen width acording to the scale
        short = change_short_length(scale) #changes the short length acording to the scale
        side = change_side_length(scale) #changes the side length acording to the scale
        corner = change_corner_length(scale) #changes the corner length acording to the scale

        for i in range(2): #each loop draws half of the O, so it is placed in a for loop to draw each half
                kevin.pendown()
                kevin.forward(short)
                kevin.left(45)
                kevin.forward(corner)
                kevin.left(45)
                kevin.forward(side)
                kevin.left(45)
                kevin.forward(corner)
                kevin.left(45)

def move_pen(): #defines a function to move kevin over and make room for the next O
        """Picks up the pen, moves it to the right 300 pixels and then randomly moves up or down a random distance between 25-200 pixels."""
        kevin.penup()
        kevin.forward(300) #kevin is already facing to the right, so no direction change is necessary
        direction = random.randint(0, 99)
        if (direction < 50):
                kevin.left(90)
                kevin.forward(random.randint(25,200))
                kevin.right(90)
        else:
                kevin.right(90)
                kevin.forward(random.randint(25,200))
                kevin.left(90)

for i in range(4): #a for loop to draw 4 O's using the functions created above.
        draw_block_o()
        move_pen()

wn.exitonclick() #program exits on click
