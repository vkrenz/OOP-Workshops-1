/**
 * @file Movie.h
 * @author Victor Krenzel (102446176)
 * @date 2023-06-18
 */

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <string>

#include "SpellChecker.h"

using namespace std;

namespace sdds {

	class Movie {
		string _title{};
		size_t _year{};
		string _des{};
	public:
		Movie() = default;
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template <typename T>
		void fixSpelling(T &spellChecker) {
			spellChecker(_title);
			spellChecker(_des);
		}
		friend ostream& operator <<(ostream& os, const Movie& src);
	};

}
#endif
