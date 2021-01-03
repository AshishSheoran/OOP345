// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: October 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include "Reservation.h"
#include <string>
#include <iomanip>


namespace sdds {

    // Default constructor
    Reservation::Reservation() {
        m_resId = m_resName = m_email = "";
        m_numberOfPeople = m_day = m_hour = 0;
    }

    // Parametrized constructor
    Reservation::Reservation(const std::string& m_res) {
        m_message = m_res;
        std::string::size_type position;
        while ((position = m_message.find(" ")) != std::string::npos) {              //remove space
            m_message.erase(position, 1);
        }
        
        // getting the reservation ID..
        std::size_t posId = m_message.find(":");
        m_resId = m_message.substr(0,posId);
        m_message.erase(0,posId+1);
        
        // Getting the reservation name.
        std::size_t posName = m_message.find(",");
        m_resName = m_message.substr(0,posName);
        m_message.erase(0,posName+1);
       
        
        // Getting the reservation email.
        std::size_t posEmail = m_message.find(",");
        m_email = m_message.substr(0,posEmail);
        m_message.erase(0,posEmail+1);
        
        // getting the number of people for reservation..
        std::size_t posNumber = m_message.find(",");
        std::string res_number = m_message.substr(0,posNumber);
        m_numberOfPeople = std::stoi(res_number);
        m_message.erase(0,posNumber+1);
        
        // getting the number of day for reservation..
        std::size_t posDay = m_message.find(",");
        std::string res_Day = m_message.substr(0,posDay);
        m_day = std::stoi(res_Day);
        m_message.erase(0,posDay+1);
        
        // getting the number of hour for reservation..
        m_hour = std::stoi(m_message);
        
    }

    // To display the reservation information
    void Reservation::display(std::ostream& os ) const {
        std::string mail = "<" + m_email + ">";
        if(m_hour >= 6 && m_hour <= 9 ) {
            os << "Reservation " << m_resId << ":" <<std::right << std::setw(10) << m_resName << " " << std::left << std::setw(20)
                << mail << "  " << "Breakfast on day " << m_day << " @ " << m_hour << ":00 for " << m_numberOfPeople
                << " people." <<std::endl;
        }
        else if ( m_hour >=11 && m_hour <= 15) {
            os << "Reservation " << m_resId << ":"  << std::setw(10) << std::right << m_resName << " " << std::setw(20) << std::left
                << mail << "  " << "Lunch on day " << m_day << " @ " << m_hour << ":00 for " << m_numberOfPeople
                << " people." <<std::endl;
        }
        else if (m_hour >=17 && m_hour <=21) {
            os << "Reservation " << m_resId << ":"  << std::setw(10) << std::right << m_resName << " " << std::setw(20) << std::left
                << mail << "  " << "Dinner on day " << m_day << " @ " << m_hour << ":00 for " << m_numberOfPeople
                << " people." <<std::endl;
        }
        else {
            os << "Reservation " << m_resId << ":"  << std::setw(10) << std::right << m_resName << " " << std::setw(20) << std::left
                << mail << "  " << "Drinks on day " << m_day << " @ " << m_hour << ":00 for " << m_numberOfPeople
                << " people." <<std::endl;
        }
    }


    // Passing the input in output stream by calling the display function
    std::ostream& operator<< (std::ostream& os, const Reservation& res) {
        res.display(os);
        return os;
    }
    

}
