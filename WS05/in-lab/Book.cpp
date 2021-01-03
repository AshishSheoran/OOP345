//
//  Book.cpp
//  ws05
//
//  Created by Ashish Sheoran on 2019-10-11.
//  Copyright © 2019 Ashish Sheoran. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include <utility>
#include "Book.h"

namespace sdds {

    void Book::trim(std::string& str) const {
        size_t i = 0u;
        
        for(i = 0; i < str.length() && str[i] == ' '; i++)
            str = str.substr(i);
        
        for(i = str.length(); i > 0 && str[i-1] == ' '; i--)
            str = str.substr(0, i);
        
    }

Book::Book() {
    
}

    Book::Book(const std::string& strBook) {
        size_t posS = 0;
        size_t posE = strBook.find(',');
        m_author = strBook.substr(posS, posE - posS);
        this->trim(m_author);
        
        posS = posE + 1;
        posE = strBook.find(',', posS);
        m_title = strBook.substr(posS, posE - posS);
        this->trim(m_title);
        
        posS = posE + 1;
        posE = strBook.find(',', posS);
        m_country = strBook.substr(posS, posE - posS);
        this->trim(m_country);
        
        posS = posE + 1;
        posE = strBook.find(',', posS);
        m_price = std::stod(strBook.substr(posS, posE - posS));
        
        posS = posE + 1;
        posE = strBook.find(',', posS);
        m_year = std::stoi(strBook.substr(posS, posE - posS));
        
        posS = posE + 1;
        posE = strBook.find(',', posS);
        m_description = strBook.substr(posS, posE - posS);
        this->trim(m_description);
        
    }


    const std::string& Book::title() const {
        return this->m_title;
    }

    const std::string& Book::country() const {
        return this->m_country;
    }

    const size_t& Book::year() const {
        return this->m_year;
    }

    double& Book::price() {
        return this->m_price;
    }


    std::ostream& operator<<(std::ostream& os, Book& books) {
        os << std::right << std::setw(20) << books.m_author << " | "
            << std::right << std::setw(22) << books.title() << " | "
            << std::right << std::setw(5) << books.country() << " | "
            << std::setw(4) << books.year() << " | "
            << std::right << std::setw(6) << std::fixed << std::setprecision(2)
            << books.price() << " | "
        << std::left << books.m_description << std::endl;
        return os;
    }

}
