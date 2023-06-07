/**
 * @file Dictionary.cpp
 * @author Victor Krenzel - 102446176
 * @date 2023-06-04
 */

#include "Dictionary.h"

using namespace std;

namespace sdds {

    bool Dictionary::haveSameTerm(const Dictionary& D, const Dictionary& N) {
        bool res = false;
        if (D.m_Term == N.m_Term) {
            res = true;
        }
        return res;
    }

    std::ostream& Dictionary::display(std::ostream& ostr) const {
        ostr.width(20);
        ostr.setf(ios::right);
        ostr << getTerm();
        ostr.setf(ios::left);
        ostr << ": " << getDefinition();
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Dictionary& P) {
        return P.display(ostr);
    }

} // namespace sdds