// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: November 6, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <cstring>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include "SongCollection.h"


namespace sdds {

   std::string& SongCollection::trim(std::string& token)
    {
        while (token.length() > 0 && token[0] == ' ') {
            token.erase(0, 1);
        }
        
        while (token.length() > 0 && token[token.length() - 1] == ' ')
        {
            token.erase(token.length() - 1, 1);
        }
        return token;
    }

    SongCollection::SongCollection(std::string filename) {
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
            
            
            try {
                song.m_year = std::stoi(buffer.substr(75,5));
            }
            catch(...) {
                song.m_year = 0;
            }
            
            song.m_length = std::stoi(buffer.substr(80,5));
            song.m_price = std::stod(buffer.substr(85));
            this->m_songs.push_back(song);
            }
        }
        file.close();
        
    }


    std::ostream& operator<<(std::ostream& out, const Song& theSong) {
        out << "| " << std::left << std::setw(20) << theSong.m_title
            << " | " << std::left << std::setw(15) << theSong.m_artist
            << " | " << std::left << std::setw(20) << theSong.m_album
            << " | " << std::right << std::setw(6) << (theSong.m_year > 0 ?                 std::to_string(theSong.m_year) : " ")
            << " | " << theSong.m_length / 60 << ":" << std::setw(2) << std::setfill('0') << theSong.m_length % 60
            << " | " << std::fixed << std::setprecision(2) << theSong.m_price << " |"
        << std::setfill(' ');
        
        return out;
    }
        
    void SongCollection::display(std::ostream& out) const {
        for_each(m_songs.begin(), m_songs.end(), [&out](const Song& songs) {
            out << songs << std::endl;
        });
        
        auto total_length = accumulate(m_songs.begin(), m_songs.end(),0u, [](unsigned int& res, const Song& theSong) {
            return res += theSong.m_length;
        });
        
        out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
        std::string item = "Total listening time: ";
        item += std::to_string(total_length / 3600);
        item += ":";
        item += std::to_string((total_length %= 3600) / 60);
        item += ":";
        item += std::to_string(total_length / 60);
        
        out << "| " << std::setw(84) << item << " |\n";
    }
        
    void SongCollection::sort(std::string field) {
        if(field == "title") {
            std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {
                return a.m_title < b.m_title;
            });
        }
        else if(field == "album") {
            std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {
                return a.m_album < b.m_album;
            });
        }
        else if(field == "length") {
            std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {
                return a.m_length < b.m_length;
            });
        }
    }
        
   void SongCollection::cleanAlbum()
        {
            for_each(m_songs.begin(), m_songs.end(), [](Song & song)
            {
                if (song.m_album == "[None]")
                    song.m_album = " ";
            });
    
        }
    
    bool SongCollection::inCollection(std::string singer) const {
        auto str = std::find_if(m_songs.begin(), m_songs.end(), [&singer](const Song& theSong) {
            return theSong.m_artist == singer;
        });
        
        return str != m_songs.end();
    }
        
    std::list<Song> SongCollection::getSongsForArtist(std::string singer) const {
        auto check = std::count_if(m_songs.begin(), m_songs.end(), [&singer](const Song& theSong) {
            return theSong.m_artist == singer;
        });
        std::list<Song> songs(check);
        
        std::copy_if(m_songs.begin(), m_songs.end(), songs.begin(), [&singer](const Song& theSong) {
            return theSong.m_artist == singer;
        });
        
        return songs;
    }
    
    

}
