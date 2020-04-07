import java.util.Scanner;

public class BMR {
  public static void main(String[] args) {
    Scanner userInput = new Scanner(System.in);
    char gender;
    int weight, height, age, selection;
    int chocolateBar = 210;
    int pepperoniPizzaSlice = 300;
    int babyCarrot = 4;
    double bmr;

    System.out.println("Welcome to the basal metabolic rate calculator.");
    System.out.print("Are you male 'm' or female 'f'? ");
    gender = Character.toUpperCase(userInput.next().charAt(0));

    while (!(gender == 'M' || gender == 'F')) {
      System.out.println("Invalid input. Please enter 'm' for male or 'f' for female.");
      System.out.print("Are you male 'm' or female 'f'? ");
      gender = Character.toUpperCase(userInput.next().charAt(0));
    }

    System.out.print("How much do you weigh (in pounds)? ");
    weight = userInput.nextInt();

    System.out.print("How tall are you (in inches)? ");
    height = userInput.nextInt();

    System.out.print("What is your age? ");
    age = userInput.nextInt();

    if (gender == 'M') {
      bmr = 66 + (6.2 * weight) + (12.7 * height) - (6.76 * age);
    } else {
      bmr = 655.1 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
    }

    System.out.println(""); // intentionally left blank for formatting.
    System.out.println("You entered:");
    System.out.println("Gender: " + gender);
    System.out.println("Weight: " + weight + " lbs");
    System.out.println("Height: " + height + " inches");
    System.out.println("Age: " + age + " years old");
    System.out.println(""); // intentionally left blank for formatting.
    System.out.println("Your basal metabolic rate is: " + bmr);
    System.out.println(""); // intentionally left blank for formatting.
    System.out.println("What food would you like to eat?");
    System.out.println("1) chocolate bar (210 calories)");
    System.out.println("2) pepperoni pizza slice (300 calories)");
    System.out.println("3) baby carrot (4 calories)");
    System.out.print("Selection: ");

    selection = userInput.nextInt();
    System.out.println(""); // intentionally left blank for formatting.

    while (!(selection == 1 || selection == 2 || selection == 3)) {
      System.out.println("Sorry, that's not a valid selection. Try again.");
      System.out.print("Selection: ");
      selection = userInput.nextInt();
      System.out.println(""); // intentionally left blank for formatting.
    }

    userInput.close();

    if (selection == 1) {
      System.out.println(
          "With your BMR, you can eat " + (bmr / chocolateBar) + " chocolate bars to maintain your body weight.");
    } else if (selection == 2) {
      System.out.println("With your BMR, you can eat " + (bmr / pepperoniPizzaSlice)
          + " pepperoni pizza slices to maintain your body weight.");
    } else {
      System.out
          .println("With your BMR, you can eat " + (bmr / babyCarrot) + " baby carrots to maintain your body weight.");
    }

    System.out.println("Thank you for using the basal metabolic rate calculator.");
  }
}