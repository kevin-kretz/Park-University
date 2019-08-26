/*******************************
 * Unit 6, Chapter 15 - Programming Assignment
 * By Kevin Kretz | 20 July 2019
 * This is a program that validates a sale in dollars and cents with a $ and a .(period).
 ********************************/

import java.util.*;

public class KKUnit6Ch15 {
  public static void main(String[] args){
    Scanner input = new Scanner(System.in);

    System.out.print("Please enter amount of sale in form $#.## (\"q\" to quit): ");
    String user_input = input.nextLine();

    //Driver class should loop until "q" is entered to quit
    while (!user_input.equals("q")) {

      //If enter is not "q", then create an instance of the LiFiSaleCheck object passing the entry as an argument
      KKSaleCheck sale = new KKSaleCheck(user_input);

      //If error
      if (!sale.getError().equals("")){
        //Print error
        System.out.print(sale.getError());
      }

      //If no error
      else {

        //print numeric from LiFiSaleCheck class
        System.out.println(sale.getNumeric());

        //print alphabetic from LiFiSaleCheck class
        System.out.println(sale.getAlphabetic());
      }

      System.out.print("\nPlease enter amount of sale in form $#.## (\"q\" to quit): ");
      user_input = input.nextLine();
    }

    input.close();
  }
}
