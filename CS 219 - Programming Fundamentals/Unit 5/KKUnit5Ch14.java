/*******************************
 * Unit 5, Chapter 14 - Programming Assignment
 * By Kevin Kretz | 12 July 2019
 * This program is a super basic pizza ordering system using polymorphism.
 * The setCrust method varies based on which type of Pizza is instantiated.
 ********************************/

import java.util.Scanner;

public class KKUnit5Ch14 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    //Get input for Cheese or Meat pizza.
    System.out.print("What type of pizza would you like (cheese or meat): ");

    // Declare a single pizza to be used for both Cheese and Meat
    String pizzaType = input.nextLine().toLowerCase();

    // If a Cheese pizza is selected
    if (pizzaType.equals("cheese")){

      //Instantiate your pizza as a LiFiCheese pizza with zero arguments.
      KKCheese pizza = new KKCheese();

      // Output of your order varies based on Cheese or Meat
      System.out.println("Your order:");
      System.out.printf("%s pizza", pizza.getType());
      System.out.printf("\n%s crust", pizza.getCrust());
      System.out.printf("\nTotal cost of $%.2f", pizza.getCost());
    }

    // If a Meat pizza is selected
    else if (pizzaType.equals("meat")){

      // instantiate your pizza as a LiFiPizza pizza with zero arguments
      KKPizza pizza = new KKPizza();

      System.out.print("Thin or thick crust: ");
      pizza.setCrust(input.nextLine());
      System.out.print("What ingredient, sorry, only 1: ");
      pizza.setIngredients(input.nextLine());

      // Output of your order varies based on Cheese or Meat
      System.out.println("Your order:");
      System.out.printf("%s pizza", pizza.getType());
      System.out.printf("\n%s (+$%.2f)", pizza.getIngredients(), pizza.getIngredientCost());
      System.out.printf("\n%s crust", pizza.getCrust());
      System.out.printf("\nTotal cost of $%.2f", pizza.getCost());
    }

    input.close();
  }
}
