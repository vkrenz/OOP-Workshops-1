/**
 * @file Reservation.h
 * @author Victor Krenzel 102446176
 * @date 2023-06-11
 */

#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>

namespace sdds {

    class Reservation {
        std::string reservationId;
        std::string name;
        std::string email;
        int partySize;
        int day;
        int hour;

        void trim();
    public:
        Reservation();
        Reservation(const std::string& res);
        void update(int newDay, int newHour);
        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };

}

#endif // RESERVATION_H
