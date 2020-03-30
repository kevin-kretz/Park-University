import random
import turtle

def isInScreen(win,turt):
    leftBound = -win.window_width() / 2
    rightBound = win.window_width() / 2
    topBound = win.window_height() / 2
    bottomBound = -win.window_height() / 2

    turtleX = turt.xcor()
    turtleY = turt.ycor()

    stillIn = True
    if turtleX > rightBound or turtleX < leftBound:
        stillIn = False
    if turtleY > topBound or turtleY < bottomBound:
        stillIn = False

    return stillIn

def main():
    wn = turtle.Screen()
    # Define your turtles here
    june = turtle.Turtle()


    june.shape('turtle')
    while isInScreen(wn,june):
        coin = random.randrange(0, 2)
        if coin == 0:
            june.left(90)
        else:
            june.right(90)

        june.forward(50)

    wn.exitonclick()

main()
