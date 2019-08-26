
/*******************************
 * Unit 5, Chapter 14 - Programming Assignment
 * By Kevin Kretz | 12 July 2019
 * This class creates a new pizza if the entered type is cheese.
 ********************************/

public class KKCheese{
  private String type;
  private String crust;
  private double cost;

  public KKCheese() {

    // Set the type to cheese via the constructor body.
    this.type = "Cheese";
    this.cost = 5.00;

    setCrust();
  }

  // Automatically set it to "Thin" crust, no option to change, sorry.
  public void setCrust(){
    this.crust = "Thin";
  }

  public String getType(){
    return this.type;
  }

  public String getCrust(){
    return this.crust;
  }

  public double getCost(){
    return this.cost;
  }
}
