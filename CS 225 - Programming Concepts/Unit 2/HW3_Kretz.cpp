// This program converts the time from 24-hour notation to 12-hour notation and vice versa.
// Unit 2 - Homework 3
// Kevin Kretz | 23 March 2021

#include <iostream>

void showMenu() {
    std::cout << "Options --" << std::endl;
    std::cout << "1: To convert time from 12-hour notation to 24-hour notation." << std::endl;
    std::cout << "2: To convert time from 24-hour notation to 12-hour notation." << std::endl;
    std::cout << "0: To quit the program." << std::endl;
    std::cout << "Choose: ";
}

int getUserChoice() {
    int userChoice;
    showMenu();
    std::cin >> userChoice;
    return userChoice;
}

int main() {
    int userChoice = getUserChoice();
    std::cout << userChoice;
    return 0;
}
