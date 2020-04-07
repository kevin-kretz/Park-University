## Project

Basal metabolic rate (BMR) is a term that refers to the rate of energy expenditure per unit time of warm-blooded creatures at rest. In other words, BMR tells us how many calories we should eat to support all of our basic body functions such as breathing, blood circulation, and cell growth. One common way to calculate a person’s BMR is to use the Harris-Benedict equation. The Harris-Benedict equation factors in a person’s weight, height, and age, and returns the basal metabolic rate for that individual person.

These are the original Harris-Benedict equations as published in 1918 and 1919. Various newer versions exist, but for our purposes we will use the originals.

The formula for a man is defined as:

- BMR = 66 + (6.2 × weight in pounds) + (12.7 × height in inches) – (6.76 × age in years)

The formula for a woman is defined as:

- BMR = 655.1 + (4.35 × weight in pounds) + (4.7 × height in inches) - (4.7 × age in years)

Write the code for the HarrisBenedict program to accept input for a person’s weight, height, and age, and then display the basal metabolic rate for that person.

Afterward, ask the user to choose from a selection of foods and then output the number they may eat to maintain their current body weight based on their BMR.

Note:

- Use named constants to store the number of calories for each food item.
- You are required to perform input validation for the sex user input. Force the user to enter m, M, f, or F.
- You are required to perform input validation for the food selection input. Force the user to enter 1, 2, or 3.
- You are not required to perform input validation for the weight, height, or age inputs.

### Sample session:

```
Welcome to the basal metabolic rate calculator.
Are you male 'm' or female 'f'? t
Invalid input. Please enter 'm' for male or 'f' for female.
Are you male 'm' or female 'f'? M
How much do you weigh (in pounds)? 160
How tall are you (in inches)? 70
What is your age? 22

You entered:
Gender: M
Weight: 160 lbs
Height: 70 inches
Age: 22 years old

Your basal metabolic rate is: 1798.28

What food would you like to eat?
1) chocolate bar (210 calories)
2) pepperoni pizza slice (300 calories)
3) baby carrot (4 calories)
Selection: 4

Sorry, that's not a valid selection. Try again.
Selection: 3

With your BMR, you can eat 449.57 baby carrots to maintain your body weight.
Thank you for using the basal metabolic rate calculator.
```
