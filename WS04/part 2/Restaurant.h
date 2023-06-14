/**
 * @file Restaurant.h
 * @author Victor Krenzel 102446176
 * @date 2023-06-11
 */

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Reservation.h"

namespace sdds {
    
    class Restaurant {
        Reservation** m_reservations;
        size_t m_cnt;

    public:
        Restaurant(const Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant& other);
        Restaurant(Restaurant&& other);
        Restaurant& operator=(const Restaurant& other);
        Restaurant& operator=(Restaurant&& other);
        ~Restaurant();

        size_t size() const;

        friend std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant);
    };
}

#endif // RESTAURANT_H
