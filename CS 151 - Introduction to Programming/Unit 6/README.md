# Project
Implement a program that manages the operations of a lemonade stand. Specifically, implement a ```LemonadeStand``` class that works in conjunction with the LemonadeStandDriver class shown below.

Your ```LemonadeStand``` class must include:

- Named constants:
    - price of one lemonade serving = .50;
    - number of lemons per pitcher = 5;
    - number of cups of sugar per pitcher = 1;
    - number of servings per pitcher = 3;
    
- Instance variables
    - ```standOwner```, the name of the lemonade stand’s owner
    - ```numOfLemons```, the number of lemons remaining in your inventory
    - ```numOfCupsSugar```, the number of remaining cups of sugar in your inventory
    - ```numOfServings```, the current number of servings left in your pitcher
    - ```moneyEarned```, to hold the total amount of money earned from selling lemonade
- Mutator methods – set the stand owner, set the number of lemons, and set the cups of sugar.
- Accessor method – get the money earned so far.
- Additional methods:
    - ```makePitcherOfLemonade```, which should check to see if there are sufficient ingredients (lemons and sugar) to make a new pitcher of lemonade. If there are sufficient ingredients, print “A new pitcher of lemonade has been made." If there are not enough ingredients, print “Sorry – unable to make a new pitcher of lemonade.” You may assume that there are plenty of empty pitcher containers to handle any requests for new pitchers of lemonade. If you make a new pitcher of lemonade, adjust your instance variables accordingly. In particular, adjust the number of lemons in your inventory and the number of cups of sugar. Also, adjust the number of lemonade servings on hand.
    - ```sellLemonade```, which should handle the purchase of one lemonade serving. If the stand has at least one serving, print “A lemonade has been sold.” and adjust your instance variables accordingly. In particular, decrement the number of servings and add to the total money earned. If the stand does not have any servings of lemonade, print “Sorry – there is no lemonade currently available.”
    - ```displayStand```, which displays information about the lemonade stand, including the owner’s name, remaining number of lemons, remaining number of cups of sugar, and number of servings on hand. In displaying the stand’s information, your program should use ASCII art. That can be a bit tricky, so a skeleton for the displayStand method has been provided. Use it!

## DisplayStand:
```
public void displayStand()
{
  System.out.printf("%18s\n", " |===============|");
  System.out.printf(
    " |  %-13s|\n",
    this.standOwner + "'s");
  System.out.printf("%7s%11s\n", " |     ", "Lemonade  |");
  System.out.printf("%18s\n", " |===============|");
  System.out.printf("%18s\n", " |     /_\\_      |");
  System.out.printf("%18s\n", " |    (^_^)      |");
  System.out.printf("%18s\n", " |_____/|\\_[]>___|"); 
  System.out.printf("%6s%4.2f%8s\n", " |   $", SERVING_PRICE, 
    "/cup   |");
  System.out.printf("%18s\n", " |_______________|");

  // Display remaining inventory
  System.out.println(
    "\nYou have " + this.servings +
    " serving(s) of lemonade remaining.");

  <Insert code here for displaying information on remaining lemons and sugar.>

} // end displayStand
```

Use the following ```LemonadeStandDriver``` class. Because I have provided the entire thing, you do not have to include your driver class in your submitted Word document.
## LemonadeStandDriver:
```
/********************************************************
* LemonadeStandDriver.java 
* John Dean
*
* This program drives the LemonadeStand class
*********************************************************/

import java.util.Scanner;

public class LemonadeStandDriver
{
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
```
## Sample session:
```
Welcome to Lemonade Stand Manager 2.0!

What is your first name? Shasondra

What would you like to do? 
1) Make lemonade pitcher, 2) Sell lemonade, 3) Display information, 4) Quit
Enter 1, 2, 3, or 4: 1
A new pitcher of lemonade has been made. 

What would you like to do? 
1) Make lemonade pitcher, 2) Sell lemonade, 3) Display information, 4) Quit
Enter 1, 2, 3, or 4: 5
Invalid selection, try again.

What would you like to do? 
1) Make lemonade pitcher, 2) Sell lemonade, 3) Display information, 4) Quit
Enter 1, 2, 3, or 4: 3
 |===============| 
 |  Shasondra's  |
 |     Lemonade  |
 |===============| 
 |     /_\_      |
 |    (^_^)      |
 |_____/|\_[]>___| 
 |   $0.50/cup   |
 |_______________|

You have 3 serving(s) of lemonade remaining. 
You have 5 lemon(s) remaining. 
You have 3 cup(s) of sugar remaining. 

What would you like to do? 
1) Make lemonade pitcher, 2) Sell lemonade, 3) Display information, 4) Quit
Enter 1, 2, 3, or 4: 2
A lemonade has been sold.

What would you like to do? 
1) Make lemonade pitcher, 2) Sell lemonade, 3) Display information, 4) Quit
Enter 1, 2, 3, or 4: 2
A lemonade has been sold.

What would you like to do? 
1) Make lemonade pitcher, 2) Sell lemonade, 3) Display information, 4) Quit
Enter 1, 2, 3, or 4: 2
A lemonade has been sold.

What would you like to do? 
1) Make lemonade pitcher, 2) Sell lemonade, 3) Display information, 4) Quit
Enter 1, 2, 3, or 4: 2
Sorry - there is no lemonade currently available. 

What would you like to do? 
1) Make lemonade pitcher, 2) Sell lemonade, 3) Display information, 4) Quit
Enter 1, 2, 3, or 4: 1
A new pitcher of lemonade has been made. 

What would you like to do? 
1) Make lemonade pitcher, 2) Sell lemonade, 3) Display information, 4) Quit
Enter 1, 2, 3, or 4: 2
A lemonade has been sold.

What would you like to do? 
1) Make lemonade pitcher, 2) Sell lemonade, 3) Display information, 4) Quit
Enter 1, 2, 3, or 4: 3
 |===============| 
 |  Shasondra's  |
 |     Lemonade  |
 |===============| 
 |     /_\_      | 
 |    (^_^)      |
 |_____/|\_[]>___| 
 |   $0.50/cup   |
 |_______________| 
  
You have 2 serving(s) of lemonade remaining. 
You have 0 lemon(s) remaining. 
You have 2 cup(s) of sugar remaining. 

What would you like to do? 
1) Make lemonade pitcher, 2) Sell lemonade, 3) Display information, 4) Quit
Enter 1, 2, 3, or 4: 4

After a long day of selling lemonade, you made: $2.00
Good job! 
```
