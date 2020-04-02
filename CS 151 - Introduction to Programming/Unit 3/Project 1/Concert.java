import java.util.Scanner;

public class Concert {
  public static void main(String[] args) {
    Scanner userInput = new Scanner(System.in);
    System.out.println("Are you a 1) regular fan, 2) VIP fan, 3) roadie, or 4) venue employee?");
    System.out.print("Enter 1, 2, 3, or 4: ");
    int role = userInput.nextInt();

    switch (role) {
      case (1):
        System.out.print("Do you have a ticket? (y/n): ");
        char ticket = userInput.next().charAt(0);
        if (ticket == 'Y' || ticket == 'y') {
          System.out.println("Proceed to the standard seating area.");
        } else {
          System.out.println("Sorry, you need to leave.");
        }
        break;
      case (2):
        System.out.print("Do you have a ticket? (y/n): ");
        ticket = userInput.next().charAt(0);
        System.out.print("Do you have a backstage pass? (y/n): ");
        char backstagePass = userInput.next().charAt(0);
        if ((ticket == 'Y' || ticket == 'y') && (backstagePass == 'Y' || backstagePass == 'y')) {
          System.out.println("Proceed to the VIP seating area.");
        } else {
          System.out.println("Sorry, you need to leave.");
        }
        break;
      case (3):
        System.out.print("Do you have a backstage pass? (y/n): ");
        backstagePass = userInput.next().charAt(0);
        if (backstagePass == 'Y' || backstagePass == 'y') {
          System.out.println("Find the band and do what they need.");
        } else {
          System.out.println("Sorry, you need to leave.");
        }
        break;
      case (4):
        System.out.print("Do you have an employee ID? (y/n): ");
        char employeeID = userInput.next().charAt(0);
        if (employeeID == 'Y' || employeeID == 'y') {
          System.out.println("Go to your work area.");
        } else {
          System.out.println("Sorry, you need to leave.");
        }
        break;
      default:
        System.out.println("Sorry, invalid input. You need to leave.");
        break;
    }
    userInput.close();
  }
}