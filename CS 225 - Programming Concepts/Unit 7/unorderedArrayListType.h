// unorderedArrayListType.h
// Seperated from shell code provided with homework instructions
// By: Bin "Crystal" Peng

#ifndef UNORDEREDARRAYLISTTYPE_H
#define UNORDEREDARRAYLISTTYPE_H

#include "arrayListType.h"
#include <iostream>

class unorderedArrayListType : public arrayListType {
  public:
    void insertAt(int location, int insertItem);
    void insertEnd(int insertItem);
    void replaceAt(int location, int repItem);
    int seqSearch(int searchItem) const;
    void remove(int removeItem);
    unorderedArrayListType(int size = 100); //Constructor
};

#endif
