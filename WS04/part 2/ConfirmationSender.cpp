/**
 * @file ConfirmationSender.cpp
 * @author Victor Krenzel 102446176
 * @date 2023-06-11
 */

#include "ConfirmationSender.h"

namespace sdds {

    ConfirmationSender::ConfirmationSender() { m_reservations = nullptr; m_cnt = 0; }

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& other) {
        m_reservations = new const Reservation*[other.m_cnt];
        m_cnt = other.m_cnt;

        for (size_t i = 0; i < m_cnt; i++) { m_reservations[i] = other.m_reservations[i]; }
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& other) {
        m_reservations = other.m_reservations;
        m_cnt = other.m_cnt;

        other.m_reservations = nullptr;
        other.m_cnt = 0;
    }

    ConfirmationSender::~ConfirmationSender() {
        delete[] m_reservations;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
        bool exists = false;

        for (size_t i = 0; i < m_cnt; i++) {
            if (m_reservations[i] == &res) { exists = true; break; }
        }

        if (!exists) {
            const Reservation** temp = new const Reservation*[m_cnt + 1];

            for (size_t i = 0; i < m_cnt; i++) temp[i] = m_reservations[i];

            temp[m_cnt] = &res;

            delete[] m_reservations;
            m_reservations = temp;
            m_cnt++;
        }

        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        for (size_t i = 0; i < m_cnt; i++) {
            if (m_reservations[i] == &res) {
                const Reservation** temp = new const Reservation*[m_cnt - 1];

                size_t idx = 0;

                for (size_t j = 0; j < m_cnt; j++) if (j != i) { temp[idx] = m_reservations[j]; idx++; }

                delete[] m_reservations;
                m_reservations = temp;
                m_cnt--;

                break;
            }
        }

        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender) {
        os << "--------------------------\n";
        os << "Confirmations to Send\n";
        os << "--------------------------\n";

        if (sender.m_cnt == 0) {
            os << "There are no confirmations to send!\n";
        } else {
            for (size_t i = 0; i < sender.m_cnt; i++) os << *sender.m_reservations[i] << "";
        }

        os << "--------------------------\n";

        return os;
    }



    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other) {
        if (this != &other) {
            delete[] m_reservations;

            m_reservations = new const Reservation*[other.m_cnt];
            m_cnt = other.m_cnt;

            for (size_t i = 0; i < m_cnt; i++) m_reservations[i] = other.m_reservations[i];
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other) {
        if (this != &other) {
            delete[] m_reservations;

            m_reservations = other.m_reservations;
            m_cnt = other.m_cnt;

            other.m_reservations = nullptr;
            other.m_cnt = 0;
        }
        return *this;
    }


}
