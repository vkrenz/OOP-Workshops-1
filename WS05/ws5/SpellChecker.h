/**
 * @file SpellChecker.h
 * @author Victor Krenzel (102446176)
 * @date 2023-06-18
 */

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>

using namespace std;

const int MAX = 6;

namespace sdds {

	class SpellChecker {
		string m_badWords[MAX];
		string m_goodWords[MAX];
		int m_modifiedCounts[MAX] = {0};
	public:
		explicit SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};

}

#endif