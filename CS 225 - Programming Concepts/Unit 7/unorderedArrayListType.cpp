// unorderedArrayListType.cpp
// Seperated from shell code provided with homework instructions
// By: Bin "Crystal" Peng


#include "unorderedArrayListType.h"
#include <iostream>

void unorderedArrayListType::insertAt(int location,
  int insertItem)
{
  if (location < 0 || location >= maxSize)
    std::cout << "The position of the item to be inserted "
    << "is out of range.\n";
  else if (length >= maxSize)  //list is full
    std::cout << "Cannot insert in a full list\n";
  else
  {
    for (int i = length; i > location; i--)
      list[i] = list[i - 1];  //move the elements down

    list[location] = insertItem; //insert the item at
    //the specified position

    length++; //increment the length
  }
} //end insertAt

void unorderedArrayListType::insertEnd(int insertItem)
{
  if (length >= maxSize)  //the list is full
    std::cout << "Cannot insert in a full list.\n";
  else
  {
    list[length] = insertItem; //insert the item at the end
    length++; //increment the length
  }
} //end insertEnd

int unorderedArrayListType::seqSearch(int searchItem) const
{
  for (int loc = 0; loc < length; loc++)
  if (list[loc] == searchItem)
    return loc;

  return -1; // not found
} //end seqSearch

void unorderedArrayListType::remove(int removeItem)
{
  if (length == 0)
    std::cout << "Cannot delete from an empty list.\n";
  else
  {
    int loc = seqSearch(removeItem);

    if (loc != -1)
      removeAt(loc);
    else
      std::cout << "The item to be deleted is not in the list\n.";
  }
} //end remove

void unorderedArrayListType::replaceAt(int location, int repItem)
{
  if (location < 0 || location >= length)
    std::cout << "The location of the item to be "
    << "replaced is out of range.\n";
  else
    list[location] = repItem;
} //end replaceAt

unorderedArrayListType::unorderedArrayListType(int size)
: arrayListType(size)
{
  //std::cout << "constructor of unorderedalt: " << this << "\n"; // testing
}  //end constructor
