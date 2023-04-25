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
    std::string getName();
    LinkedList<Song> &getSongs();
};

#endif