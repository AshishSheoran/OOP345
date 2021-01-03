// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: October 7, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Restaurant.h"

namespace sdds {

    Restaurant::Restaurant() {

    }

    Restaurant::Restaurant(Reservation* reservations[], size_t count) {
        if(reservations != nullptr) {
            this->reservation = new (std::nothrow) Reservation[count];
            if(this->reservation != nullptr) {
                for(size_t i = 0; i < count; i++) {
                    this->reservation[i] =*reservations[i];
                    this->m_count++;
                }
            }
        }
    }

    Restaurant::Restaurant(const Restaurant& rest) {
        *this = rest;
    }

    Restaurant::Restaurant(Restaurant&& rest) {
        *this = std::move(rest);
    }

    size_t Restaurant::size() const {
        return this->m_count;
    }

    bool Restaurant::isEmpty() const{
        return this->reservation == nullptr? true : false;
    }

    void Restaurant::display(std::ostream& os) const {
        for(size_t i = 0; i < this->m_count; i++) {
            os << this->reservation[i];
        }
    }

    Restaurant& Restaurant::operator=(const Restaurant& rest) {
        if(this != &rest && rest.reservation == nullptr) {
            delete [] this->reservation;
            this->reservation = nullptr;
            this->m_count = 0;
            
            this->reservation = new (std::nothrow) Reservation[rest.m_count];
            if(this->reservation != nullptr) {
                for(size_t i = 0; i < this->m_count; i++) {
                    this->reservation[i] = rest.reservation[i];
                    this->m_count++;
                }
            }
        }
        return *this;
    }

    Restaurant& Restaurant::operator=(Restaurant&& rest) {
        if(this != &rest && rest.reservation == nullptr) {
            delete [] this->reservation;
            this->reservation = nullptr;
            this->m_count = 0;
            
            this->reservation = rest.reservation;
            this->m_count = rest.m_count;
            rest.reservation = nullptr;
            rest.m_count = 0;
        }
        return *this;
    }

    Restaurant::~Restaurant() {
        delete[] reservation;
    }

    std::ostream& operator<<(std::ostream& os, const Restaurant& rest) {
        os << "--------------------------" << std::endl;
        os << "Fancy Restaurant" << std::endl;
        os << "--------------------------" << std::endl;
        if(rest.m_count == 0) {
            os << "This object is empty" << std::endl;
        }
        else {
            rest.display(os);
        }
        os << "--------------------------" << std::endl;
        return os;
    }


}
