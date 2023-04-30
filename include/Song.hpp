#ifndef SONG_HPP
#define SONG_HPP

#include <string>
#include <iostream>

// Classe que representa uma música, contendo título e autor
class Song{

private:
    std::string title; // Título da música
    std::string author; // Autor da música

public:
    Song();
    Song(std::string title, std::string author = "");
    std::string getTitle();
    std::string getAuthor();
    void setTitle(std::string title);
    void setAuthor(std::string author);
    bool operator==(Song &b);
    friend std::ostream& operator<<(std::ostream& os, const Song& song);
};

#endif