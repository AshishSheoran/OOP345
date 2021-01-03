// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: November 8, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "SongCollection.h"


namespace sdds {

void SongCollection::trim(std::string& str) const {
    size_t i = 0u;
    
    for(i = 0; i < str.length() && str[i] == ' '; i++)
        str = str.substr(i);
    
    for(i = str.length(); i > 0 && str[i-1] == ' '; i--)
        str = str.substr(0, i);
}

SongCollection::SongCollection(std::string& filename) {
    std::ifstream file(filename);
    
    if(!file) {
        throw "Invalid filename";
    }
    
    while(file) {
        Song song;
        std::string buffer;
        std::getline(file, buffer);
        if(file) {
            song.m_title = buffer.substr(0, 25);
            trim(song.m_title);
            
            song.m_artist = buffer.substr(25, 25);
            trim(song.m_artist);
            
            song.m_album = buffer.substr(50, 25);
            trim(song.m_album);
        }
        
        try {
            song.m_year = std::stoi(buffer.substr(75,5));
        }
        catch(...) {
            song.m_year = 0;
        }
        
        song.m_length = std::stoi(buffer.substr(80,5));
        song.m_price = std::stod(buffer.substr(85));
    }
    
}

void SongCollection::display(std::ostream& out) const {
    out << "| " << std::left << std::setw(20) << m_title
}

}
