#include <string>
#include <iostream>
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"

Playlist::Playlist(){
    this->name = "";
}

Playlist::Playlist(std::string name){
    this->name = name;
}

Playlist::~Playlist(){
    songs.clear();
}

std::string Playlist::getName(){
    return name;
}

LinkedList<Song> &Playlist::getSongs(){
    return songs;
}

void Playlist::addSong(Song song){
    songs.add(song);
}

/**
 * @brief Remove a música especificada da playlist.
 * 
 * @param title Título da música.
 */
void Playlist::removeSong(std::string title){
    this->getSongs().removeValue(Song(title));
}

/**
 * @brief Imprime as músicas da playlist.
 * 
 */
void Playlist::printSongs(){
    auto head = getSongs().getHead();
    getSongs().print();
}

bool Playlist::operator==(Playlist &b){
    return this->getName() == b.getName();
}

std::ostream& operator<<(std::ostream& os, const Playlist& playlist){
    os << "\"" << playlist.name << "\" - " << playlist.songs.getSize() << " música(s).";
    return os;
}