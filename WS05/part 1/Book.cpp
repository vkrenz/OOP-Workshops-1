#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

#include "Book.h"

using namespace std;

namespace sdds {

    Book::Book():
        m_author(""),
        m_title(""),
        m_country(""),
        m_year(0),
        m_price(0.0),
        m_description("")
    {}

    const std::string& Book::title() const {
        return m_title;
    }

    const std::string& Book::country() const {
        return m_country;
    }

    const size_t& Book::year() const {
        return m_year;
    }

    double& Book::price() {
        // Todo: Allow `m_price` to be mutable by client
        return m_price;
    }

    Book::Book(const std::string& strBook) {
        // Remove whitespace from beginning and end of each token
        std::istringstream iss(strBook);
        std::istream_iterator<std::string> begin(iss), end;
        std::vector<std::string> tokens(begin, end);

        std::for_each(tokens.begin(), tokens.end(), [](std::string& token) {
            token.erase(token.begin(), std::find_if());
        });
    }

} // namespace sdds