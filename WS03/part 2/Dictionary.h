/**
 * @file Dictionary.h
 * @author Victor Krenzel - 102446176
 * @date 2023-06-04
 */

#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H
#include <iostream>
#include <string>

namespace sdds {

    class Dictionary {
        std::string m_Term{};
        std::string m_Definition{};
    public:
        const std::string& getTerm() const{
            return m_Term;
        }

        const std::string& getDefinition() const{
            return m_Definition;
        }

        Dictionary(const std::string Term, const std::string Definition) : m_Term{ Term }, m_Definition{ Definition }{};

        static bool haveSameTerm(const Dictionary& P, const Dictionary& N);

        Dictionary() : m_Term{ "" }, m_Definition{ "" }{ };

        virtual std::ostream& display(std::ostream& ostr = std::cout) const;

        bool operator==(const Dictionary& dis)const {
            return m_Term == dis.getTerm();
        }
    };

    std::ostream& operator<<(std::ostream& ostr, const Dictionary& P);

}

#endif // DICTIONARY_H