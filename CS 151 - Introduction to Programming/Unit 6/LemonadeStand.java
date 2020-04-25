public class LemonadeStand {
  private double servingPrice = 0.50;
  private int lemonsPerPitcher = 5;
  private int cupsOfSugarPerPitcher = 1;
  private int servingsPerPitcher = 3;
  private String standOwner;
  private int numOfLemons;
  private int cupsOfSugar;
  private double totalMoneyEarned;
  private int servings;

  public void setStandOwner(String name) {
    this.standOwner = name;
  }

  public void setLemons(int numOfLemons) {
    this.numOfLemons = numOfLemons;
  }

  public void setCupsOfSugar(int cupsOfSugar) {
    this.cupsOfSugar = cupsOfSugar;
  }

  public double getMoneyEarned() {
    return this.totalMoneyEarned;
  }

  public void makePitcherOfLemonade() {
    if (this.numOfLemons >= lemonsPerPitcher && this.cupsOfSugar >= cupsOfSugarPerPitcher) {
      this.numOfLemons -= lemonsPerPitcher;
      this.cupsOfSugar -= cupsOfSugarPerPitcher;
      this.servings += servingsPerPitcher;
      System.out.println("A new pitcher of lemonade has been made.");
    } else {
      System.out.println("Sorry – unable to make a new pitcher of lemonade.");
    }
  }

  public void sellLemonade() {
    if (this.servings >= 1) {
      this.servings--;
      this.totalMoneyEarned += servingPrice;
      System.out.println("A lemonade has been sold.");
    } else {
      System.out.println("Sorry – there is no lemonade currently available.");
    }
  }

  public void displayStand() {
    System.out.printf("%18s\n", " |===============|");
    System.out.printf(" |  %-13s|\n", this.standOwner + "'s");
    System.out.printf("%7s%11s\n", " |     ", "Lemonade  |");
    System.out.printf("%18s\n", " |===============|");
    System.out.printf("%18s\n", " |     /_\\_      |");
    System.out.printf("%18s\n", " |    (^_^)      |");
    System.out.printf("%18s\n", " |_____/|\\_[]>___|");
    System.out.printf("%6s%4.2f%8s\n", " |   $", servingPrice, "/cup   |");
    System.out.printf("%18s\n", " |_______________|");

    // Display remaining inventory
    System.out.println("\nYou have " + this.servings + " serving(s) of lemonade remaining.");
    System.out.println("You have " + this.numOfLemons + " lemon(s) remaining.");
    System.out.println("You have " + this.cupsOfSugar + " cup(s) of sugar remaining.");
  }
}