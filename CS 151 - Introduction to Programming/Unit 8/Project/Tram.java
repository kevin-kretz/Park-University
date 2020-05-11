/**********************************************
 * Kevin Kretz - 10 May 2020 This is the Tram class for a tram ticket purchasing
 * system. The driver was provided as a part of project instructions.
 **********************************************/
public class Tram {
  private String name;
  private int capacity;
  private int purchasedSeats;
  private int ticketEarnings;

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
    if (this.purchasedSeats < this.capacity) {
      if (age <= 3) {
        System.out.println("The child is young enough to share a seat, so they ride for free.");
      } else if (age >= 65) {
        ticketCost -= 2.00;
        purchasedSeats++;
        System.out.printf("The adult is old enough to receive the senior discount, so they pay only $%,.2f",
            ticketCost);
      } else {
        purchasedSeats++;
        System.out.printf("A ticket has been sold for $%,.2f", ticketCost);
      }
    } else {
      System.out.println("Sorry, the tram is full. Unable to purchase ticket.");
    }
  }

  // displaySeatsAndEarnings method
  public void displaySeatsAndEarnings() {
    System.out.printf("Tram \"%s\" has sold %d seats for a grand total of $%,.2f.", this.name, this.purchasedSeats,
        this.ticketEarnings);
  }
}