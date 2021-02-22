# Project
Trams come in many sizes and are frequently used to move people from point A to point B quickly. Oftentimes you will see them at large tourist venues such as zoos and amusement parks. For this project you will write a program that simulates ticket purchases for tram objects. You must implement a Tram class that includes:
- Five static constants. Study the method descriptions below, and you’ll see five values that should be implemented as static constants.
- Instance constants  
    - ```name```, which stores the tram’s name
    - ```capacity```, which stores the tram’s number of seats
- Instance variables
    – ```purchasedSeats```, which stores how many seats on the tram have been purchased
    - ```ticketEarnings```, which stores earnings from the tram’s ticket sales
- Constructor – A 2-parameter constructor, which receives the tram’s name and capacity.
- Methods:
    - ```sellChildTicket```, which should pass the age and child ticket cost to a helper method. The child ticket cost is $4.50. This method should enable method-call chaining.
    - ```sellAdultTicket```, which should pass the age and adult ticket cost to a helper method. The adult ticket cost is $8.50. This method should enable method-call chaining.
addPerson, a helper method that accepts the age of the person and the anticipated ticket cost. Check to see if the tram is full, and if it is, print an appropriate message. Check to see if the person is 3 or younger, in which case the child shares a seat and rides for free. Check to see if the person is 65 or older, in which case the adult earns a senior discount of $2 (their ticket is $2 less than a normal adult ticket).
    - ```displaySeatsAndEarnings```, a method that displays the seats purchased and ticket earnings for the Tram calling object.
    
In your submitted Word document, you must provide all the code in your program. That means you must include your Tram class and also a TramDriver class. Your TramDriver class should be easy because its main method is provided below. You just have to add a prologue, a class heading, and indent the main method.

## Tram main method
```
public static void main(String[] args)
{
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
  for (int i=0; i<7; i++)
  {
    tram2.sellAdultTicket(30);
  }
  System.out.println();
  tram2.displaySeatsAndEarnings();
} // end main
```

## Output:
```
Tram #1
An adult wants to buy a ticket.
A ticket has been sold for $8.50.
An adult wants to buy a ticket.
A ticket has been sold for $8.50.
An adult wants to buy a ticket.
The adult is old enough to receive the senior discount, so they pay only $6.50.
A child wants to buy a ticket.
A ticket has been sold for $4.50.
A child wants to buy a ticket.
The child is young enough to share a seat, so they ride for free.

Tram "Orient Express" has sold 4 seats for a grand total of $28.00.

Tram #2
An adult wants to buy a ticket.
A ticket has been sold for $8.50.
An adult wants to buy a ticket.
A ticket has been sold for $8.50.
An adult wants to buy a ticket.
A ticket has been sold for $8.50.
An adult wants to buy a ticket.
A ticket has been sold for $8.50.
An adult wants to buy a ticket.
A ticket has been sold for $8.50.
An adult wants to buy a ticket.
Sorry, the tram is full. Unable to purchase ticket.
An adult wants to buy a ticket.
Sorry, the tram is full. Unable to purchase ticket.

Tram "African Safari" has sold 5 seats for a grand total of $42.50.
```
