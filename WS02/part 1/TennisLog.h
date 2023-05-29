#include <iostream>

#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

#include <string>

namespace sdds {

    struct TennisMatch {
        std::string m_tourney_id;
        std::string m_tourney_name;
        int m_match_id;
        std::string m_winner_name; // Winner of the match
        std::string m_loser_name; // Loser of the match

        TennisMatch():
            m_tourney_id(""),
            m_tourney_name(""),
            m_match_id(0),
            m_winner_name(""),
            m_loser_name("")
        {};

        TennisMatch(
            std::string tourneyId,
            std::string tourneyName,
            int matchId,
            std::string winnerName,
            std::string loserName
        ):
            m_tourney_id(tourneyId),
            m_tourney_name(tourneyName),
            m_match_id(matchId),
            m_winner_name(winnerName),
            m_loser_name(loserName)
        {};
    };

    class TennisLog {
    public:
        TennisMatch* m_matches = {};
        unsigned int m_match_count = 0;
        unsigned int index = 0;

        TennisLog(); // Default constructor
        TennisLog(char filename[32]);
        TennisLog(const TennisLog& src);
        TennisLog(TennisLog&& src);

        size_t len(); // return length

        void addMatch(TennisMatch& match);
        TennisLog findMatches(const std::string& playerName);

        std::string operator[](size_t);
		TennisLog& operator=(const TennisLog&);
		TennisLog& operator=(TennisLog&&);
        operator size_t();

        ~TennisLog(); // Destructor
    };

    std::ostream& operator<<(std::ostream& os, const TennisMatch& match);

}

#endif