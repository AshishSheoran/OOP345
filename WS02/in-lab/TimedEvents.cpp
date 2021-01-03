// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: Sept 24, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include "TimedEvents.h"

namespace sdds {
    void TimedEvents::startClock() {
        ts = std::chrono::steady_clock::now();
    }


    void TimedEvents::stopClock() {
        te = std::chrono::steady_clock::now();
    }


    void TimedEvents::recordEvent( const char* msg) {
        auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(te - ts);
        if( nr < MAX_RECORDS) {
            this->events[nr].msg = msg;
            this->events[nr].units = "nanoseconds";
            this->events[nr].duration = ms;
            nr++;
        }
    }

    
    std::ostream& operator<<(std::ostream& out, const TimedEvents& events) {
        out << "--------------------------\n";
        out << "Execution Times:\n";
        out << "--------------------------\n";
        for(int i = 0; i < events.nr; i++)
            out << std::setw(20) << std::left
                << events.events[i].msg << ' ' << std::setw(12) << std::right
                << events.events[i].duration.count() << ' '
                << events.events[i].units << '\n';
        out << "--------------------------\n";
        return out;
    }

}
