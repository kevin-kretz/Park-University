// This program is the same as last weeks program; however, it removes the maxsize of the list
// By: Kevin Kretz | 25 April 2021

#include <iostream>
#include "DynList.h"

int main() {
  // creae list1
  dynListType *list1 = new dynListType(5);

  // insert elements into list1
  list1 -> insert(10);
  list1 -> insert(20);

  std::cout << "List one: " << list1 << std::endl;
  std::cout << "Is 40 in list one? Answer (-1 means no): " << list1 -> search(40) << std::endl;
  std::cout << "Is 10 in list one? Answer (-1 means no): " << list1 -> search(10) << std::endl;
  std::cout << "\n" << std::endl;  // print new line to match example

  // create list 2
  dynListType *list2 = new dynListType(5);

  // insert elements into list2
  list2 -> insert(100);
  list2 -> insert(1000);
  list2 -> insert(20);
  list2 -> insert(10);

  std::cout << "List two: " << list2 << std::endl;

  // remove number at index 0
  list2 -> remove(0);

  std::cout << "List two after removing [0]: " << list2 << std::endl;
  std::cout << "\n" << std::endl;  // print new line to match example

  // add list2 to list 1
  list1 = (*list1 + list2);

  std::cout << "list1, after list1 + list2: " << list1 << std::endl;
  std::cout << "list1 == list2: " << (list1 == list2) << std::endl;

  // set list1 = list 2;
  list1 = list2;
  std::cout << "list1 == list2, after list1 = list2: " << (list1 == list2) << std::endl;
  std::cout << "list1, after list1 = list2: " << list1 << std::endl;

  // create list3; set list3 = list2
  dynListType *list3 = list2;
  std::cout << "list3: maxSize " << list3 -> getMaxSize() << ", " << list3 << std::endl;

  // append 0 to end of list 3
  list3 -> insert(0);
  std::cout << "list3, after append/insert: maxValue" << list3 -> getMaxSize() << ", " << list3 << std::endl;

  // append 10 to end of list 3
  list3 -> insert(10);
  std::cout << "list3, after append/insert: maxValue" << list3 -> getMaxSize() << ", " << list3 << std::endl;

  // append 20 to end of list 3
  list3 -> insert(20);
  std::cout << "list3, after append/insert: maxValue" << list3 -> getMaxSize() << ", " << list3 << std::endl;

  // append 30 to end of list 3
  list3 -> insert(30);
  std::cout << "list3, after append/insert: maxValue" << list3 -> getMaxSize() << ", " << list3 << std::endl;

  // append 40 to end of list 3
  list3 -> insert(40);
  std::cout << "list3, after append/insert: maxValue" << list3 -> getMaxSize() << ", " << list3 << std::endl;

  // append 0 to begginging of list 3
  list3 -> insert(0, 0);
  std::cout << "list3, after insert(0, val): maxValue" << list3 -> getMaxSize() << ", " << list3 << std::endl;

  // append 20 to begginging of list 3
  list3 -> insert(0, 20);
  std::cout << "list3, after insert(0, val): maxValue" << list3 -> getMaxSize() << ", " << list3 << std::endl;

  // append 40 to begginging of list 3
  list3 -> insert(0, 40);
  std::cout << "list3, after insert(0, val): maxValue" << list3 -> getMaxSize() << ", " << list3 << std::endl;

  // append 60 to begginging of list 3
  list3 -> insert(0, 60);
  std::cout << "list3, after insert(0, val): maxValue" << list3 -> getMaxSize() << ", " << list3 << std::endl;

  // append 80 to begginging of list 3
  list3 -> insert(0, 80);
  std::cout << "list3, after insert(0, val): maxValue" << list3 -> getMaxSize() << ", " << list3 << std::endl;

  // return 7th element
  std::cout << "index 7 of list3: " << list3 -> at(7) << std::endl;

  // remove 7th element
  list3 -> remove(7);
  std::cout << "list3, after remove(7) " << list3 << std::endl;

  return 0;
}
