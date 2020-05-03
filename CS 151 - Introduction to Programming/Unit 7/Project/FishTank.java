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

  public void addGoldfish(){
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
