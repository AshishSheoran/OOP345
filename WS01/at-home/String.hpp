//
//  String.hpp
//  workshop 1
//
//  Create/Users/ashu/Documents/semester 3/oop345/workshops/OOP-Workshops-master/WS01/workshop 1/workshop 1/String.cppd by Ashish Sheoran on 2019-09-13.
//  Copyright © 2019 Ashish Sheoran. All rights reserved.
//

#ifndef SDDS_STRING_H
#define SDDS_STRING_H
#include <iostream>
#include<cstring>

namespace sdds {
    // declaration of global veriable that can be avaliable for all translation units
    extern unsigned int g_maxSize;
    
    class String {
        char *Cstring;// C-style null terminated string of any length
    public:
        String(const char*);
        void display(std::ostream&);
    };
    std::ostream& operator << (std::ostream& os, String&);
}

#endif // !SDDS_STRING_H
