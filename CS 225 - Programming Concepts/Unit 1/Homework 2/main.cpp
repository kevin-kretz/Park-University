#include <iostream>  // Included input and output streams
#include <string> // Include string
#include <iomanip>  // Include input output manipulation

bool finished() {
  char answer;
  std::cout << "Would you like to enter another number? (Enter \"Y\" for yes or \"N\" for no): ";
  std::cin >> answer;

    if (toupper(answer) == 89){  // If user enters y
      std::cin.ignore();  // Clears user input
      return false;
    }

    else {
      return true;
    }
}

std::string getOriginalPhoneNumber() {
  char userPhoneNumber[8]; // Declare variable userPhoneNumber
  std::cout << "Enter a telephone number (in letters or numbers): ";  // Prompts user for a phone number
  std::cin.getline(userPhoneNumber, 9);  // Stores user response into userPhoneNumber;
  return userPhoneNumber;
}

bool isError(std::string originalPhoneNumber) {
  for (int i = 0; i < originalPhoneNumber.length(); i++) {
    char ch = toupper(originalPhoneNumber[i]);

    bool isLetter = false;
    bool isNumber = false;
    bool isSpace = false;
    bool isHyphen = false;

    if (ch >= 'A' && ch <= 'Z') {
      isLetter = true;
    }
    else if (ch >= '0' && ch <= '9') {
      isNumber = true;
    }
    else if (ch == ' ') {
      isSpace = true;
    }
    else if (ch == '-') {
      isHyphen = true;
    }

    if (!isLetter && !isNumber && !isSpace && !isHyphen) {
      return true;
    }
  }
  return false;
}

std::string convert(std::string originalPhoneNumber) {
  // Declare variables
  std::string actualPhoneNumber;

  for (int i = 0; i <= originalPhoneNumber.length(); i++) {
    char ch = toupper(originalPhoneNumber[i]);   // converts character to uppercase 
    
    // Adds hypen after 3rd number
    if (i == 3) {
      actualPhoneNumber.append("-");
    }

    // If letter, convers to number
    if (ch >= 'A' && ch <= 'Z') {
      if (ch >= 'A' && ch <= 'C') {
        actualPhoneNumber.append("2");
      }
      else if (ch >= 'D' && ch <= 'F') {
        actualPhoneNumber.append("3");
      }
      else if (ch >= 'G' && ch <= 'I') {
        actualPhoneNumber.append("4");
      }
      else if (ch >= 'J' && ch <= 'L') {
        actualPhoneNumber.append("5");
      }
      else if (ch >= 'M' && ch <= 'O') {
        actualPhoneNumber.append("6");
      }
      else if (ch >= 'P' && ch <= 'S') {
        actualPhoneNumber.append("7");
      }
      else if (ch >= 'T' && ch <= 'V') {
        actualPhoneNumber.append("8");
      }
      else {
        actualPhoneNumber.append("9");
      }
    }

    // Adds number to string
    else if (ch >= '0' && ch <= '9') {
      actualPhoneNumber.append(std::string(1, ch));
    }
  }
  return actualPhoneNumber;
}

int main() {
  // declares variables
  std::string originalPhoneNumber;
  std::string actualPhoneNumber;

  do {
    originalPhoneNumber = getOriginalPhoneNumber();
    if (isError(originalPhoneNumber)) {
      std::cout << "Invalid Character: Please make sure to only enter letters, numbers, dashes and spaces." << std::endl;
    }
    else {
      actualPhoneNumber = convert(originalPhoneNumber);
      std::cout << actualPhoneNumber << std::endl;
    }
  }

  while (!finished());

  return 0;
}
