// This program converts the time from 24-hour notation to 12-hour notation and vice versa.
// Unit 2 - Homework 3
// Kevin Kretz | 23 March 2021

#include <iostream>
#include <string>

int displayMenu() {
    int menuChoice;
    
    std::cout << "Options --" << std::endl;
    std::cout << "1: To convert time from 12-hour notation to 24-hour notation." << std::endl;
    std::cout << "2: To convert time from 24-hour notation to 12-hour notation." << std::endl;
    std::cout << "0: To quit the program." << std::endl;
    std::cout << "Choose: ";
    std::cin >> menuChoice;
    std::cout << "\n";
    return menuChoice;
}

int getTime(std::string unit) {
    int time;
    std::cout << "Enter " << unit << ": ";
    std::cin >> time;
    return time;
}

bool getIsAM(int menuChoice, int hours){
    bool isAM;
    if (menuChoice == 1) {
        char userInput;
        std::cout << "Enter AM/PM (A or P): ";
        std::cin >> userInput;
        
        if (toupper(userInput) == 'A') {
            isAM = true;
        }
        else {
            isAM = false;
        }
    }
    else {
        if (hours <= 12) {
            isAM = true;
        }
        else {
            isAM = false;
        }
    }
    std::cout << "\n";
    return isAM;
}

std::string convertTime(int menuChoice, int hours, int minutes, bool isAM) {
    std::string convertedTime;
    
    if (menuChoice == 1) {
        if (!isAM) {
            hours += 12;
        }
        convertedTime = std::to_string(hours) + ":" + std::to_string(minutes);
    }
    else {
        if (!isAM) {
            hours -= 12;
        }
        convertedTime = std::to_string(hours) + ":" + std::to_string(minutes);
        if (!isAM) {
            convertedTime += " PM";
        }
        else {
            convertedTime += " AM";
        }
    }
    return convertedTime;
}

void displayResults(std::string convertedTime) {
    std::cout << "The time is: " << convertedTime << std::endl;
}

int main() {
    int menuChoice = displayMenu();
    int hours = getTime("hours");
    int minutes = getTime("minutes");
    bool isAM = getIsAM(menuChoice, hours);
    std::string convertedTime = convertTime(menuChoice, hours, minutes, isAM);
    displayResults(convertedTime);
    return 0;
}
