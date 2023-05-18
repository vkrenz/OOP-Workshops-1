#include <iostream>
#include <cstring>
#include <iomanip>
#include "./headers/carads.h"
using namespace std;

namespace sdds {

    void listArgs(int argc, char* argv[]) {
        cout << "Command Line: " << endl;
        cout << "--------------------------" << endl;

        for (int i = 0; i < argc; i++) {
            cout << i + 1 << ": " << argv[i] << endl;
        }
    }

    Cars::Cars() {
        m_brand[0] = '\0';
        m_model[0] = '\0';
        m_year = 0;
        m_price = 0.0;
        m_condition = '\0';
        m_isPromotion = false;
    }

    void Cars::read(istream& is) {
        if (!is.good()) return;

        char orderTag, brand[10], model[15];
        int year;
        double price;
        char discountStatus;

        if (is >> orderTag
               >> brand
               >> model
               >> year
               >> price
               >> discountStatus) 
        {
            m_condition = orderTag;
            strcpy(m_brand, brand);
            strcpy(m_model, model);
            m_year = year;
            m_price = price;
            m_isPromotion = (discountStatus == 'Y');
        }
    }

    void Cars::display(bool reset) {
        // Keep track of how many times the function has been called
        static int counter = 1;

        if (reset) counter = 1;

        // Print the counter value
        cout << setw(2) << left << counter << '. ';

        // Check if m_brand is empty (Print "No Car" if it is.)
        if (strlen(m_brand) != 0) { cout << "No Car" << endl; return; }

        // Print the car ad's details
        cout << setw(10) << left << m_brand << '| '
             << setw(15) << left << m_model << '| '
             << m_year << '| '
             << fixed << setprecision(2)
             << setw(12) << left << getPriceWithTax() << '| ';

        // Check if the cat has a special price
        // If yes, print out the special price
        if (m_isPromotion == 'Y') cout << setw(12) << right << getSpecialPrice();


    }

    char Cars::getStatus() const {
        if (!m_condition) return;

        return m_condition;
    }

    double Cars::getPriceWithTax() const {
        return m_price * g_taxrate;
    }

    double Cars::getSpecialPrice() const {
        return m_price * (1 - g_discount);
    }

} // namespace sdds 