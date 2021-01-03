// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: November 6, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SongCollection_h
#define SongCollection_h

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <list>

namespace sdds {

    struct Song {
        std::string m_artist;
        std::string m_title;
        std::string m_album;
        double m_price;
        int m_year;
        size_t m_length;
    };

    class SongCollection {
        std::vector<sdds::Song>m_songs;
        std::string& trim(std::string& token);
    public:
        SongCollection(std::string filename);
        void display(std::ostream& out) const;
        void sort(std::string);
        void cleanAlbum();
        bool inCollection(std::string) const;
        std::list<Song> getSongsForArtist(std::string) const;
    };

std::ostream& operator<<(std::ostream& out, const Song& theSong);

}



#endif /* SongCollection_h */
