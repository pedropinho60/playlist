#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <string>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"

class Playlist{

private:
    std::string name;
    LinkedList<Song> songs;

public:
    Playlist();
    Playlist(std::string name);
    ~Playlist();
    std::string getName();
    LinkedList<Song> &getSongs();
    void addSong(Song song);
    void removeSong(std::string title);
    void printSongs();
    bool operator==(Playlist &b);
    friend std::ostream& operator<<(std::ostream& os, const Playlist& playlist);
};

#endif