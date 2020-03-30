/*******************************
 * Unit 3, Chapter 12 - Programming Assignment
 * By Kevin Kretz | 29 June 2019
 * This program gets input for a string, then outputs the initial character, ascii values of
 * the character and number, and hex values of each character. Repeats until quit.
 ********************************/

import java.util.*;

public class KKUnit3Chapter12 {
    public static void main(String [] args) {
      Scanner scnr = new Scanner(System.in);

      //Get input for a string containing both numbers and letters of any length
      System.out.print("Please enter a string of any length: ");
      String userString = scnr.nextLine();
      scnr.close();

      //Use a for loop with postfix notation to increment through the string
      for (int i = 0; i < userString.length(); i++) {
        Character currentLetter = userString.charAt(i);
        if (i == 0) { //If first line, print header
          System.out.printf("\n%-8s%-15s%-15s%-5s\n", "Initial", "ASCII(char)", "ASCII(int)", "Hex"); //Print Headers
        }
        //If currentLetter is a digit, print the ascii value of each character, the integer converted to a string, ascii(int) value, and hex value
        if (Character.isDigit(currentLetter)){
          System.out.printf("%-8s%-15s%-15s%-5S\n", currentLetter, "", (int) currentLetter, Integer.toHexString((int) currentLetter));
        }
        //Otherwise, print the ascii value of each character, the integer converted to a string, ascii(char) value, and hex value
        else {
          System.out.printf("%-8s%-15s%-15s%-5S\n", currentLetter, (int) currentLetter, "", Integer.toHexString((int) currentLetter));
        }
      }

      //Output "Thank you for playing!"
      System.out.print("\nThank you for playing!");

    } // end main
} // end class Test
