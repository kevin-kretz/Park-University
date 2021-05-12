#ifndef _DYNLIST_H_
#define _DYNLIST_H_

#include <ostream>

class dynListType {
  private:
    int *dataPtr;  // static array storing data items
    int size;  // actual number of elements stored
    int maxSize;  // the capacity

  public:
    dynListType(int para); // constructor
    dynListType(dynListType &obj);  // copy constructor
    ~dynListType();  // destructor
    int getSize() const;  // return number of elements actually stored in list
    int getMaxSize() const;  // return capacity of list
    bool isEmpty() const;  // returns if list is empty
    int search(int element) const;  // looks for an item and return index of first occurrence; returns -1 if not found
    int at(int index) const;  // returns element at a specific index
    void insert(int element);  // insert an element at the end of the list
    bool insert(int index, int element);  // inserts element into given index; shifts remaining elements
    void print() const;  // prints contents of list
    bool remove(int index);  // removes element at given index; shifts remaining elements
    dynListType *operator+(const dynListType *l) const;

  friend std::ostream &operator << (std::ostream &output, const dynListType *l) {
    int sizen = l -> getSize();
    output << "[";
    for (int i = 0; i < sizen; i++) {
      if (i == sizen - 1) {
        output << l -> at (i);
      }
      else {
        output << l -> at (i) << ", ";
      }
    }
    output << "]";
    return output;
  }

  void operator=(dynListType &obj); //overloading of assignment operator
  bool operator==(dynListType obj);  // overloading of == operator
};

#endif
