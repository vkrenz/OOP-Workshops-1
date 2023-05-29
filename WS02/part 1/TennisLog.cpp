#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>
#include "TennisLog.h"

using namespace std;

namespace sdds {

    // Constructors  

    TennisLog::TennisLog()
    {};

    TennisLog::TennisLog(char filename[32]):
        m_matches(nullptr),
        m_match_count(-1)
    {
        ifstream file(filename);

        if (!file) return;

        string line, name;

        while (getline(file, line)) {
            m_match_count++;
        }

        file.close();

        ifstream f(filename);
        getline(f, line);

        m_matches = new TennisMatch[m_match_count];

        unsigned int i = 0;
        char delimiter = ',';

        while (i < m_match_count) {
            getline(f, m_matches[i].m_tourney_id, delimiter);
            getline(f, m_matches[i].m_tourney_name, delimiter);

            string matchId;
            getline(f, matchId, delimiter);
            m_matches[i].m_match_id = stoi(matchId);

            getline(f, m_matches[i].m_winner_name, delimiter);
            getline(f, m_matches[i].m_loser_name);

            i++;
        }

        f.close();
    };

    TennisLog::TennisLog(TennisLog&& old) {
        *this = move(old);
    }

    TennisLog::TennisLog(const TennisLog& old) {
        *this = old;
    }

    // Operator Overload

    TennisLog& TennisLog::operator=(TennisLog&& src) {
        if (this != &src) {
            delete[] m_matches;
            m_matches = nullptr;

            m_matches = src.m_matches;

            src.m_matches = nullptr;
            m_match_count = src.m_match_count;
            src.m_match_count = 0;
        }

        return *this;
    }

    TennisLog& TennisLog::operator =(const TennisLog& src) {
        if (this != &src) {
            delete[] m_matches;
            m_matches = nullptr;
            m_match_count = src.m_match_count;

            m_matches = new TennisMatch[m_match_count] {};

            for (unsigned int i = 0; i < m_match_count; i++) {
                m_matches[i] = src.m_matches[i];
            }

            // m_matches->m_tourney_id = src.m_matches->m_match_id;
            // m_matches->m_tourney_name = src.m_matches->m_tourney_name;
            // m_matches->m_match_id = src.m_matches->m_match_id;
            // m_matches->m_winner_name = src.m_matches->m_winner_name;
            // m_matches->m_loser_name = src.m_matches->m_loser_name;

        }

        return *this;
    }

    // Public Functions

    void TennisLog::addMatch(TennisMatch& match) {
        m_match_count++;

        TennisMatch *newMatch = new TennisMatch[m_match_count] {};

        for (unsigned int i = 0; i < m_match_count - 1; i++) {
            newMatch[i] = m_matches[i];
        }

        newMatch[m_match_count - 1] = match;
        delete[] m_matches;
        m_matches = newMatch;
    };

    TennisLog TennisLog::findMatches(const string& playerName) {
        // Create a new TennisLog object to match `m_matches`
        TennisLog tL;

        for (size_t i = 0; i < m_match_count; i++) {

            // Check if `playerName` matches `m_winner_name` or `m_loser_name`
            if (m_matches[i].m_winner_name == playerName || m_matches[i].m_loser_name == playerName) {
                tL.addMatch(m_matches[i]);
            }
        }

        return tL;
    };

    TennisLog::~TennisLog() {
        delete[] m_matches;
    };

    string TennisLog::operator[](size_t index) {
        string res = "";

        if (index < m_match_count) {
            string str = "..........Tourney ID : ";
            str += m_matches[index].m_tourney_id;
            for (int i = m_matches[index].m_tourney_id.length(); i < 30; i++) str += '.';
            str += '\n';
            res += str;

            str = "............Match ID : ";
            str += to_string(m_matches[index].m_match_id);
            for (int i = to_string(m_matches[index].m_match_id).length(); i< 30; i++) str += '.';
            str += '\n';
            res += str;

            str = ".............Tourney : ";
            str += m_matches[index].m_tourney_name;
            for (int i = m_matches[index].m_tourney_name.length(); i< 30; i++) str += '.';
            str += '\n';
            res += str;

            str = "..............Winner : ";
            str += m_matches[index].m_winner_name;
            for (int i = m_matches[index].m_winner_name.length(); i < 30; i++) str += '.';
            str += '\n';
            res += str;

            str = "...............Loser : ";
            str += m_matches[index].m_loser_name;
            for (int i = m_matches[index].m_loser_name.length(); i < 30; i++) str += '.';
            str += '\n';
            res += str;

            return res;
        }

        return "Empty Match";
    }

    TennisLog::operator size_t() {
        return m_match_count;
    }

} // namespace sdds 