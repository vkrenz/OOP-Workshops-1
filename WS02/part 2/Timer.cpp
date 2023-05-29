#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
/**
 * @file Timer.cpp
 * @author Victor Krenzel - 102446176
 * @date 2023-05-28
 */

#include <ratio>
#include <chrono>

#include "Timer.h"

using namespace std;

namespace sdds {

    long Timer::start() {
        chrono::system_clock::time_point tP = chrono::system_clock::now();
        return tP.time_since_epoch().count();
    }

    long Timer::stop() {
        chrono::system_clock::time_point tP = chrono::system_clock::now();
        return tP.time_since_epoch().count();       
    }

    ostream& operator<<(ostream& os, const Timer& tasks) {
        os  << "--------------------------" << endl
            << "Execution Times:" << endl
            << "--------------------------" << endl;

        for (int i = 0; i < tasks.T_R_ecords; i++) {
            os << std::setw(21) << left << tasks.T_Taskk[i].taskName << " ";
            os << std::setw(13) << right << tasks.T_Taskk[i].duration.count() << " " 
               << tasks.T_Taskk[i].units << endl;
        }

        os << "--------------------------" << endl;

        return os;
    }

    void Timer::addTask(string name) {
        T_Taskk[T_R_ecords].taskName = name;
        T_Taskk[T_R_ecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(End_Time_ - Start_Time_);
        T_Taskk[T_R_ecords].units = "nanoseconds";

        T_R_ecords++;
    }

}