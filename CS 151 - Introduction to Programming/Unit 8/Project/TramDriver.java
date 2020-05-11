/**********************************************
 * Kevin Kretz - 10 May 2020 This is the driver class for a tram ticket
 * purchasing system. The driver was provided as a part of project instructions.
 **********************************************/
public class TramDriver {
  public static void main(String[] args) {
    Tram tram1 = new Tram("Orient Express", 30);
    Tram tram2 = new Tram("African Safari", 5);

    // Sell some tickets for tram #1
    System.out.println("Tram #1");
    tram1.sellAdultTicket(49).sellAdultTicket(30).sellAdultTicket(65);
    tram1.sellChildTicket(12).sellChildTicket(3);
    System.out.println();
    tram1.displaySeatsAndEarnings();

    // Sell some tickets for tram #2
    System.out.println("\nTram #2");
    for (int i = 0; i < 7; i++) {
      tram2.sellAdultTicket(30);
    }
    System.out.println();
    tram2.displaySeatsAndEarnings();
  } // end main
} // end class