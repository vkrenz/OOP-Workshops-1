/**
 * @file ConfirmationSender.h
 * @author Victor Krenzel 102446176
 * @date 2023-06-11
 */

#ifndef CONFIRMATIONSENDER_H
#define CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds {

    class ConfirmationSender {
        const Reservation** m_reservations;
        size_t m_cnt;
    public:
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& other);
        ConfirmationSender(ConfirmationSender&& other);
        ~ConfirmationSender();

        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);

        friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender);
    
        ConfirmationSender& operator=(const ConfirmationSender& other);
        ConfirmationSender& operator=(ConfirmationSender&& other);
    };
    
}

#endif // CONFIRMATIONSENDER_H
