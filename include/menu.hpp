#include <iostream>
#include <string>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"

void playlistMenu(LinkedList<Song> &songs, LinkedList<Playlist> &playlists);
void songMenu(LinkedList<Song> &songs, LinkedList<Playlist> &playlists);
int mainMenu(LinkedList<Song> &songs, LinkedList<Playlist> &playlists);