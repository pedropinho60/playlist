#include <iostream>

#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"

int main(){
    Playlist playlist1("Playlist 1");
    Playlist playlist2("Playlist 2");

    Song song1("Song 1", "Artist 1");
    Song song2("Song 2", "Artist 2");
    Song song3("Song 3", "Artist 3");
    Song song4("Song 4", "Artist 4");

    playlist1.addSong(song1);
    playlist1.addSong(song2);
    playlist1.addSong(song3);
    playlist1.addSong(song4);

    playlist2.addSong(song2);
    playlist2.addSong(song3);

    std::cout << playlist1 << std::endl;
    playlist1.printSongs();
    std::cout << playlist2 << std::endl;
    playlist2.printSongs();

    Playlist playlist3 = playlist1 + playlist2;

    std::cout << playlist3 << std::endl;
    playlist3.printSongs();

    Playlist playlist4 = playlist1 - playlist2;

    std::cout << playlist4 << std::endl;
    playlist4.printSongs();

    Playlist playlist5 = playlist2 + song4;
    std::cout << "Playlist 2 + Song 4:" << std::endl;
    std::cout << playlist5 << std::endl;
    playlist5.printSongs();

    Playlist playlist6 = playlist1 - song2;
    std::cout << "Playlist 1 - Song 2:" << std::endl;
    std::cout << playlist6 << std::endl;
    playlist6.printSongs();

    Playlist playlist7("Playlist 7");

    playlist7 << song1 << song2;

    std::cout << playlist7 << std::endl;
    playlist7.printSongs();

    Song song5;
    Song song6;

    playlist7 >> song5 >> song6;
    std::cout << "============================" << std::endl;
    std::cout << playlist7 << std::endl;
    playlist7.printSongs();
    std::cout << "============================" << std::endl;

    std::cout << "Song 5:" << std::endl;
    std::cout << song5 << std::endl;

    std::cout << "Song 6:" << std::endl;
    std::cout << song6 << std::endl;

    return 0;
}
