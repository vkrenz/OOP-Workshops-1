/**
 * @file Movie.cpp
 * @author Victor Krenzel (102446176)
 * @date 2023-06-18
 */

#include <sstream>
#include <iomanip>

#include "Movie.h"

namespace sdds {

	const std::string& Movie::title() const { return _title; }

	Movie::Movie(const std::string& strMovie) {
		if (!strMovie.empty()) {
			stringstream line(strMovie);
			string tempToInt{};
			getline(line, _title, ',');
			_title.erase(0, _title.find_first_not_of(' '));
			_title.erase(_title.find_last_not_of(' ') + 1);
			getline(line, tempToInt, ',');
			_year = stoi(tempToInt);
			getline(line, _des, '\n');
			_des.erase(0, _des.find_first_not_of(' '));
			_des.erase(_des.find_last_not_of(' ') + 1);
		}
		else {
			*this = Movie();
		}
	}
	
	ostream& operator<<(ostream& os, const Movie& src) {
		os << setw(40) << src._title << " | ";
		os << setw(4) << src._year << " | ";
		os << src._des << endl;
		return os;
	}

}
