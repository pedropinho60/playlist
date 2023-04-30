#include <iostream>
#include <string>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"
#include "menu.hpp"

int main(){
    LinkedList<Playlist> playlists;
    LinkedList<Song> songs;

    int exit{0};

    while(exit == 0){
        exit = mainMenu(songs, playlists);
    }

    playlists.clear();
    songs.clear();

    return 0;
}