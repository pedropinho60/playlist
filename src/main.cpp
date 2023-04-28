#include <iostream>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"

void playlistMenu(){
    std::cout << "\nMenu de playlists\n";
    std::cout << "1. Adicionar playlists\n";
    std::cout << "2. Remover playlist\n";
    std::cout << "3. \n";
    std::cout << "0. Sair\n";
    std::cout << "Digite sua escolha: ";
}

void songMenu(){}

int mainMenu(){
    int choice;

    std::cout << "\nMenu inicial\n";
    std::cout << "1. Gerenciar playlists\n";
    std::cout << "2. Gerenciar músicas\n";
    std::cout << "0. Sair\n";
    std::cout << "Digite sua escolha: ";

    std::cin >> choice;

    switch(choice){
        case 1: playlistMenu(); break;
        case 2: songMenu(); break;
        case 0: return 1;
        default: std::cout << "Erro: Escolha inválida!\n"; break;
    } 

    return 0;
}

int main(){
    LinkedList<Playlist> playlists;
    LinkedList<Song> songs;

    int exit{0};

    while(exit == 0){
        mainMenu();
    }

    playlists.clear();

    return 0;
}