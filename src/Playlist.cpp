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

std::string Playlist::getName(){
    return name;
}

LinkedList<Song> &Playlist::getSongs(){
    return songs;
}

void Playlist::addSong(Song song){
    songs.add(song);
}

void Playlist::removeSong(std::string title){
    Node<Song> *currNode = songs.getHead();
    Node<Song> *prevNode = nullptr;

    while(currNode != nullptr){
        if(currNode->getValue().getTitle() == title){
            if(prevNode != nullptr){
                prevNode->setNext(currNode->getNext());
                if(currNode == songs.getTail()){
                    songs.setTail(prevNode);
                }
            }
            else{
                songs.setHead(currNode->getNext());
                if(songs.getHead() == nullptr){
                    songs.setTail(nullptr);
                }
            }
            delete currNode;
        }
        prevNode = currNode;
        currNode = currNode->getNext();
    }
}

void Playlist::printSongs(){
    Node<Song> *currNode = songs.getHead();

    while(currNode != nullptr){
        std::cout << "Título: " << currNode->getValue().getTitle() << std::endl;
        std::cout << "Autor: " << currNode->getValue().getAuthor() << std::endl;

        currNode = currNode->getNext();

        if(currNode != nullptr) {
            std::cout << std::endl;
        }
    }
}