// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: October 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef Reservation_h
#define Reservation_h

#include <iostream>
#include <string>
#include <algorithm>
 
namespace sdds {

    class Reservation {
        std::string m_resId;
        std::string m_resName;
        std::string m_email;
        std::string m_message;
        int m_numberOfPeople;
        int m_day;
        int m_hour;
        
    public:
        Reservation();
        Reservation(const std::string& m_res);
        void display(std::ostream& ) const;
        
    };

    std::ostream& operator<<(std::ostream& os, const Reservation& res);

}


#endif /* Reservation_h */
