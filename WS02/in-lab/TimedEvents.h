// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: Sept 24, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef TimedEvents_h
#define TimedEvents_h

#include <iostream>
#include <chrono>
#include <string>

using namespace std;
namespace sdds {
    const int MAX_RECORDS = 7;

    class TimedEvents {
        int nr = 0;
        std::chrono::steady_clock::time_point ts;
        std::chrono::steady_clock::time_point te;
        struct {
            std::string msg;
            std::string units;
            std::chrono::steady_clock::duration duration;
        } events[MAX_RECORDS];
    public:
        void startClock();
        void stopClock();
        void recordEvent(const char*);
        friend std::ostream& operator<<(std::ostream& out, const TimedEvents& events);
    };

}


#endif /* TimedEvents_h */
