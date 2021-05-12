// Implementation file for listType class
// By: Kevin Kretz | 18 April 2021

#include "listType.h"
#include <assert.h>

//Constructor
listType::listType(int max/*IN*/) {
  if (max > 0) {  // if max is greater than 0
    maxSize = max;  // set maxSize to max
  }
  else {  // if max is less than 1
    maxSize = 5;  // maxSize is set to 5
  }
  size = 0;  // set size to 0
}


// Looks for an iteger; returns index of first occurrence
// PRE: list must be created and integer must be passed in to find
// POST: return index of the element if found; -1 if not found
int listType::search(int element /*IN*/) const {
  for (int i = 0; i < size; i++) {  // for every integer in list
    if (dataArr[i] == element) {  // if two integers are the same
      return i;  // return index of integer in list
    }
  }

  return -1;  // return -1 for failed search
}


// PRE: 0 <= index < size
// POST: integer at index in dataArr is returned
int listType::at(int index  /*INOUT*/) const {
  assert(index >= 0 && index < size);
  return dataArr[index];  // returns integer
}


// Adds an element at the end of the list
// PRE: list must be created. int must be given to insert
// POST: element is added at the end of dataArr if size<maxSize
bool listType::insert(int element  /*INOUT*/) {
  if (size < maxSize) {  // if size of list is less than max size
    dataArr[size] = element;  // set integer at index to element
    size++;  // increment size
    return true;  // Return true for successful insert
  }
  return false;  // Return false for failed insert
}


// Inserts an element into a specified index; shifts the current element and any following elements to the right
// PRE: list must be declared; index to insert must be given; int must be given to insert;
// POST: element is added at index if size<maxSize and 0<=index<=size
bool listType::insert(int index, int element) {
  if (size < maxSize) {  // if size is less than max
    if (index >= 0 && index < size) {  // if index is within list size
      for (int i = size; i > index; i--) {  // for ever integer in list; starting at the end of the list
        dataArr[i] = dataArr[i - 1];  // shift integers to the right
      }
      dataArr[index] = element;  // insert new integer
      size++;  // increment size
      return true;  // return true for successful insert
    }
    else if (index == size) {  // if index is the last in size
      return (insert(element));  // run insert function; which will return boolean value
    }
    else {
      return false;  // return false for failed insert
    }
  }
  else {
    return false;  // return false for failed insert
  }
}


// Removes integer at the specified location
// PRE: list must be created; index to remove must be provided
// POST: integer at index is removed from the list; (if 0 <= index < size)
bool listType::remove(int index) {
  if (index >= 0 && index < size) {  // if index is within list size
    if (index == size - 1) {  // if index is the last element
      size--;  // decrement size
      return true;  // return true for successful remove
    }
    else {  // if not last element
      for (int i = index; i < size - 1; i++) {  // for every element in list; starting at index
        dataArr[i] = dataArr[i + 1];  // shift all elements to the left
      }
      size--;  // decrement size
      return true;  // return true for successful remove
    }
  }
  return false;  // return false for failed remove
}

// prints the contents of the list
// PRE: list must be created;
// POST: no changes made
std::ostream &operator<<(std::ostream &out, const listType &list) {
  out << "[";  // print opening bracket
  for (int i = 0; i < list.size - 1; i++) { // for every integer in list (except last)
    out << list.dataArr[i] << ", ";  // print iteger followed by ","
  }
  out << list.dataArr[list.size - 1] << "] ";  // for last element: print integer only
  return out;  // returns out
}


// concatenates two lists together
// PRE: two lists must be created and passed in
// POST: returns a list which contains integers from both the lists in arguments
listType listType::operator+(const listType &other) {
  listType concatList(size + other.size);  // create new list that is size1 + size2 in length
  for (int i = 0; i < size; i++) {  // for every integer in first list
    concatList.insert(dataArr[i]);  // insert integer into new list
  }
  for (int i = 0; i < other.size; i++) {  // for every integer in second list
    concatList.insert(other.dataArr[i]);  // insert integer into new list
  }
  return concatList;  // return new list
}
