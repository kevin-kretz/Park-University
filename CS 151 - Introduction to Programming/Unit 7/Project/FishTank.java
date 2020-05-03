public class FishTank {
  private int lengthInInches;
  private int widthInInches;
  private int heightInInches;
  private int numGoldfish;
  private int gallonCapacity;
  private static int totalGoldfish;

  public FishTank(int lengthInInches, int widthInInches, int heightInInches) {
    this.lengthInInches = lengthInInches;
    this.widthInInches = widthInInches;
    this.heightInInches = heightInInches;
    this.gallonCapacity = (this.lengthInInches * this.widthInInches * this.heightInInches) / 231;
    this.numGoldfish = 0;
  }

  public addGoldfish(){
    this.numGoldfish++;
    totalGoldfish++;
  }

  public removeGoldfish() {
    this.numGoldfish--;
    totalGoldfish--;
  }

}
