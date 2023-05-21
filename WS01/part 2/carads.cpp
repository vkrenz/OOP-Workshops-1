/**
 * @author Victor Krenzel - 102446176
 * @date 05/21/2023
 * 
 * I have done all the coding by myself 
 * and only copied the code that my professor 
 * provided to complete my workshops and assignments.
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

    Cars::Cars():
        m_brand(nullptr),
        m_year(0),
        m_price(0.0),
        m_condition('\0'),
        m_isPromotion(false) 
    {
        m_brand = new char[1];
        m_brand[0] = '\0';
        m_model[0] = '\0';
    }

    Cars::Cars(const Cars& other):
        m_brand(nullptr),
        m_year(other.m_year),
        m_price(other.m_price),
        m_condition(other.m_condition),
        m_isPromotion(other.m_isPromotion)
    {
        strcpy(m_model, other.m_model);

        if (other.m_brand) {
            m_brand = new char[strlen(other.m_brand) + 1];
            strcpy(m_brand, other.m_brand);
        }
    }

    Cars& Cars::operator=(const Cars& other) {
        if (this != &other) {
            delete[] m_brand;
            m_brand = nullptr;

            m_year = other.m_year;
            m_price = other.m_price;
            m_condition = other.m_condition;
            m_isPromotion = other.m_isPromotion;

            strcpy(m_model, other.m_model);

            if (other.m_brand) {
                m_brand = new char[strlen(other.m_brand) + 1];
                strcpy(m_brand, other.m_brand);
            }
        }

        return *this;
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
        delete[] m_brand;
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

    Cars::operator bool() const {
        return m_condition == 'N';
    }


    // A bunch of setters 
    void Cars::setBrandEmpty(string brand) {
        delete[] m_brand;
        m_brand = new char[brand.length() + 1];
        strcpy(m_brand, brand.c_str());
    }
    void Cars::setCondition(char condition) { m_condition = condition; }
    void Cars::setModel(string model) { strcpy(m_model, model.c_str()); }
    void Cars::setYear(int year) { m_year = year; }
    void Cars::setPrice(double price) { m_price = price; }
    void Cars::setIsPromotion(bool isPromotion) { m_isPromotion = isPromotion; }

    Cars::~Cars() {
        delete[] m_brand;
    }

    // Does same thing as void Cars::read(istream& is);
    istream& operator>>(istream& is, Cars& car) {
        char delimiter = ',';

        // Temp values
        char condition;
        string brand;
        string model;
        int year;
        double price;
        char discountStatus;

        // Read m_condition
        is >> condition;
        car.setCondition(condition);
        is.ignore();

        // Read m_brand
        getline(is, brand, delimiter);
        car.setBrandEmpty(brand);

        // Read m_model
        getline(is, model, delimiter);
        car.setModel(model);

        // Read m_year
        is >> year;
        car.setYear(year);
        is.ignore();

        // Read m_price
        is >> price;
        car.setPrice(price);
        is.ignore();

        // Read m_isPromotion
        is >> discountStatus;
        car.setIsPromotion(discountStatus == 'Y' ? true : false);
        is.ignore();

        return is;
    }

    void operator>>(const Cars& car1, Cars& car2) {
        car2 = car1;
    }

} // namespace sdds 