#ifndef SDDS_CARADS_H 
#define SDDS_CARADS_H 

extern double g_taxrate;
extern double g_discount;

namespace sdds {

    void listArgs(int argc, char* argv[]);

    class Cars {
        char m_brand[10];
        char m_model[15];
        int m_year; // year of manufacturing
        double m_price; // price of the car
        char m_condition; // 'N' for new, 'U' for used.
        bool m_isPromotion; // is there a current promotion?
    public:
        Cars();
        void read(std::istream& is);
        void display(bool reset);
        char getStatus() const;
        double getPriceWithTax() const;
        double getSpecialPrice() const;
    };

}

#endif