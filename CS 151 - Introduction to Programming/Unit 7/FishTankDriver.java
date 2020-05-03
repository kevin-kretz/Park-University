// Kevin Kretz | 3 May 2020
// FishTankDriver.java was provided by course materials

public class FishTankDriver {
  public static void main(String[] args) {
    FishTank ft1, ft2; // fish tanks for testing purposes

    ft1 = new FishTank(36, 18, 12);
    ft2 = new FishTank(48.5, 12.75, 25);

    ft1.addGoldfish();
    ft1.addGoldfish();
    ft1.addGoldfish();
    System.out.println("Tank #1:");
    ft1.displayTankInformation();

    System.out.println("\nTank #2:");
    ft2.addGoldfish();
    ft2.addGoldfish();
    ft2.displayTankInformation();

    ft1.transferGoldfish(ft2);
    System.out.println("\nTank #1's goldfish have been transferred to Tank #2.");

    System.out.println("\nTank #1:");
    ft1.displayTankInformation();
    System.out.println("\nTank #2:");
    ft2.displayTankInformation();

    System.out.println("\nRemoving a goldfish from Tank #2...");
    ft2.removeGoldfish();
    System.out.println("\nTank #2:");
    ft2.displayTankInformation();
    System.out.println();

    ft1.addGoldfish();
    FishTank.displayTotalFish();
  } // end main
}