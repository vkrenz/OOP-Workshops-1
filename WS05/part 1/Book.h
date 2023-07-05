#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>

namespace sdds {

    class Book {
        std::string m_author;
        std::string m_title;
        std::string m_country; // Country of publication
        size_t m_year;
        double m_price;
        std::string m_description;
    public:
        Book();

        // a query that returns the title of the book
        const std::string& title() const;

        // a query that returns the publication country
        const std::string& country() const;

        // a query that returns the publication year
        const size_t& year() const;

        // a function that returns the price by reference, allowing the client code to update the price
        double& price();

        // a constructor that receives a reference to an unmodifiable string that contains information about
        // the book; this constructor extracts the information about the book from the string by parsing 
        // it and stores the tokens in the object's attributes. The string always has the following format:
        //
        // AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
        //
        // This constructor should remove all spaces from the beginning and end of any token in the string.
        Book(const std::string& strBook);
    };

} // namespace sdds 

#endif // SDDS_BOOK_H