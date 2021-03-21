#include <iostream>  // Included input and output streams
#include <string> // Include string
#include <iomanip>  // Include input output manipulation

bool isFinished() {
  char answer;
  std::cout << "Would you like to enter another number? (Enter \"Y\" for yes or \"N\" for no): ";
  std::cin >> answer;

    if (toupper(answer) == 89){  // If user enters y
      return false;
    }

    else {
      return true;
    }
}

std::string getOriginalPhoneNumber() {
  char userPhoneNumber[8]; // Declare variable userPhoneNumber
  std::cout << "Enter a telephone number (in letters or numbers): ";  // Prompts user for a phone number
  std::cin.ignore();
  std::cin.getline(userPhoneNumber, 9);  // Stores user response into userPhoneNumber;
  return userPhoneNumber;
}

int convert(std::string originalPhoneNumber) {
  
}

int main() {
  // declares variables
  bool finished = false;
  std::string originalPhoneNumber;
  std::string actualPhoneNumber;

  while (!finished) {
    originalPhoneNumber = getOriginalPhoneNumber();
    actualPhoneNumber = convert(originalPhoneNumber);
    std::cout << originalPhoneNumber << std::endl;
    finished = isFinished();
  }

  return 0;
}
