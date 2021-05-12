// driver.cpp
// By: Kevin Kretz | 2 May 2021

#include "arrayListType.h"
#include "unorderedArrayListType.h"
#include "queue.h"

#include <iostream>

int main() {
  ////////////////////////////
  // included in shell code //
  ////////////////////////////
  unorderedArrayListType intList(25);

  for (int i = 0; i < 8; i++)
    intList.insertEnd(i * 10 + 5);
  std::cout << "intList: " << intList << std::endl;

  //Create temp and initialize it using intList
  unorderedArrayListType temp(intList);
  std::cout << "temp: " << temp << std::endl;

  //Replace the first element of temp.
  temp.replaceAt(0, -75);
  std::cout << "temp first element replaced: " << temp << std::endl;

  std::cout << "intList: " << intList << std::endl;
  ////////////////////////////////
  // end included in shell code //
  ////////////////////////////////

  std::cout << std::endl;  // blank space for readability
  std::cout << std::endl;  // blank space for readability

  // create new queueList
  queue queueList(10);
  std::cout << "Queue created!" << std::endl;
  std::cout << "Queue is empty: "  << queueList.isEmpty() << std::endl;
  std::cout << std::endl;  // blank space for readability

  // insert 8 numbers into queue
  for (int i = 0; i < 8; i++) {
    queueList.enque(i * 10 + 5);
  }
  std::cout << "Queue after inserts: " << queueList << std::endl;
  std::cout << "Queue is empty: "  << queueList.isEmpty() << std::endl;
  std::cout << std::endl;  // blank space for readability

  std::cout << "Current queue size: " << queueList.size() << std::endl;
  std::cout << "Oldest item in queue: " << queueList.front() << std::endl;
  std::cout << "Youngest item in queue: " << queueList.back() << std::endl;
  std::cout << std::endl;  // blank space for readability

  queueList.enque(85);
  std::cout << "Queue, after enque: " << queueList << std::endl;
  std::cout << "Queue size, after enque: " << queueList.size() << std::endl;

  queueList.deque();
  queueList.deque();
  std::cout << "Queue, after two deques: " << queueList << std::endl;
  std::cout << "Queue size, after enque: " << queueList.size() << std::endl;
  return 0;
} // end main
