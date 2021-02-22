/**********************************************
 * Kevin Kretz - 10 May 2020 This is the Tram class for a tram ticket purchasing
 * system. The driver was provided as a part of project instructions.
 **********************************************/
public class Tram {
  private String name;
  private int capacity;
  private int purchasedSeats;
  private double ticketEarnings;

  // Constructor
  public Tram(String name, int capacity) {
    this.name = name; // sets tram's name
    this.capacity = capacity; // sets tram's capacity
  }

  // sellChildTicket method
  public Tram sellChildTicket(int age) {
    double ticketCost = 4.50; // sets ticket cost
    System.out.println("A child wants to buy a ticket.");
    this.addPerson(age, ticketCost); // passes ticket to helper method
    return this; // allows method chaining
  }

  // sellAdultTicket
  public Tram sellAdultTicket(int age) {
    double ticketCost = 8.50; // sets ticket cost
    System.out.println("An adult wants to buy a ticket.");
    this.addPerson(age, ticketCost); // passes ticket to helper method
    return this; // allows method chaining
  }

  // addPerson helper method
  public void addPerson(int age, double ticketCost) {
    // if the train is not full
    if (this.purchasedSeats < this.capacity) {
      // if the child is under 3, they don't take up a seat and get to ride for free.
      if (age <= 3) {
        System.out.println("The child is young enough to share a seat, so they ride for free.");
      }
      // if the adult is over 65, they get $2 off their ticket price
      else if (age >= 65) {
        ticketCost -= 2.00; // reduces ticket price
        ticketEarnings += ticketCost; // add ticketCost to ticketEarnings
        purchasedSeats++; // increases purchasedSeats by 1
        System.out.printf("The adult is old enough to receive the senior discount, so they pay only $%,.2f.\n",
            ticketCost);
      }
      // if not younger than 3 or older than 65
      else {
        purchasedSeats++; // increases purchasedSeats by 1
        ticketEarnings += ticketCost; // add ticketCost to ticketEarnings
        System.out.printf("A ticket has been sold for $%,.2f.\n", ticketCost);
      }
    }
    // if the train is full
    else {
      System.out.println("Sorry, the tram is full. Unable to purchase ticket.");
    }
  }

  // displaySeatsAndEarnings method
  public void displaySeatsAndEarnings() {
    System.out.printf("Tram \"%s\" has sold %d seats for a grand total of $%,.2f.\n", this.name, this.purchasedSeats,
        this.ticketEarnings);
  }
}
