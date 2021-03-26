// This program converts the time from 24-hour notation to 12-hour notation and vice versa continuously until user chooses to stop the program.
// Unit 2 - Homework 3
// Kevin Kretz | 23 March 2021

#include <iostream> // Included for input and output streams
#include <string>  // Included for string conversion

// This function displays the menu for the user to choose the type of conversion and returns the user's input
// Pre: menuChoice - Delcared (Empty)
// Post: menuChoice
// In: n/a
// Out: menuChoice (type:int users choice of which menu option to execute)
// In-Out: n/a
int displayMenu() {
    int menuChoice;  // Declare variable
    
    // Print menu
    std::cout << "Options --" << std::endl;
    std::cout << "1: To convert time from 12-hour notation to 24-hour notation." << std::endl;
    std::cout << "2: To convert time from 24-hour notation to 12-hour notation." << std::endl;
    std::cout << "0: To quit the program." << std::endl;
    std::cout << "Choose: ";
    
    
    std::cin >> menuChoice;  // Store user input into variable
    std::cout << "\n";  // Print new line to match example
    return menuChoice;  // Return the user input
}

// This function gets and returns the time the user wishes to convert to the other notation
// Pre: menuChoice
// Post: menuChoice, hours, minutes
// In: unit (type:string unit of measurement for time being entered. e.g. hours, minutes)
// Out: time (type:int minutes or hours, depending on input unit)
// In-Out: n/a
int getTime(std::string unit) {
    int time;  // Declare variable
    std::cout << "Enter " << unit << ": ";  // Print prompt to enter time; Unit of measurement changes
    std::cin >> time;  // Stores user input in variable
    return time;  // Returns variable
}

// This function, based on the information provided, returns whether it is AM
// Pre: menuChoice, hours, minutes
// Post: menuChoice, hours, minutes, isAM
// In: menuChoice (type:int to determine if AM/PM will be provided), hours (type:int to calculate AM/PM if not provided)
// Out: isAM (type:bool signifing whether or not time is AM)
// In-Out: n/a
bool getIsAM(int menuChoice, int hours){
    bool isAM;  // Declares variable
    
    if (menuChoice == 1) {   // If user will provide AM/PM
        char userInput;  // Declare variable
        std::cout << "Enter AM/PM (A or P): ";  // Prompt for AM/PM
        std::cin >> userInput;  // Store user input in variable
        
        if (toupper(userInput) == 'A') {  // Convert user input to upper case; if "A"
            isAM = true;
        }
        else {
            isAM = false;
        }
    }
    else {  // If user will not provide AM/PM
        if (hours <= 12) {
            isAM = true;
        }
        else {
            isAM = false;
        }
    }
    return isAM;  // Return boolean value for isAM
}

// This function, takes a time and returns it converted to the other notation
// Pre: menuChoice, hours, minutes, isAM
// Post: menuChoice, hours, minutes, isAM, convertedTime
// In: menuChoice (type:int to determine if isAM will be provided), hours (type:int), minutes (type:int), isAM(type:bool)
// Out: convertedString (type:string time converted to new notation)
// In-Out: n/a
std::string convertTime(int menuChoice, int hours, int minutes, bool isAM) {
    std::string convertedTime;  // declare variable

    if (menuChoice == 1) {  // If user provided AM/PM
        if (!isAM ) {  // If PM
            hours += 12;  // add 12 hours to hours
        }
        if (hours == 12 &&  isAM) {  // If 12am
            hours = 0;  // Set hours to 0;
        }
        if (hours < 10) {
            convertedTime += "0";  // Add leading 0
        }
        convertedTime += std::to_string(hours) + ":";  // add hours and time seperator
        if (minutes < 10) {
            convertedTime += "0";  // Add leading 0
        }
        convertedTime += std::to_string(minutes);  // add minutes
    }
    else {  // If user didn't provide AM/PM
        if (!isAM) {  // If PM
            hours -= 12;  // subtract 12 hours from time
        }
        if (hours < 10) {
            convertedTime += "0";  // add leading 0
        }
        convertedTime += std::to_string(hours) + ":";  // add hours and time seporator
        if (minutes < 10) {
            convertedTime += "0";  // add leading 0
        }
        convertedTime += std::to_string(minutes);  // add minutes
        if (!isAM) {
            convertedTime += " PM";   // add PM
        }
        else {
            convertedTime += " AM";   // add AM
        }
    }
    return convertedTime;  // return new convertedTime string
}

// This function outputs the results of the time converted to the new notation
// Pre: menuChoice, hours, minutes, isAM, convertedTime
// Post: menuChoice, hours, minutes, isAM, convertedTime
// In: convertedTime(type:string used in output string)
// Out: n/a
// In-Out: n/a
void displayResults(std::string convertedTime) {
    std::cout << "\n";  // new line to match example
    std::cout << "The time is: " << convertedTime << std::endl;  // print converted time
    std::cout << "\n";  // new line to match example
}

// This function is the main function of the program, which calls other functions to gather and calculate the times.
// Pre: n/a
// Post: n/a
// In: n/a
// Out: n/a
// In-Out: n/a
int main() {
    int menuChoice = displayMenu();  // display menu; store answer in variable
    while (menuChoice != 0) {  // while the user wants to continue
        int hours = getTime("hours");  // gets hours from user
        int minutes = getTime("minutes");  // gets minutes from user
        bool isAM = getIsAM(menuChoice, hours);  // determines AM/PM
        std::string convertedTime = convertTime(menuChoice, hours, minutes, isAM);  // converts time
        displayResults(convertedTime);  // display results
        menuChoice = displayMenu();  // print menu
    }
    
    return 0;  // return 0 and end program
}
