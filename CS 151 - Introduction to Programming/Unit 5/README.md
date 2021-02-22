# Project
Pig Latin is a language that’s used by kids for fun. To form a Pig Latin sentence, you take a regular sentence and rearrange the letters within each word as follows. Move the first letter to the end of the word and append "ay" after that moved letter. When writing the result, you should use all uppercase. For example, "horse" would convert to "ORSEHAY" and "ice cream" would convert to "CEIAY REAMCAY."

For this project, write a Pig Latin generator that prompts the user to input a line of text and outputs the line translated to Pig Latin.

You are not required to perform input validation on the user-entered line. You may assume that the user enters all alphabetic characters, except for single spaces that are used to separate each word.

To distinguish between the words in the line, you will need to search for a space character that follows each word. To make it easier to find the last word, after reading the entered line, you should append a space character to the end of the line.

## Sample session:
```
Welcome to the Pig Latin generator!
Please enter a line of text to be converted into Pig Latin:
Porcine valves ARE the awesomest

Here is your translation:
ORCINEPAY ALVESVAY REAAY HETAY WESOMESTAAY
```
<br />
<br />
<br />

# Extra Credit (2 pts)
With formal Pig Latin (favored by the indigenous pigs in Oklahoma’s panhandle), words that begin with vowels are special. If a word begins with a vowel, do not move the word’s first letter, and append "WAY" to the end of the original word. Add this feature to your program. Hint: Use a named constant for a string that contains all the vowels, and use the ```contains``` method with that named constant to determine if a word’s first letter is a vowel.

## Sample session:
```
Welcome to the Pig Latin generator!
Please enter a line of text to be converted into Pig Latin:
Porcine valves ARE the awesomest

Here is your translation:
ORCINEPAY ALVESVAY AREWAY HETAY AWESOMESTWAY
```
