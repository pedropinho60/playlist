/**
 * @file Playlist.hpp
 * @brief Arquivo que contém a classe Playlist.
 */

#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <string>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"

/**
 * @brief Classe que implementa uma playlist, contendo uma lista encadeada 
 * (LinkedList) de músicas (Song).
 */
class Playlist{

private:
    std::string name; //!< Nome da playlist.
    LinkedList<Song> songs; //!< Lista de músicas da playlist.

public:
    // Construtor padrão da playlist. 
    Playlist();
    // Construtor da playlist que recebe seu nome. 
    Playlist(std::string name);
    // Construtor cópia da playlist.
    Playlist(Playlist &other);
    // Destrutor da playlist, que remove todas as músicas. 
    ~Playlist();
    // Retorna o tamanho da playlist.
    size_t getSize();
    // Retorna o nome da playlist. 
    const std::string &getName() const;
    // Retorna uma referência para a lista encadeada de músicas. 
    LinkedList<Song> &getSongs();
    // Adiciona uma música à playlist. 
    void addSong(Song &song);
    // Adiciona todas as músicas de uma outra playlist à playlist.
    void addSong(const Playlist &playlist);
    // Remove a música especificada da playlist. 
    void removeSong(Song &song);
    // Remove todas as músicas de uma outra playlist da playlist.
    int removeSong(Playlist playlist);
    // Procura uma música na playlist. 
    Song *searchSong(Song &song);
    // Imprime as músicas da playlist. 
    void printSongs();
    // Sobrecarga de operador de igualdade. 
    bool operator==(Playlist &b);
    // Sobrecarga de operador de união da playlist.
    Playlist operator+(const Playlist &other);
    Playlist operator+(Song &song);
    Playlist& operator=(const Playlist &other);
    // Sobrecarga de operador de inserção da playlist. 
    friend std::ostream& operator<<(std::ostream& os, const Playlist& playlist);
};

#endif