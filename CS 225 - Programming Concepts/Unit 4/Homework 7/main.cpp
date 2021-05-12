#include <iostream>
#include <string>
#include <sstream>

int *readNum(int &numOfDigits /*OUT*/);

int *sumNum(const int *pNum1 /*IN*/, int numOfDigits /*IN*/, const int *pNum2 /*IN*/,
            int numOfDigits2 /*IN*/, int &numOfDigitsResult /*OUT*/);

void print(const int *pNum /*IN*/, int numOfDigits /*IN*/);

int main()
{
  int userAmtOfDigits1, userAmtOfDigits2, totalDigits;
  int *userNumberPtr1 = new int[userAmtOfDigits1];
  int *userNumberPtr2 = new int[userAmtOfDigits2];
  int *userNumberPtr3;

  userNumberPtr1 = readNum(userAmtOfDigits1);
  userNumberPtr2 = readNum(userAmtOfDigits2);

  userNumberPtr3 = sumNum(userNumberPtr1, userAmtOfDigits1, userNumberPtr2,
                          userAmtOfDigits2, totalDigits);

  print(userNumberPtr3, totalDigits);

  return 0;
} //end main

int *readNum(int &numOfDigits /*IN*/)
{
  std::string userInput;
  int userNumber, amtOfDigits;

  std::cout << "Please enter a positive integer: ";
  std::getline(std::cin, userInput);
  std::cout << std::endl;

  numOfDigits = userInput.length();
  int *returnNumPtr = new int[userInput.length()];

  for (int i = 0; i < numOfDigits; i++)
  {
    returnNumPtr[i] = int(userInput[i] - 48);

  }
  return returnNumPtr;
} //end readNum

int *sumNum(const int *pNum1 /*IN*/, int numOfDigits /*IN*/, const int *pNum2 /*IN*/,
            int numOfDigits2 /*IN*/, int &numOfDigitsResult /*OUT*/) {

  int *pNum3 = new int[numOfDigitsResult];
  int carryOver = 0;

  if (numOfDigits >= numOfDigits2) {
    numOfDigitsResult = numOfDigits + 1;
    int i = 1;
    while (i <= numOfDigits2) {
      pNum3[numOfDigitsResult - i] = (pNum1[numOfDigits - i] + pNum2[numOfDigits2 - i] + carryOver) % 10;
      carryOver = (pNum1[numOfDigits - i] + pNum2[numOfDigits2 - i] + carryOver) / 10;
      i++;
    }
    while (i <= numOfDigits) {
      pNum3[numOfDigitsResult - i] = (pNum1[numOfDigits - i] + carryOver) % 10;
      carryOver = (pNum1[numOfDigits - i] + carryOver) / 10;
      i++;
    }
    pNum3[0] = carryOver;
  }
  else {
    numOfDigitsResult = numOfDigits2 + 1;
    int i = 1;
    while (i <= numOfDigits) {
      pNum3[numOfDigitsResult - i] = (pNum1[numOfDigits - i] + pNum2[numOfDigits2 - i] + carryOver) % 10;
      carryOver = (pNum1[numOfDigits - i] + pNum2[numOfDigits2 - i] + carryOver) / 10;
      i++;
    }
    while (i <= numOfDigits2) {
      pNum3[numOfDigitsResult - i] = (pNum2[numOfDigits2 - i] + carryOver) % 10;
      carryOver = (pNum2[numOfDigits2 - i] + carryOver) / 10;
      i++;
    }
    pNum3[0] = carryOver;
  }

  return pNum3;
} //end sumNum

void print(const int *pNum /*IN*/, int numOfDigits /*IN*/) {
  std::cout << "The sum of the numbers is: ";
  for (int i = 0; i < numOfDigits; i++) {
    if (!(i == 0 && pNum[i] == 0)) {
      std::cout << pNum[i];
    }
  }
  std::cout << std::endl;
} //end print
