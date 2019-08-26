/*******************************
 * Unit 5, Chapter 14 - Programming Assignment
 * By Kevin Kretz | 12 July 2019
 * This class creates a new pizza if the entered type is meat.
 ********************************/

import java.util.Scanner;

public class KKPizza{
  Scanner scnr = new Scanner(System.in);

  // Ensure all instance variables are private
  private String type;
  private double cost;
  private String crust;
  private String ingredient;
  private double ingredientCost;
  
  // Default constructor should set pizzaType to Meat and cost to $5
  public KKPizza() {

    //setType to Meat via the constructor
    this.type = "Meat";
    this.cost = 5.00;
  }

  public void setCrust(String crust){
    this.crust = crust;
  }

  //  setIngredients and allow for only 1 ingredient
  public void setIngredients(String ingredient) {
    this.ingredient = ingredient;
    this.ingredientCost = 2.00;
    this.setCost();
  }

  // setCost add $2 to the initial cost which is $5
  public void setCost() {
    this.cost += ingredientCost;
  }

  // Include accessor methods as needed.
  public String getType() {
    return this.type;
  }

  public String getIngredients() {
    return this.ingredient;
  }

  public Double getIngredientCost() {
    return this.ingredientCost;
  }

  public String getCrust() {
    return this.crust;
  }

  public Double getCost() {
    return this.cost;
  }
}
