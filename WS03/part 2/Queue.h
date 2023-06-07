/**
 * @file Queue.h
 * @author Victor Krenzel - 102446176
 * @date 2023-06-04
 */

#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H
#include <iostream>
#include <string>

#include "Dictionary.h"

namespace sdds {

  template<typename T, size_t CAPACITY>
  class Queue {
  protected:
    T array[CAPACITY];
    size_t numOfElements{0};
    T dummy{};
    Dictionary d;
  public:
  Queue():d("Empty Term","Empty Substitute"){}

  virtual ~Queue() {}

  size_t size() const {
    return numOfElements;
  }

  void display(std::ostream& ostr = std::cout) const {
    ostr << "----------------------" << std::endl;
    ostr << "|" << " Dictionary Content " << "|" << std::endl;
    ostr << "----------------------" << std::endl;
    for (size_t i = 0; i < numOfElements; i++) ostr << array[i] << std::endl;
    ostr << "----------------------" << std::endl;
  }

  virtual bool push(const T& item) {
    bool res = false;
    if (numOfElements < CAPACITY) {
      array[numOfElements] = item;
      numOfElements++;
      res = true;
    }
    return res;
  }

  virtual T pop() 
  {
      T tmp=this->array[0];
      for(size_t i=0;i< this->numOfElements - 1 ;  i++) this->array[i] = this->array[i+1];

      this->numOfElements--;

      return tmp;
  }

  T& operator[](size_t index) {
    if (index >= 0 && index < numOfElements) return array[index];
    return dummy;
  }

  };


  template<>
  Dictionary& Queue<Dictionary,100>::operator[](size_t index) 
  {
    if (index >= 0 && index < this->numOfElements) return this->array[index];
    return this->d;
  }

}
#endif // QUEUE_H