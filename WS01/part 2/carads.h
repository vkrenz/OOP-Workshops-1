/**
 * @author Victor Krenzel - 102446176
 * @date 05/21/2023
 * 
 * I have done all the coding by myself 
 * and only copied the code that my professor 
 * provided to complete my workshops and assignments.
*/

#ifndef SDDS_CARADS_H 
#define SDDS_CARADS_H 

extern double g_taxrate;
extern double g_discount;

#include <string>

namespace sdds {

    void listArgs(int argc, char* argv[]);

    class Cars {
        char* m_brand; // C-style null-terminated string of any length
        char m_model[15];

        int m_year; // year of manufacturing
        double m_price; // price of the car
        char m_condition; // 'N' for new, 'U' for used.
        bool m_isPromotion; // is there a current promotion?
    public:
        Cars(); // Default Cars Constructor
        Cars(const Cars& other); // Copy Cars Constructor
        Cars& operator=(const Cars& other); // Assignment Operator

        void read(std::istream& is);
        void display(bool reset);

        char getStatus() const;
        double getPriceWithTax() const;
        double getSpecialPrice() const;

        void setBrandEmpty(std::string brand);
        void setCondition(char condition);
        void setModel(std::string model);
        void setYear(int year);
        void setPrice(double price);
        void setIsPromotion(bool isPromotion);

        operator bool() const; // Conversion to bool operator

        ~Cars(); // Delete m_brand mem leak
    };

    std::istream& operator>>(std::istream& is, Cars& car);
    void operator>>(const Cars& car1, Cars& car2);

}

#endif