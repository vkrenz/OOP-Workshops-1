/**
 * @file Reservation.cpp
 * @author Victor Krenzel 102446176
 * @date 2023-06-11
 */

#include "Reservation.h"
#include <iomanip>
#include <sstream>

namespace sdds {
    Reservation::Reservation():
        partySize(0), 
        day(0), 
        hour(0) 
    {}

    Reservation::Reservation(const std::string& res) {
        std::istringstream iss(res);
        std::string token;
        std::getline(iss, reservationId, ':');
        std::getline(iss, name, ',');
        std::getline(iss, email, ',');
        std::getline(iss, token, ',');
        partySize = std::stoi(token);
        std::getline(iss, token, ',');
        day = std::stoi(token);
        std::getline(iss, token);
        hour = std::stoi(token);
        trim();
    }

    void Reservation::update(int newDay, int newHour) {
        day = newDay;
        hour = newHour;
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& res) {
        std::string meal;
        if (res.hour >= 6 && res.hour <= 9) meal = "Breakfast";
        else if (res.hour >= 11 && res.hour <= 15) meal = "Lunch";
        else if (res.hour >= 17 && res.hour <= 21) meal = "Dinner";
        else meal = "Drinks";

        os << "Reservation " << std::setw(10) << std::right << res.reservationId;
        os << ": " << std::setw(20) << std::right << res.name;
        os << "  <" << std::setw(20) << std::left << res.email + ">";
        os << "   " << meal << " on day " << res.day << " @ " << res.hour << ":00 for ";
        os << res.partySize << " pe" << (res.partySize == 1 ? "rson." : "ople.");
        os << std::endl;
        return os;
    }

    void Reservation::trim() {
        size_t pos = reservationId.find_first_not_of(' ');
        if (pos != std::string::npos) reservationId.erase(0, pos);

        pos = reservationId.find_last_not_of(' ');
        if (pos != std::string::npos) reservationId.erase(pos + 1);

        pos = name.find_first_not_of(' ');
        if (pos != std::string::npos) name.erase(0, pos);

        pos = name.find_last_not_of(' ');
        if (pos != std::string::npos) name.erase(pos + 1);

        pos = email.find_first_not_of(' ');
        if (pos != std::string::npos) email.erase(0, pos);

        pos = email.find_last_not_of(' ');
        if (pos != std::string::npos) email.erase(pos + 1);
    }
}
