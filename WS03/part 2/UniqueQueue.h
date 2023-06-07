/**
 * @file UniqueQueue.h
 * @author Victor Krenzel - 102446176
 * @date 2023-06-04
 */

#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H
#include <iostream>
#include <cmath>
#include <string>

#include "Dictionary.h"
#include "Queue.h"

namespace sdds {

    template<class T>
    class UniqueQueue : public Queue<T,100>{
        const size_t CAPACITY = 100;
    public:
        UniqueQueue(){;}

        bool push(const T& item) {
            for(size_t i=0;i < this->numOfElements; i++) {
                if(item == this->array[i]) return false;
            }
            return Queue<T,100>::push(item);
        }


        T pop() {   
            T tmp=this->array[0];
            for(size_t i=0;i< this->numOfElements - 1 ;  i++) this->array[i] = this->array[i+1];
            this->numOfElements--;
            return tmp;
        }


    };



    template<>
    bool UniqueQueue<double>::push(const double& item) {
        for(size_t i=0;i< this->numOfElements; i++) {
            if( std::fabs(item - this->array[i]) <= 0.005 ) return false;
        }
        return Queue<double,100>::push(item);
    };


}
#endif // !