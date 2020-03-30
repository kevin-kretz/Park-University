 # Unit 2 - Programming Assignment
 # By Kevin Kretz | 20 June 2019
 # Creates four Ohio State block O logos.  Ensure you make the window full screen if necessary.

import turtle

wn = turtle.Screen() #creates "wn" Screen object
kevin = turtle.Turtle() #creates "kevin" Turtle object

wn.bgcolor("#666666") #sets window background color to official Ohio State gray
wn.screensize(1200, 900) #sets screen size to fit all 4 drawings

kevin.penup() #picks up the pen to not draw while moving to starting position
kevin.setx(-500) #moves kevin to the starting x position
kevin.sety(-134.4) #moves kevin to the starting y position
kevin.color("#bb0000") #changes kevin to official Ohio State Ohio State scarlet
kevin.width(50) #changes width of kevin to 50

#assigns variable names to appropiate lengths
short = 100
side = 175
corner = 62.5
#I feel creating a left variable is unnecessary becuase rotating left 45 degrees is self explanitory


def draw_block_o(): #defines a function to draw the Ohio State block O when called.
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

def move_pen_right(): #defines a function to move kevin over and make room for the next O
    kevin.penup()
    kevin.forward(300) #kevin is already facing to the right, so no direction change is necessary

for i in range(4): #defines a function to draw 4 O's using the functions created above.
    draw_block_o()
    move_pen_right()

wn.exitonclick() #program exits on click
