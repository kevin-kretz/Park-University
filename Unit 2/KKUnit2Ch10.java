/*******************************
 * Unit 1, Chapter 9 - Programming Assignment
 * By Kevin Kretz | 15 June 2019
 * This program generates random numbers between 1 and 100, then allows you to search for matching values.
 * The output is printed for in a sorted and unsorted list.
 ********************************/

import java.util.*;

public class KKUnit2Ch10 {
    public static void main(String [] args) {
        Scanner scnr = new Scanner(System.in);
        Random rand = new Random();
    
        //Declare an array list to hold random numbers.
        ArrayList<Integer> randomNumbers = new ArrayList<>();

        //Get input for how many random numbers to use.
        System.out.print("How many random numbers between 1 and 100: ");
        int numberOfRandomNumbers = scnr.nextInt();

        //Using a "for loop", add random numbers to the array list between 1 and 100.
        for (int i = 0; i < numberOfRandomNumbers; i++){
            int randomNumber = rand.nextInt(50) + 1;
            randomNumbers.add(randomNumber);
        }

        //Get input for value to be searched.
        System.out.print("Which random number are you searching for?: ");
        int searchValue = scnr.nextInt();
        scnr.close();

        //Using a "for-each loop" and a sequential search, search through the array list for the search term entered.
        boolean searchValueFound = false;
        int index = 0;

        for (int number : randomNumbers) {
            if (number == searchValue && searchValueFound == false) { //Only print the headers and values if the search item is found.
                System.out.println("\nUnsorted List"); //Output "Unsorted List"
                System.out.println(searchValue + " found at location: " + index); //For first match found, output # found at location: #
                searchValueFound = true;
            }
            else if (number == searchValue){
                System.out.println(searchValue + " found at location: " + index); //For each additional match found, output # found at location: #
            }
            index++;
        }

        //Use java collections to sort the array list.
        Collections.sort(randomNumbers);

        //Using a "for-each loop" and a sequential search, search through the array list for the search term entered.
        searchValueFound = false;
        index = 0;

        for (int number : randomNumbers) {
            if (number == searchValue && searchValueFound == false) { //Only print the headers and values if the search item is found.
                System.out.println("\nSorted List"); //Output "Unsorted List"
                System.out.println(searchValue + " found at location: " + index); //For first match found, output # found at location: #
                searchValueFound = true;
            }
            else if (number == searchValue){
                System.out.println(searchValue + " found at location: " + index); //For each additional match found, output # found at location: #
            }
            index++;
        }

        //Print the total value of all random numbers added together after the search has complete.
        int sum = 0;

        for (int number : randomNumbers) {
            sum += number;
        }

        System.out.print("\nTotal of all numbers: " + sum);
    }
}
