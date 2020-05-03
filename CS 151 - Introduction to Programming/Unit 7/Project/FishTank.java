public class FishTank {
  private double lengthInInches;
  private double widthInInches;
  private double heightInInches;
  private int numGoldfish;
  private double gallonCapacity;
  private static int totalGoldfish;
 
  public FishTank(double lengthInInches, double widthInInches, double heightInInches) {
    this.lengthInInches = lengthInInches;
    this.widthInInches = widthInInches;
    this.heightInInches = heightInInches;
    this.gallonCapacity = (this.lengthInInches * this.widthInInches * this.heightInInches) / 231;
    this.numGoldfish = 0;
  }
 
  public void addGoldfish() {
    this.numGoldfish++;
    totalGoldfish++;
  }
 
  public void removeGoldfish() {
    this.numGoldfish--;
    totalGoldfish--;
  }
 
  public void transferGoldfish(FishTank newFishTank) {
    newFishTank.numGoldfish += this.numGoldfish;
    this.numGoldfish = 0;
  }
 
  // created for use in displayTankInformation()
  public boolean isBigEnough() {
    double gallonsNeeded;
 
    if (numGoldfish > 1) {
      gallonsNeeded = ((numGoldfish - 1) * 12) + 30;
    }
    else if (numGoldfish == 1) {
      gallonsNeeded = 30;
    }
    else {
      gallonsNeeded = 0;
    }
 
    if (gallonCapacity >= gallonsNeeded) {
      return true;
    }
    else {
      return false;
    }
  }
 
  public void displayTankInformation() {
    System.out.printf("This tank is %,.1f inches long, %,.1f inches wide, and %,.1f inches tall.\n", lengthInInches,
        widthInInches, heightInInches);
    System.out.printf("It can hold up to %,.1f gallons of water.\n", gallonCapacity);
    System.out.println("Currently, it holds " + this.numGoldfish + " goldfish.");
    if (this.isBigEnough()) {
      System.out.println("This tank is sufficiently large for its current number of goldfish.");
    }
    else {
      System.out.println("This tank is too small for its current number of goldfish.");
    }
  }
 
  public static void displayTotalFish() {
    System.out.println("There are " + totalGoldfish + " total goldfish in all the tanks combined.");
  }
}
