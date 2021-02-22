# Project - Fish Tank
Did you know that common goldfish can grow up to 10 inches long? This can only be achieved if the goldfish has a large enough tank. Typical fishbowls are poor environments for most fish, as they lack swimming room, accommodation for a filter, and proper temperature regulation among other things. For a single common goldfish, it is recommended for it to be stored in a tank with a capacity of no less than 30 gallons of water. For every additional common goldfish in the tank, you should use a tank with 12 more gallons of storage capacity. For example, a tank with four common goldfish should have a 66 gallon storage capacity. That’s 30 + 12 + 12 + 12 = 66.

If you have the dimensions of the tank, you can compute its gallon capacity using this equation:
*gallon-capacity = (length-in-inches * width-in-inches * height-in-inches) / 231*

Multiplying the length, width, and height together gives us the cubic volume. When you divide the volume by 231, which is the number of cubic inches in a gallon, that gives you the tank’s gallon capacity.

Implement a program that tracks goldfish stored in fish tanks. You must implement a ```FishTank``` class that includes:

- Three static constants (study the description above, and you’ll see three values that should be implemented as static constants).
- Instance variables – ```gallonCapacity``` which stores the tank’s water capacity in gallons, ```lengthInInches```, which stores the tank’s length, ```widthInInches```, which stores the tank’s width, ```heightInInches```, which stores the tank’s height, and ```numGoldfish```, which holds the tank’s current number of goldfish.
- A static variable – ```totalGoldfish```, which stores the total number of goldfish in all of the tanks combined.
- Implement a 3-parameter constructor where the tank’s length, width, and height are passed in. The number of goldfish should be set to zero.
- Methods:
    - ```addGoldfish```, which should increase the number of goldfish in the tank and goldfish across all tanks by one.
    - ```removeGoldfish```, which should decrease the number of goldfish in the tank and goldfish across all tanks by one.
    - ```transferGoldfish```, which should accept a ```FishTank``` as an argument, remove all of the fish from the calling object, and add them to the passed-in ```FishTank```
    - ```displayTankInformation```, which should print the tank’s dimensions, gallon capacity, the number of goldfish it currently holds, and whether or not the tank’s capacity is sufficient for the tank’s current number of goldfish. For the tank’s dimensions and capacity, print the values rounded to the nearest tenths place (see the output).
    - ```displayTotalFish```, a static method which should print the total number of goldfish in all tanks combined.

In your submitted Word document, you must provide all the code in your program. That means you must include your ```FishTank``` class and also a ```FishTankDriver``` class. Your ```FishTankDriver``` class should be easy because its ```main``` method is provided below. You just have to add a prologue, a class heading, and indent the main method.
```
public static void main(String[] args)
{
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
  System.out.println(
    "\nTank #1's goldfish have been transferred to Tank #2.");

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
```

## Output:
```
Tank #1:
This tank is 36.0 inches long, 18.0 inches wide, and 12.0 inches tall.
It can hold up to 33.7 gallons of water.
Currently, it holds 3 goldfish.
This tank is too small for its current number of goldfish.

Tank #2:
This tank is 48.5 inches long, 12.8 inches wide, and 25.0 inches tall.
It can hold up to 66.9 gallons of water.
Currently, it holds 2 goldfish.
This tank is sufficiently large for its current number of goldfish.

Tank #1's goldfish have been transferred to Tank #2.

Tank #1:
This tank is 36.0 inches long, 18.0 inches wide, and 12.0 inches tall.
It can hold up to 33.7 gallons of water.
Currently, it holds 0 goldfish.
This tank is sufficiently large for its current number of goldfish.

Tank #2:
This tank is 48.5 inches long, 12.8 inches wide, and 25.0 inches tall.
It can hold up to 66.9 gallons of water.
Currently, it holds 5 goldfish.
This tank is too small for its current number of goldfish.

Removing a goldfish from Tank #2...

Tank #2:
This tank is 48.5 inches long, 12.8 inches wide, and 25.0 inches tall.
It can hold up to 66.9 gallons of water.
Currently, it holds 4 goldfish.
This tank is sufficiently large for its current number of goldfish.

There are 5 total goldfish in all the tanks combined.
```
