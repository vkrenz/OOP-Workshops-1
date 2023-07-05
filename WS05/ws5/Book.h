/**
 * @file Book.h
 * @author Victor Krenzel (102446176)
 * @date 2023-06-18
 */

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>

#include "SpellChecker.h"

using namespace std;

namespace sdds {

	class Book {
		string _author{};
		string _title{};
		string _country{};
		size_t _year{};
		double _price{};
		string _des{};
	public:
		Book() = default;
		Book(const Book& src);
		Book& operator=(const Book& src);
		const string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		
		explicit Book(const std::string& strBook);
		template <typename T>
		void fixSpelling(T &spellChecker) { spellChecker(_des); }
		
		friend ostream& operator <<(ostream& os, Book& src);
	};

}

#endif
