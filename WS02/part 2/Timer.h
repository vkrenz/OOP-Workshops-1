/**
 * @file Timer.h
 * @author Victor Krenzel - 102446176
 * @date 2023-05-28
 */

#include <iostream>
#include <chrono>

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

namespace sdds {
    const int MAX = 10;

    struct TennisMatches {
        std::string taskName;
        std::string units;
        std::chrono::steady_clock::duration duration;
    };

    class Timer {
    public:
        std::chrono::steady_clock::time_point Start_Time_;
        std::chrono::steady_clock::time_point End_Time_;

        TennisMatches tennisMatches;

        TennisMatches T_Taskk[MAX];
        int T_R_ecords = 0;

        friend std::ostream& operator<<(std::ostream& os, const Timer& tasks);
        
        long start();
        long stop();

        void addTask(std::string name);
    };

}

#endif