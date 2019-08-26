#Final Submition
import java.util.Random;
import java.util.Arrays;
import java.util.Scanner;

class Test {
    public static void main(String[] args) {
        Random rand = new Random();
        Scanner scnr = new Scanner(System.in);

        //Declare an array of size 10
        int[] unsortedArray = new int[10];

        //Fill each element in this array with random numbers from 1 to 20.
        for (int i = 1; i < 10; i++) {
            int randomNumber = rand.nextInt(20) + 1;
            unsortedArray[i] = randomNumber;
        }

        //Make a copy of this array.
        int[] sortedArray = new int[10];

        for (int i = 0; i < sortedArray.length; i++) {
            sortedArray[i] = unsortedArray[i]; 
        }

        //Using the java API, sort the copy.
        Arrays.sort(sortedArray);

        //Print a table showing both the unsorted and sorted arrays.
        System.out.printf("%s%18s\n", "Unsorted Array", "Sorted Array");

        for (int i = 0; i < sortedArray.length; i++) {
            System.out.printf("%-20d%d\n", unsortedArray[i], sortedArray[i]);
        }

        //Enter a number to search for
        System.out.print("\nPlease enter a number to search for: ");
        int searchValue = scnr.nextInt();

        //Output the search value and location found
        System.out.println("");
        int index = 1;
        boolean searchValueFound = false;

        for (int number : unsortedArray) {
            if (number == searchValue) {
                System.out.printf("Search Value: %d found at location: %d in the unsorted array\n", searchValue, index);
                searchValueFound = true;
            }
            index++;
        }
        
        if (searchValueFound) {
            index = 1;

            for (int number : sortedArray) {
                if (number == searchValue) {
                    System.out.printf("Search Value: %d found at location: %d in the sorted array\n", searchValue, index);
                }
                index++;
            }
        }

        else {
            System.out.printf("Search Value: %d was not found", searchValue);
        }
    }
}
