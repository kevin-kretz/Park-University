
/****************************************************
* Warehouse.java
* Kevin Kretz
*
* This program stores items on a self using the rack-
* shelf-description method.
****************************************************/

import java.util.Scanner;

public class Warehouse {
  public static void main(String[] args) {
    // initialize variable
    char rack;
    int shelf;
    String description;
    Scanner userInput = new Scanner(System.in);

    // Get the rack of the item
    System.out.println("What rack is the item stored on? ");
    rack = userInput.nextLine().charAt(0);

    // Get the shelf of the item
    System.out.println("What shelf is the item stored on? ");
    shelf = userInput.nextInt();

    // Get the description of the item
    System.out.println("What is the description of the item? ");
    description = userInput.nextLine();

    // close the user input
    userInput.close();
  } // end main
} // end class
