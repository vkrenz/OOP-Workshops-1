/**
 * @file SpellChecker.cpp
 * @author Victor Krenzel (102446176)
 * @date 2023-06-18
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "SpellChecker.h"

using namespace std;

namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		else {
			string temp;
			size_t i = 0;
			while (file && i < MAX) {
				getline(file, m_badWords[i], ' '); 
				m_badWords[i].erase(0, m_badWords[i].find_first_not_of(' '));
				m_badWords[i].erase(m_badWords[i].find_last_not_of(' ') + 1);
				getline(file, m_goodWords[i], '\n');
				m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(' '));
				m_goodWords[i].erase(m_goodWords[i].find_last_not_of(' ') + 1);
				i++;
				
			}
			file.close();
		}
	}

	void SpellChecker::operator()(std::string& text) {
		for (int i = 0; i < MAX; ++i) {
			while (text.find(m_badWords[i]) != string::npos) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].size(),
					m_goodWords[i]);
					m_modifiedCounts[i]++;					
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
		std::cout << "Spellchecker Statistics" << std::endl;
			for (int i = 0; i < MAX; i++)
				cout << setw(15) << right << m_badWords[i] << ": " <<
				m_modifiedCounts[i] << " replacements" << endl;
	}

}