"""
 Unit 4 - Programming Assignment
 By Kevin Kretz | 04 July 2019
 This program has a turtle draw a line around the screen.  It randomly turns left or right 90 degrees and
 then draws a line forward while the turtle is still on the screen.
"""

import random
import turtle

def isInScreen(win,turt):
    """Using the window from the first parameter and the turtle from the second parameter, return whether the turtle is is still in the screen."""
    leftBound = -win.window_width() / 2 #gathers the cordinates of the left screen boundry
    rightBound = win.window_width() / 2 #gathers the cordinates of the right screen boundry
    topBound = win.window_height() / 2 #gathers the cordinates of the top screen boundry
    bottomBound = -win.window_height() / 2 #gathers the cordinates of the bottom screen boundry

    turtleX = turt.xcor() #gathers the x cordinate of the turtle's current position
    turtleY = turt.ycor() #gathers the y cordinate of the turtle's current position

    stillIn = True #creates a variable called stillIn and sets it to true
    if turtleX > rightBound or turtleX < leftBound: #if the turtle's x cordinate is farther than the right or left screen boundry
        stillIn = False #change stillIn to false
    if turtleY > topBound or turtleY < bottomBound: #if the turtle's y cordinate is farther than the top or bottom screen boundry
        stillIn = False #change stillIn to false

    return stillIn #return stillIn

def moveTurtle(turtle):
    """Randomly generates a pain level of 1-10.  If a turtle pain level is 10, it is not permitted to move.  Otherwise, the turtle will randomly rotate 90 degrees left or right and then move 50 pixels in that direction."""
    pain = random.randrange(1, 11) #defines a new variable named pain and sets it to a random number between 0 - 9
    if pain != 10: #if a turtle reaches a pain level of 10, it is not allowed to move
        coin = random.randrange(0, 2) #defines a new variable named coin and sets it to a random number either 0 or 1
        if coin == 0: #if coin equals 0
            turtle.left(90) #the turtle rotates 90 degrees to the left
        else: #otherwise (if coin equals 1)
            turtle.right(90) #the turtle rotates 90 degrees to the right

        turtle.forward(50) #moves the turtle forward 50 pixels

def areAtSamePosition(turtle1, turtle2):
    """Rounds the cordinates of the turtles position to the nearest whole number, and returns if the turtles are in the same position."""
    turtle_1_xcor = round(turtle1.xcor()) #rounds the x cor to the nearest whole number
    turtle_1_ycor = round(turtle1.ycor()) #rounds the y cor to the nearest whole number
    turtle_2_xcor = round(turtle2.xcor()) #rounds the x cor to the nearest whole number
    turtle_2_ycor = round(turtle2.ycor()) #rounds the y cor to the nearest whole number
    return (turtle_1_xcor == turtle_2_xcor) & (turtle_1_ycor == turtle_2_ycor) #if both turtle's x and y cordinates are equal, return true, otherwise return false

def main():
    """This function has a turtle randomly turn left or right 90 degrees and then draws a line forward while the turtle is still on the screen."""
    wn = turtle.Screen() #set a variable wn to the turtle screen
    june = turtle.Turtle() #defines a new turtle named june
    kevin = turtle.Turtle() #defines another turtle named kevin

    june.shape('turtle') #sets the turtle June to the shape of a turtle
    kevin.shape('triangle') #sets the turtle Kevin to the shape of a triangle

    june.color("purple") #sets junes color to purple
    kevin.color("red") #sets kevin's color to red

    kevin.penup() #picks up the pen so the turtle kevin does not draw a line when moving to starting position
    kevin.goto(50, 0) #the turtle kevin moves to the starting location
    kevin.pendown() #sets the pen down to begin drawing the lines.

    while isInScreen(wn,june) & isInScreen(wn, kevin): #loops the following code if the isInScreen function using the window wn and the turtle june returns true
        if areAtSamePosition(kevin, june): #checks if the turtles are at the same position
                break #if so breaks from the program
        moveTurtle(june) #moves the turtle june
        if areAtSamePosition(kevin, june): #checks if the turtles are at the same position
            break #if so breaks fromt the program
        moveTurtle(kevin) #moves the turtle kevin

    if isInScreen(wn, kevin) & isInScreen(wn, june): #determines if both turtles are on the screen
        kevin.write("There is no winner") #if so declares a tie
    elif isInScreen(wn, june): #if june is on the screen
        june.write("kevin wins!") #declares kevin the winner
    else: #if kevin is on the screen
        kevin.write("june wins!") #declares june the winner

    wn.exitonclick() #the screen pauses until clicked on to exit

main() #runs the main function
