// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: October 7, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef ConfirmationSender_h
#define ConfirmationSender_h

#include <utility>
#include <iostream>
#include "Reservation.h"

namespace sdds {
    class ConfirmationSender {
        Reservation** reservation{ nullptr };
        size_t count{ 0 };

    public:
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender&);
        ConfirmationSender(ConfirmationSender&&);
        ConfirmationSender& operator=(const ConfirmationSender&);
        ConfirmationSender& operator=(ConfirmationSender&&);
        ConfirmationSender& operator+=(const Reservation&);
        ConfirmationSender& operator-=(const Reservation&);
        ~ConfirmationSender();
        void display(std::ostream&)const;
        friend  std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
    };
}


#endif /* ConfirmationSender_h */
