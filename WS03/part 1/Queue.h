#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H
#include <iostream>
#include "Dictionary.h"
#include <string>
namespace sdds {

template<typename T, size_t CAPACITY>
class Queue {

protected:
  T array[CAPACITY];
  size_t numOfElements{0};
  T dummy{};

public:

  Queue(){}

  virtual ~Queue() {}

  size_t size() const
  {
  return numOfElements;
  }

  void display(std::ostream& ostr = std::cout)const 
  {
  ostr << "----------------------" << std::endl;
  ostr << "|" << " Dictionary  Content " << "|" << std::endl;
  ostr << "----------------------" << std::endl;
  for (size_t i = 0; i < numOfElements; i++) {
    ostr << array[i] << std::endl;
  }
  ostr << "----------------------" << std::endl;
  }

  virtual bool push(const T& item) 
  {
  bool res = false;
  if (numOfElements < CAPACITY) {
    array[numOfElements] = item;
    numOfElements++;
    res = true;
  }
  return res;
  }

  T& operator[](int index) 
  {
  if (index >= 0 && index < numOfElements) {
    return array[index];
  }
  return dummy;
  }

};

}
#endif // !