/**
 * @file Restaurant.cpp
 * @author Victor Krenzel 102446176
 * @date 2023-06-11
 */

#include "Restaurant.h"

namespace sdds {

    size_t COUNT = 1;

    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
        m_reservations = new Reservation*[cnt];
        m_cnt = cnt;

        for (size_t i = 0; i < cnt; i++) m_reservations[i] = new Reservation(*reservations[i]);
    }

    Restaurant::Restaurant(const Restaurant& other) {
        m_reservations = new Reservation*[other.m_cnt];
        m_cnt = other.m_cnt;

        for (size_t i = 0; i < m_cnt; i++) m_reservations[i] = new Reservation(*other.m_reservations[i]);
    }

    Restaurant::Restaurant(Restaurant&& other) {
        m_reservations = other.m_reservations;
        m_cnt = other.m_cnt;

        other.m_reservations = nullptr;
        other.m_cnt = 0;
    }

    Restaurant::~Restaurant() {
        for (size_t i = 0; i < m_cnt; i++) delete m_reservations[i];

        delete[] m_reservations;
    }

    size_t Restaurant::size() const {
        return m_cnt;
    }

    std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant) {
        os << "--------------------------\n";
        os << "Fancy Restaurant ("<<COUNT++<<")\n";
        os << "--------------------------\n";

        if (restaurant.m_cnt == 0) os << "This restaurant is empty!\n";
        else for (size_t i = 0; i < restaurant.m_cnt; i++) os << *restaurant.m_reservations[i] << "";

        os << "--------------------------\n";

        return os;
    }


    Restaurant& Restaurant::operator=(const Restaurant& other) {
        if (this != &other) {
            for (size_t i = 0; i < m_cnt; i++) delete m_reservations[i];

            delete[] m_reservations;

            m_reservations = new Reservation*[other.m_cnt];
            m_cnt = other.m_cnt;

            for (size_t i = 0; i < m_cnt; i++) m_reservations[i] = new Reservation(*other.m_reservations[i]);
        }
        return *this;
    }

    Restaurant& Restaurant::operator=(Restaurant&& other) {
        if (this != &other) {
            for (size_t i = 0; i < m_cnt; i++) delete m_reservations[i];
            
            delete[] m_reservations;

            m_reservations = other.m_reservations;
            m_cnt = other.m_cnt;

            other.m_reservations = nullptr;
            other.m_cnt = 0;
        }
        
        return *this;
    }


}
