// arrayListType.h
// Seperated from shell code provided with homework instructions
// By: Bin "Crystal" Peng

#ifndef ARRAYLISTTYPE_H
#define ARRAYLISTTYPE_H

#include <iostream>

class arrayListType {
  friend std::ostream &operator<<(std::ostream &, const arrayListType &);

  public:
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const;
    int maxListSize() const;
    bool isItemAtEqual(int location, int item) const;
    void removeAt(int location);
    void retrieveAt(int location, int &retItem) const;
    void clearList();
    virtual int seqSearch(int searchItem) const = 0;
    virtual void insertAt(int location, int insertItem) = 0;
    virtual void insertEnd(int insertItem) = 0;
    virtual void replaceAt(int location, int repItem) = 0;
    virtual void remove(int removeItem) = 0;
    arrayListType(int size = 100);
    arrayListType(const arrayListType &otherList);
    virtual ~arrayListType();

  protected:
    int *list;  // array to hold the list elements
    int length;  // length of the list
    int maxSize;  // the maximum size of the list
};

#endif
