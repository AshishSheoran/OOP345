//
//  String.cpp
//  workshop 1
//
//  Created by Ashish Sheoran on 2019-09-13.
//  Copyright © 2019 Ashish Sheoran. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS

#include "String.hpp"

namespace sdds {
    
    unsigned int g_maxSize = 3u;
    
    String::String(const char *cstr) //recieves an unmodifiable reference to a c-style string
    {
        if (cstr != nullptr) //checking existance of cstr
        {
            if (cstr[0] == '\0') //if the cstr string is empty
            {
                Cstring = nullptr;
            }
            else //if not empty
            {
                Cstring = new char[g_maxSize];
                //copying characters from cstr to str
                strncpy(Cstring, cstr, (g_maxSize));
                Cstring[g_maxSize + 1] = 0;
            }
        }
    }
    // receive object and inserts the string stored in the instance variable.
    void String::display(std::ostream& os) {
        
        os << Cstring;
    };
    //inserts the saved string into the left operand
    std::ostream& operator << (std::ostream& os, String & cstr) {
        
        static int count = 1;
        os << count << ": ";
        count++;//operator counts how many times it has been called
        
        cstr.display(os);
        
        return os;
        
    };
    
    
}
