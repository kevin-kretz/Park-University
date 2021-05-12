// queue.cpp
// By: Kevin Kretz | 2 May 2021

#include "queue.h"
#include <iostream>


bool queue::isEmpty() const {
  return (length == 0);  // return whether length is 0 or not
}

int queue::size() const {
  return length;  // return length of queue
}

int queue::front() const {
  int retItem;  // create variable retItem
  retrieveAt(0, retItem);  // call retreiveAt() from arrayListType
  return (retItem);  // return retItem
}

int queue::back() const {
  int index = length - 1;  // create variable index; initialize it to length of queue - 1
  int retItem;  // create variable retItem
  retrieveAt(index, retItem);  // call retreiveAt() from arrayListType
  return (retItem);  // return retItem
}

void queue::enque(int newItem) {
  insertEnd(newItem);  // call insertEnd() from unorderedArrayListType
}

int queue::deque() {
  int index = length - 1;  // create variable index;  initialize it to length of queue - 1
  int retItem;  // create variable retItem
  retrieveAt(index, retItem);  // call retreiveAt() from arrayListType
  removeAt(index);  // call removeAt() from arrayListType
  return (retItem);  // return retItem
}

queue::queue(int size) {
  maxSize = size;  // set maxSize to current size
  length = 0;  // set length to 0
  list = new int[maxSize];  // create a new list
}

std::ostream &operator<<(std::ostream &out, const queue &obj) {
  for (int i = 0; i < obj.length; i++) {  // for every object in list
    out << obj.list[i] << " ";  // add object to output; space to seperate objests
  }
  return out;  // return output
} //end operator<<
