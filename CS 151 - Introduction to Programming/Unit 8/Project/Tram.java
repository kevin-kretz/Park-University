/**********************************************
 * Kevin Kretz - 10 May 2020 This is the Tram class for a tram ticket purchasing
 * system. The driver was provided as a part of project instructions.
 **********************************************/
public class Tram {
  private String name;
  private int capacity;

  // Constructor
  public Tram(String name, int capacity) {
    this.name = name;
    this.capacity = capacity;
  }

  // sellChildTicket method
  public void sellChildTicket(int age) {
    double ticketCost = 4.50; // sets ticket cost
    addPerson(age, ticketCost); // passes ticket to helper method
  }

  // sellAdultTicket
  public void sellAdultTicket(int age) {
    double ticketCost = 8.50; // sets ticket cost
    addPerson(age, ticketCost); // passes ticket to helper method
  }

  // addPerson helper method
  public void addPerson(int age, double ticketCost) {

  }

  // displaySeatsAndEarnings method
  public void displaySeatsAndEarnings() {

  }
}