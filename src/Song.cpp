#include "Song.hpp"
#include <string>

Song::Song(){
    setTitle("");
    setAuthor("");
}

/**
 * @brief Construtor da música
 * 
 * @param title Título da música.
 * @param author (Opcional) Autor da música.
 */
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

/**
 * @brief Compara se duas músicas são iguais por seus títulos.
 * @note Duas músicas com títulos iguais e autores diferentes serão consideradas iguais.
 * 
 * @return Retorna true caso o título das músicas seja igual.
 * @return Retorna false caso contrário.
 */
bool Song::operator==(Song &b){
    return this->getTitle() == b.getTitle();
}

std::ostream& operator<<(std::ostream& os, const Song &song){
    os << "Título: \"" << song.title << "\", Autor: \"" << song.author << "\"";
    return os;
}