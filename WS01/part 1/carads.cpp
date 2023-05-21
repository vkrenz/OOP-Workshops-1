/**
 * @author Victor Krenzel - 102446176
 * @date 05/19/2023
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "carads.h"

using namespace std;

double g_taxrate = 0.0;
double g_discount = 0.0;

namespace sdds {

    void listArgs(int argc, char* argv[]) {
        cout << "Command Line:" << endl;
        cout << "--------------------------" << endl;

        for (int i = 0; i < argc; i++) {
            cout << "  " <<  i + 1 << ": " << argv[i] << endl;
        }

        cout << "--------------------------" << endl;

        cout << endl;
    }

    Cars::Cars() {
        m_brand[0] = '\0';
        m_model[0] = '\0';
        m_year = 0;
        m_price = 0.0;
        m_condition = 'N';
        m_isPromotion = false;
    }

    void Cars::read(istream& is) {
        if (!is.good()) return;

        char delimiter = ',';

        // Temp values
        string brand;
        string model;

        // Read m_condition
        is.get(m_condition);
        is.ignore();

        // Read m_brand
        getline(is, brand, delimiter);
        strcpy(m_brand, brand.c_str());
        m_brand[sizeof(m_brand)-1] = '\0';

        // Read m_model
        getline(is, model, delimiter);
        strcpy(m_model, model.c_str());
        m_model[sizeof(m_model)-1] = '\0';

        // Read m_year
        is >> m_year;
        is.ignore();

        // Read m_price
        is >> m_price;
        is.ignore();

        // Read m_isPromotion
        char discountStatus;
        is >> discountStatus;
        m_isPromotion = discountStatus == 'Y' ? true : false;
        is.ignore();
    }

    void Cars::display(bool reset) {
        // Keep track of how many times the function has been called
        static int counter = 1;

        if (reset) counter = 1;

        // Print the counter value
        cout << setw(2) << left << counter << ". ";

        // Check if m_brand is empty (Print "No Car" if it is.)
        if (strlen(m_brand) == 0) { cout << "No Car" << endl; counter++; return; }

        // Print the car ad's details
        cout << setw(10) << left << m_brand << "| "
             << setw(15) << left << m_model << "| "
             << m_year << " | "
             << fixed << setprecision(2)
             << setw(11) << right << getPriceWithTax() << "|";

        // Check if the car has a special price
        m_isPromotion ? cout << setw(12) << right << getSpecialPrice() << endl : cout << endl;

        counter++;
    }

    char Cars::getStatus() const {
        return m_condition; 
    }

    double Cars::getPriceWithTax() const {
        return m_price + (m_price * g_taxrate);
    }

    double Cars::getSpecialPrice() const {
        return m_isPromotion ? getPriceWithTax() - (getPriceWithTax() * g_discount) : m_price;
    }

} // namespace sdds 