// This project encrypts and decrypts strings
// By Kevin Kretz
// 3 Apr 2021

/*       Pseudo code for encryption function

for (ever character in string):
  if (character is letter):
    if (character is lowercase):
      character's ascii value = 219 - current ascii value
    else if (character is uppercase):
      character's ascii value = 155 - current ascii value
  else if (character is number):
      convert char to int
      get new number and convert back to char
 
 */

#include <iostream>

// declare functions
std::string encrypt(std::string plainTextString  /*IN*/);
std::string shiftString(std::string originalString /*IN*/, bool unshift /*IN*/);
std::string encryptLetters(std::string plainTextString /*IN*/);
std::string decrypt(std::string encryptedString /*IN*/);

int main(){
  std::string str = "Supercalifragilisticexpialidocious 17 #&";  // string to be encrypted
  std::string secretStr = encrypt(str);  // encrypt string and save it as a variable

  std::cout << "original:  " << str << '\n';  // print original string
  std::cout << "encrypted: " << secretStr << '\n';  // print encrypted string
  std::cout << "decrypted: " << decrypt(secretStr) << '\n';  // print decrypted string

  return 0;
}

// This function takse a plain text string, and encrypts it by shifting the letters and changing them to the other half of the alphabet
// Pre-Function: only the shiftString() and encryptLetters() functions need to be declared
// Post-function: will retrun encrypted string
std::string encrypt(std::string plainTextString) {
  std::string shiftedString = shiftString(plainTextString, false);  // shift the letters and store result in a variable
  std::string encryptedString = encryptLetters(shiftedString);  // encrypt shifted letters to other half of the alphabet
  return encryptedString;
}

//  This process is the same as encrypting, just in the reverse order
// Pre-Function: only the shiftString() and encryptLetters() functions need to be declared
// Post-function: will retrun plain text string
std::string decrypt(std::string encryptedString) {
  std::string shiftedString = encryptLetters(encryptedString);  // decryptes the letters (leaving just a shifted string) and stores the result into a variable
  std::string plainTextString = shiftString(shiftedString, true);  // unshifts the letters to correct positions
  return plainTextString;
}

// This function shifts right length()/2  positions (toward higher index)
// Pre-Function: original string needs to be declared, and whether or not this is to unshift the letters also needs to be included
// Post-function: will return a shifted or unshifted string based on function input
std::string shiftString(std::string originalString /*IN*/, bool unshift /*IN*/) {
    std::string shiftedString = originalString;  // duplicates string; removes need for temp variable
    int shiftAmount = originalString.length() / 2;  // shift amount per instructions
    
    if (unshift == true && originalString.length() % 2 == 1) {  // if unshifting, and there are an odd number of letters
      shiftAmount += 1;  // add one to compensate for division
    }

    for (int i = 0; i < shiftedString.length(); i++) {  // for every letter in the string
      int j = (i + shiftAmount) % shiftedString.length();  // set to variable for readability; original index of letter + shift amount; % shiftedString.length to allow for rollover to index 0
      shiftedString[j] = originalString[i];  // assigns letter its new index
    }

    return shiftedString;
}

// This function encrypts the letters by switching them to the other half of the alphabet.  (e.g. A -> Z, B -> Y  ...  y -> b, z -> a)
// Pre-Function: Prior to this function, only a string needs to be declared and passed in as an arguement
// Post-function: will retrun encrypted string
std::string encryptLetters(std::string plainTextString /*IN*/) { 
  std::string encryptedLetters = plainTextString; // duplicates string; removes need for temp variable

  for (int i = 0; i < encryptedLetters.length(); i++) {  // for each letter in string length
    if (toupper(encryptedLetters[i]) >= 'A' && toupper(encryptedLetters[i]) <= 'Z') {  // if index is a letter
      if (encryptedLetters[i] >= 'a') {  // if letter is lowercase
        encryptedLetters[i] = char(219) - encryptedLetters[i];  // unencrypted letter + encrypted letter = 219;  Therefore 219 - current letter = letter ecrypted
      }
      else {  // if letter is uppercase
        encryptedLetters[i] = char(155) - encryptedLetters[i];  // unencrypted letter + encrypted letter = 155;  Therefore  155 - current letter = letter ecrypted
      }
    }
    else if (encryptedLetters[i] >= '0' && encryptedLetters[i] <= '9') { // if index is number
      int j = int(encryptedLetters[i]) - 48;  // j is the int version of the int stored in a char
      encryptedLetters[i] = char(9 - j + 48);  // unencrypted letter + encrypted letter = 9;  Therefore 9 - j = int encrypted;  + 48 to get ascii char
      
    }
  }
  return encryptedLetters;
}
