#include <iostream>  // Included input and output streams
#include <string> // Include string
#include <iomanip>  // Include input output manipulation

int main() {
  // Declare variables
  std::string userPhoneNumber; // Declare variable userPhoneNumber
  int actualPhoneNumber[7]; // Declare int array actualPhoneNumber
  int phoneNumberIndex = 0; // Declare phoneNumberIndex

  // Gather user input
  std::cout << "Enter a telephone number (in letters or numbers): ";  // Prompts user for a phone number
  std::cin >> userPhoneNumber;  // Stores user response into userPhoneNumber
  
  // Changes the phone number into only numbers
  for (int i = 0; i <= 7; i++) { // Only process the first 8 digits.  Only ouputs 7 digits.  8th digit is incase of included hyphen or space.
    char digit = toupper(userPhoneNumber[i]);  // Stores digit in uppercase form for ease of conditional statement
    
    // Changes letter to number and addes to actualPhoneNumber array
    if (digit >= 'A' && digit <= 'Z') {  // If the current digit is a letter
      if (digit >= 'A' && digit <= 'C') {
        actualPhoneNumber[phoneNumberIndex] = 2;  // If 'A - C' store 2 in actualPhone number
      }
      else if (digit >= 'D' && digit <= 'F') {
        actualPhoneNumber[phoneNumberIndex] = 3;  // If 'D - F' store 3 in actualPhone number
      }
      else if (digit >= 'G' && digit <= 'I') {
        actualPhoneNumber[phoneNumberIndex] = 4;  // If 'G - I' store 4 in actualPhone number
      }
      else if (digit >= 'J' && digit <= 'L') {
        actualPhoneNumber[phoneNumberIndex] = 5;  // If 'J - L' store 5 in actualPhone number
      }
      else if (digit >= 'M' && digit <= 'O') {
        actualPhoneNumber[phoneNumberIndex] = 6;  // If 'M - O' store 6 in actualPhone number
      }
      else if (digit >= 'P' && digit <= 'S') {
        actualPhoneNumber[phoneNumberIndex] = 7;  // If 'P - S' store 7 in actualPhone number
      }
      else if (digit >= 'T' && digit <= 'V') {
        actualPhoneNumber[phoneNumberIndex] = 8;  // If 'T - V' store 8 in actualPhone number
      }
      else {
        actualPhoneNumber[phoneNumberIndex] = 9;  // Otherwise store 9 in actualPhone number
      }

      phoneNumberIndex++;
    }

    else if (digit >= '0' && digit <= '9') {
      actualPhoneNumber[phoneNumberIndex] = digit-48;  // subtracts 48 to eliminate ASCII number.
      phoneNumberIndex++;
    }
  }

  // Return 0 and end of program 
  return 0;
}
