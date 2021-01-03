//
//  Book.h
//  ws05
//
//  Created by Ashish Sheoran on 2019-10-11.
//  Copyright © 2019 Ashish Sheoran. All rights reserved.
//

#ifndef Book_h
#define Book_h


#include <iostream>
#include <string>

namespace sdds {

    class Book {
        std::string m_author;
        std::string m_title;
        std::string m_country;
        std::string m_description;
        double m_price = 0.0;
        size_t m_year = 0;
        void trim (std::string& str) const;
    public:
        Book();
        Book(const std::string& strBook);
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        friend std::ostream& operator<<(std::ostream& os, Book& books);
    };

}

#endif /* Book_h */
