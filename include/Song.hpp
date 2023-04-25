#ifndef SONG_HPP
#define SONG_HPP

#include <string>

// Classe que representa uma música, contendo título e autor
class Song{

private:
    std::string title; // Título da música
    std::string author; // Autor da música

public:
    Song(std::string title, std::string author);
    std::string getTitle();
    std::string getAuthor();
    void setTitle(std::string title);
    void setAuthor(std::string author);
};

#endif