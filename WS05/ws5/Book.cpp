/**
 * @file Book.cpp
 * @author Victor Krenzel (102446176)
 * @date 2023-06-18
 */

#include <iomanip>
#include <sstream>

#include "Book.h"

namespace sdds {

	const string& Book::title() const { return _title; }

	const std::string& Book::country() const { return _country; }

	const size_t& Book::year() const { return _year; }

	double& Book::price() { return _price; }

	Book::Book(const std::string& strBook) {
		stringstream line(strBook);
		string tempToInt{};
		getline(line, _author, ',');
		_author.erase(0, _author.find_first_not_of(' '));
		_author.erase(_author.find_last_not_of(' ') + 1);
		getline(line, _title, ',');
		_title.erase(0, _title.find_first_not_of(' '));
		_title.erase(_title.find_last_not_of(' ') + 1);
		getline(line, _country, ',');
		_country.erase(0, _country.find_first_not_of(' '));
		_country.erase(_country.find_last_not_of(' ') + 1);
		getline(line, tempToInt, ',');
		_price = stod(tempToInt);
		getline(line, tempToInt, ',');
		_year = stoi(tempToInt);
		getline(line, _des, '\n');
		_des.erase(0, _des.find_first_not_of(' '));
		_des.erase(_des.find_last_not_of(' ') + 1);
	}

	ostream& operator<<(ostream& os, Book& src) {
		os << setw(20) << src._author << " | ";
		os << setw(22) << src.title() << " | ";
		os << setw(5) << src.country() << " | ";
		os << setw(4) << src.year() << " | ";
		os << setw(6) << fixed << setprecision(2) << src.price() << " | ";
		os << src._des << endl;

		return os;
	}

	Book& Book::operator=(const Book& src) {
		if (this != &src) {
			_author = src._author;
			_title = src._title;
			_country = src._country;
			_year = src._year;
			_price = src._price;
			_des = src._des;
		}
		
		return *this;
	}

	Book::Book(const Book& src) { *this = src; }
}