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
    Playlist(const Playlist &other);
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
    void removeSong(const Song &song);
    // Remove todas as músicas de uma outra playlist da playlist.
    int removeSong(const Playlist &playlist);
    // Procura uma música na playlist. 
    Song *searchSong(const Song &song);
    // Imprime as músicas da playlist. 
    void printSongs();
    // Sobrecarga de operador de igualdade. 
    bool operator==(Playlist &b);
    // Sobrecarga de operador de união de playlists.
    Playlist operator+(const Playlist &other);
    // Sobrecarga de operador de união de playlist com música.
    Playlist operator+(Song &song);
    // Sobrecarga de operador de diferença de playlists.
    Playlist operator-(const Playlist &other);
    // Sobrecarga de operador de diferença de playlist com música.
    Playlist operator-(Song &song);
    // Sobrecarga de operador de atribuição de playlist.
    Playlist& operator=(const Playlist &other);
    // Sobrecarga de operador de extração de música de uma playlist.
    Playlist& operator>>(Song &song);
    // Sobrecarga de operador de inserção de música em playlist.
    Playlist& operator<<(Song &song);
    // Sobrecarga de operador de inserção de playlist. 
    friend std::ostream& operator<<(std::ostream& os, const Playlist& playlist);
};

#endif
