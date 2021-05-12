// Static Array Based Lists driver file
// By: Kevin Kretz | 18 April 2021

#include "listType.h"
#include <iostream>

int main() {
  listType one(2);  // create list named "one" with max of two integers
  one.insert(10);  // insert 10 into list
  one.insert(20);  // insert 20 into list
  
  std::cout << "List one: " << one << std::endl;  // print out list one
  std::cout << "Is 40 in list? Answer (-1 means no): " << one.search(40) << std::endl;  // search list one for 40; print result
  std::cout << "Is 10 in list? Answer (-1 means no): " << one.search(10) << std::endl;  // search list one for 10; print result
  
  listType two(4);  // create new list named "two" with max of four integers
  two.insert(100);  // instert 100 into list
  two.insert(1000);  // instert 1000 into list
  two.insert(20);  // instert 20 into list
  two.insert(10);  // instert 10 into list
  
  std::cout << "\nList two: " << two << std::endl; // print out list two; included new line per example in instructions
  two.remove(0);  // remove int at index 0 from list
  std::cout << "List two after removing [0]: " << two << std::endl;  // print list two again
  listType three = one + two;  // create new list named three; by adding list one and list two together
  std::cout << "\nList one + list two : " << three << std::endl; // print list three; included new line per example in instructions

  return 0;
}
