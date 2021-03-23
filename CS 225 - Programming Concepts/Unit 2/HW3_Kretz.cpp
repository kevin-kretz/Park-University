// This program converts the time from 24-hour notation to 12-hour notation and vice versa.
// Unit 2 - Homework 3
// Kevin Kretz | 23 March 2021

#include <iostream>

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

std::string getTime(int menuChoice){
    std::string hours;
    std::string minutes;
    std::string amPM;
    
    std::cout << "Enter hours: ";
    std::cin >> hours;
    std::cout << "Enter minutes: ";
    std::cin >> minutes;
    
    if (menuChoice == 1) {
        std::cout << "Enter AM/PM (A or P): ";
        std::cin >> amPM;
        return hours + " " + minutes + " " + amPM;
    }
    else {
        return hours + " " + minutes;
    }
    
}

int main() {
    int menuChoice = displayMenu();
    std::string time = getTime(menuChoice);
    std::cout << time;
    return 0;
}
