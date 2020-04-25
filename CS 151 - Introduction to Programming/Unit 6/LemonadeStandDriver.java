
/********************************************************
* LemonadeStandDriver.java 
* John Dean
*
* This program drives the LemonadeStand class
*********************************************************/

import java.util.Scanner;

public class LemonadeStandDriver {
  public static void main(String[] args)

  {

    Scanner stdIn = new Scanner(System.in); 
    String name;   // lemonade stand owner's name
    int selection; // user's choice of what to do next
  
    LemonadeStand stand = new LemonadeStand();

    System.out.println(
      "Welcome to Lemonade Stand Manager 2.0!\n");

    System.out.print("What is your first name? ");
    name = stdIn.nextLine();
    stand.setStandOwner(name); 

    stand.setLemons(10); 
    stand.setCupsOfSugar(4);

    do
    {
      System.out.println("\nWhat would you like to do?"); 
      System.out.println(
        "1) Make lemonade pitcher, 2) Sell lemonade," +
        " 3) Display information, 4) Quit");
      System.out.print("Enter 1, 2, 3, or 4: ");
      selection = stdIn.nextInt();

      if (selection == 1) 
      {
        stand.makePitcherOfLemonade();
      }
      else if (selection == 2) 
      {
        stand.sellLemonade();
      } 
      else if (selection == 3) 
      { 
        stand.displayStand();
      }
      else if (selection < 1 || selection > 4) 
      {
        System.out.println("Invalid selection, try again."); 
      }
    } while (selection != 4); </p.

    System.out.printf(
      "\nAfter a long day of selling lemonade, " +
      "you made: $%4.2f\n",       stand.getMoneyEarned());
    System.out.println("Good job!"); 
  } // end main
} // end LemonadeStandDriver class