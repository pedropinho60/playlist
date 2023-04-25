#include "Song.hpp"
#include <string>

Song::Song(std::string title, std::string author){
    setTitle(title);
    setAuthor(author);
}

std::string Song::getTitle(){
    return title;
}

std::string Song::getAuthor(){
    return author;
}

void Song::setTitle(std::string title){
    this->title = title;
}

void Song::setAuthor(std::string author){
    this->author = author;
}