// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: October 7, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef Restaurent_h
#define Restaurent_h

#include "Reservation.h"
#include <iostream>
namespace sdds {

        class Restaurant {
            Reservation* reservation  { nullptr };
            size_t m_count = 0;
        public:
            Restaurant();
            Restaurant(Reservation* [], size_t );
            Restaurant(const Restaurant&);
            Restaurant& operator=(const Restaurant&);
            Restaurant(Restaurant&&);
            Restaurant& operator=(Restaurant&&);
            ~Restaurant();
            size_t size() const;
            bool isEmpty() const;
            void display(std::ostream&) const;
            friend std::ostream& operator<<(std::ostream&, const Restaurant&);
        };


}


#endif /* Restaurent_h */
