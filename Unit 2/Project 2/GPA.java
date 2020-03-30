
/****************************************************
* GPA.java
* Kevin Kretz
*
* This program calculates the grade point average (GPA)
* of students using grade and number of credit hours.
****************************************************/

import java.util.Scanner;

public class GPA {
  public static void main(String[] args) {
    // initialize variable
    float sumOfGrades = 0;
    float totalCreditHours = 0;
    float GPA;
    int numberOfClasses;
    Scanner userInput = new Scanner(System.in);

    // Get number of classes
    System.out.print("How many courses did you take this past semester? ");
    numberOfClasses = userInput.nextInt();

    // If there were no classes taken, tell the user a GPA can't be calculated.
    if (numberOfClasses == 0) {
      System.out.println("Sorry, your GPA cannot be calculated.");
    }

    else {
      // for each class taken
      while (numberOfClasses > 0) {
        int grade;
        int creditHours;

        // Get the user's grade
        System.out.print("Enter the grade for a course (A=4, B=3, C=2, D=1, F=0): ");
        grade = userInput.nextInt();

        // Get the number of credit hours for the class
        System.out.print("Enter the credit hours for that course: ");
        creditHours = userInput.nextInt();

        // Add (grade * credit hours) to the current sum of the grades
        sumOfGrades += (grade * creditHours);
        totalCreditHours += creditHours;
        numberOfClasses--;
      }

      // Calculate the GPA
      GPA = sumOfGrades / totalCreditHours;

      // Print the users GPA
      System.out.println("Your GPA for this semester is " + GPA);
    }

    // close the user input
    userInput.close();
  } // end main
} // end class
