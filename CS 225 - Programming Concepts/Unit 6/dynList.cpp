#include "DynList.h"
#include <iostream>

// constructor
dynListType::dynListType(int size = 5) { 
  maxSize = size;  // set maxSize;  set to 5 if not provided
  dataPtr = new int[size];
}

// copy constructor
dynListType::dynListType(dynListType &obj) {
  this -> size = obj.size;  // sets size
  this -> maxSize = obj.maxSize;  // sets maxSize
  this -> dataPtr = new int[this -> size];
  for (int i = 0; i < size; i++)  // for every element in the list
  {
    this -> dataPtr[i] = obj.dataPtr[i];  // copy element to new list
  }
}

// destructor
dynListType::~dynListType() {
  delete dataPtr; // releases memory
}

// return number of ints actually stored in the list
int dynListType::getSize() const { 
  return size;
}

// returns the capacity of the list
int dynListType::getMaxSize() const {
  return maxSize;
} 

// returns whether the list is empty or not
bool dynListType::isEmpty() const {
  return size == 0;  
}

// looks for an int and returns index of first occurrence; returns -1 if not found
int dynListType::search(int element) const {  
  for (int i = 0; i < size; i++) {  // for every index in list
    if (dataPtr[i] == element) {  // if index equals element
      return i;  // return the index it was found at
    }
  }
  return -1; // return -1 if not found
}

// returns int at a specific index
int dynListType::at(int index) const {  
  if (index >= 0 && index <= size) {  // if index is valid
    return dataPtr[index];  // return int at index
  }
  else {
    std::cout << "Invalid index accessed" << std::endl;  // otherwise print invalid index
    return false;
  }
}

// inserts an int at the end of the list
void dynListType::insert(int element) {
  if (size < maxSize) {  // if room in list
    dataPtr[size] = element;  // insert element
  }
  else {
    int i;
    maxSize *= 2;  // doubles the maxSize of the list
    int *temp = new int[maxSize]; // create a temporary array
    for (i = 0; i < size; i++) {
      temp[i] = dataPtr[i]; //copy the elements to the temporary array
    }
    temp[i] = element; // insert new int at the end of the list
    delete dataPtr;  // releases memory
    dataPtr = temp;  // set dataPrt equal to temp list
  }
  size++;  // increment size
}

// insert an element into location index and shift remaining elements
bool dynListType::insert(int index, int element) {
  if (index >= 0 && index <= size) {
    int i;  // declare int i
    
    if (size >= maxSize) {
      maxSize *= 2;  // doubles the maxSize of the list
      int *temp = new int[maxSize]; // create a temporary array
      for (i = 0; i < size; i++) {  // for every element in the list
        temp[i] = dataPtr[i];  // copy the elements
      }

      delete dataPtr; // releases memory
      dataPtr = temp;  // set dataPtr equal to temp list
    }

    size++;  // increment size

    for (i = size; i > index; i--) {  // for every element in the list; starting at last number
      dataPtr[i] = dataPtr[i - 1];  // shift index
    }
    dataPtr[i] = element;  // insert new element
    return true;  // return true for successful insert
  }
  return false;  // return false for failed insert
}

// remove element at the specified location and shift remaining elements
bool dynListType::remove(int index) {  
  if (index >= 0 && index <= size) {  // if valid index given
    for (int i = index; i < size; i++) {  // for every element in list
      dataPtr[i] = dataPtr[i + 1];  // shift element
    }
    size--;  // decrement size
    return true;  // return true for successful remove
  }
  return false;  // return false for failed remove
}

// overloading of + operator
dynListType *dynListType::operator+(const dynListType *other) const {
  int size1 = this -> size;  // get size of list 1
  int size2 = other -> getSize();  // get size of list 2
  int newSize = size1 + size2;  // set new size equal to size1 + size 2
  
  dynListType *tempList = new dynListType(newSize);  // create new list of new size type

  for (int i = 0; i < size; i++) {  // for every int in list 1.
    tempList -> insert(this -> at(i));  // insert element into tempList list
  }
  for (int i = 0; i < size2; i++) {  // for every int in list 2.
    tempList -> insert(other ->at(i));  // insert element into tempList list
  }
  return tempList;  // return the new list
}

// overloading of assignment operator
void dynListType::operator=(dynListType &obj) {
  this -> size = obj.size;  // set sizes to be the same
  this -> maxSize = obj.maxSize;  // set max sizes to be the same
  this -> dataPtr = new int[this -> size]; 
  for (int i = 0; i < size; i++) {  // for every element in the list
    this->dataPtr[i] = obj.dataPtr[i];  // copy element
  }
}

//overloading of == operator
bool dynListType::operator==(dynListType obj) {
  if (this->size != obj.size) {  // if lists are not the same length
    return false;
  }
  for (int i = 0; i < size; i++) {  // for every element in the list
    if (this -> dataPtr[i] != obj.dataPtr[i]) {  // if the values are not the same
      return false;
    }
  }
  return true; // the lists are equal
}
