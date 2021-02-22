/***************************************************************************
* Unit 5: Assignment + Extra Credit
* Kevin Kretz
* 21 April 2020
*
* This is a Pig Latin generator that prompts the user to input a line * of text and outputs the line translated to Pig Latin in upper case.
***************************************************************************/
 
import java.util.*;
 
public class Test {
  public static void main(String[] args) {
    Scanner userInput = new Scanner(System.in);
    String originalString;
    String translatedString = "";
    int wordStartingIndex = 0;
    String currentWord = "";
 
    System.out.println("Welcome to the Pig Latin generator!");
    System.out.println("Please enter a line of text to be converted into Pig Latin:");
    originalString = userInput.nextLine().toLowerCase();
    userInput.close();
 
    for (int i = 0; i < originalString.length(); i++) {
      char currentLetter = originalString.charAt(i);
      if (currentLetter != ' ') {
        currentWord += currentLetter;
      }
      if (currentLetter == ' ' || i == (originalString.length() - 1)) {
        char startingLetter = originalString.charAt(wordStartingIndex);
 
        /*
         * I could not figure out a way to use the contains method with the starting
         * char. I got it to work for the string as a whole, but this did not help me
         * determint if the starting letter was a vowel.
         */
 
        if (startingLetter == 'a' || startingLetter == 'e' || startingLetter == 'i' || startingLetter == 'o'
            || startingLetter == 'u') {
          translatedString += currentWord;
          translatedString += "way";
          if (i != (originalString.length() - 1)) {
            translatedString += " ";
          }
        } else {
          currentWord = currentWord.substring(1);
          translatedString += currentWord;
          translatedString += startingLetter;
          translatedString += "ay";
          if (i != (originalString.length() - 1)) {
            translatedString += " ";
          }
        }
        wordStartingIndex = i + 1;
        currentWord = "";
      }
    }
 
    System.out.println(""); // Output left blank for formatting.
    System.out.println("Here is your translation:");
    System.out.println(translatedString.toUpperCase());
  } // end main
}// end class CarInventoryReport
