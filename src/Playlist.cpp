/**
 * @file Playlist.cpp
 * @brief Arquivo que implementa os métodos da classe Playlist.
 */

#include <string>
#include <iostream>
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"

/**
 * @brief Construtor padrão da playlist.
 */
Playlist::Playlist(){
    this->name = "";
}

/**
 * @brief Construtor da playlist que recebe seu nome.
 * 
 * @param name Nome da playlist.
 */
Playlist::Playlist(std::string name){
    this->name = name;
}

Playlist::Playlist(Playlist &other){
    this->name = other.name;

    this->addSong(other);
}

/**
 * @brief Destrutor da playlist, que remove todas as músicas.
 */
Playlist::~Playlist(){
    getSongs().clear();
}

/**
 * @brief Retorna o tamanho da playlist.
 * 
 * @return Número de músicas.
 */
size_t Playlist::getSize(){
    return getSongs().getSize();
}

/**
 * @brief Retorna o nome da playlist.
 * 
 * @return Nome da playlist.
 */
const std::string& Playlist::getName() const{
    return name;
}

/**
 * @brief Retorna uma referência para a lista encadeada de músicas.
 * 
 * @return Referência para a lista de músicas.
 */
LinkedList<Song> &Playlist::getSongs() {
    return songs;
}

/**
 * @brief Adiciona uma música à playlist.
 * 
 * @param song Música a ser adicionada.
 */
void Playlist::addSong(Song &song){
    getSongs().add(song);
}

/**
 * @brief Adiciona todas as músicas de uma outra playlist à playlist.
 * 
 * @param playlist Playlist a ser adicionada.
 */
void Playlist::addSong(const Playlist &playlist){
    getSongs().add(playlist.songs);
}

/**
 * @brief Remove a música especificada da playlist.
 * 
 * @param title Título da música.
 */
void Playlist::removeSong(Song &song){
    getSongs().removeValue(song);
}

int Playlist::removeSong(Playlist playlist){
    int removed = 0;
    for (Node<Song> *song = playlist.getSongs().getHead(); song != nullptr; song = song->getNext()){
        if (getSongs().removeValue(song->getValue())){
            removed++;
        }
    }
    return removed;
}

/**
 * @brief Procura uma música na playlist.
 * 
 * @param song Música a ser buscada.
 * @return Retorna o ponteiro para a música, caso ela esteja na lista, ou nullptr
 * caso contrário.
 */
Song *Playlist::searchSong(Song &song){
    return getSongs().searchValue(song);
}

/**
 * @brief Imprime as músicas da playlist.
 */
void Playlist::printSongs(){
    getSongs().print();
}

/**
 * @brief Sobrecarga de operador de igualdade.
 * 
 * @return Retorna true se o nome das playlists for igual.
 * @return Retorna false caso contrário.
 */
bool Playlist::operator==(Playlist &b){
    return this->getName() == b.getName();
}

Playlist Playlist::operator+(const Playlist &other){
    Playlist newPl(name + " + " + other.name);
    newPl.addSong(*this);

    Node<Song> *currNode = other.songs.getHead();

    while(currNode != nullptr){
        Song currSong = currNode->getValue();
        if(newPl.searchSong(currSong) == nullptr){
            newPl.addSong(currSong);
        }

        currNode = currNode->getNext();
    }

    return newPl;
}

Playlist Playlist::operator+(Song &song){
    Playlist newPl(*this);
    if(newPl.searchSong(song) == nullptr){
        newPl.addSong(song);
    }

    return newPl;
}

Playlist& Playlist::operator=(const Playlist &other){
    if(this == &other){
        return *this;
    }

    songs.clear();

    addSong(other);
    name = other.name;

    return *this;
}

/**
 * @brief Sobrecarga de operador de inserção da playlist.
 */
std::ostream& operator<<(std::ostream& os, const Playlist& playlist){
    os << "\"" << playlist.name << "\" - " << playlist.songs.getSize() << " música(s).";
    return os;
}