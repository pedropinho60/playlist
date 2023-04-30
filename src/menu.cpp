#include <iostream>
#include <string>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"

void playlistMenu(LinkedList<Playlist> &playlists){
    int choice;

    std::cout << "======================\n";
    std::cout << "Menu de playlists\n";
    std::cout << "1. Adicionar playlist\n";
    std::cout << "2. Remover playlist\n";
    std::cout << "3. Listar playlists\n";
    std::cout << "0. Sair\n";
    std::cout << "Digite sua escolha: ";

    std::cin >> choice;
    std::cin.ignore();

    std::string line;

    switch(choice){
        case 1: // Adicionar playlist
            std::cout << "Digite o nome da playlist para adicionar, ou deixe em branco para cancelar:\n";
            std::getline(std::cin, line);
            if(line != "") {
                if(playlists.searchValue(Playlist(line)) != -1){
                    std::cout << "Erro: Playlist \"" << line << "\" já existe.\n";
                }
                else{
                    playlists.add(Playlist(line));
                    std::cout << "Playlist \"" << line << "\" adicionada com sucesso.\n";
                }
            }
            else{
                std::cout << "Ação cancelada.\n";
            }
            std::cout << "Pressione ENTER para continuar.";
            std::getline(std::cin, line);
            break;
                
        case 2: // Remover playlist
            std::cout << "Digite o nome da playlist para remover, ou deixe em branco para cancelar:\n";
            std::getline(std::cin, line);
            if(line != ""){
                if(playlists.searchValue(Playlist(line)) == -1){
                    std::cout << "Erro: Playlist inválida.\n";
                }
                else{
                    playlists.removeValue(Playlist(line));
                    std::cout << "Playlist \"" << line << "\" removida com sucesso.\n";
                }
            }
            else{
                std::cout << "Ação cancelada.\n";
            }
            std::cout << "Pressione ENTER para continuar.";
            std::getline(std::cin, line);
            break;

        case 3: // Listar playlists
            if(playlists.getSize() == 0){
                std::cout << "Nenhuma playlist cadastrada.\n";
            }
            else{
                std::cout << "Playlists:\n";
                playlists.print();
            }
            std::cout << "Pressione ENTER para continuar.";
            std::getline(std::cin, line);
            break;

        default: // Escolha inválida
            std::cout << "Erro: Escolha inválida!\n";
            std::cout << "Pressione ENTER para continuar.";
            std::getline(std::cin, line);
            break;
    }
}

void songMenu(LinkedList<Song> &songs){
    int choice;

    std::cout << "======================\n";
    std::cout << "Menu de músicas\n";
    std::cout << "1. Adicionar música\n";
    std::cout << "2. Remover música\n";
    std::cout << "3. Listar músicas\n";
    std::cout << "0. Sair\n";
    std::cout << "Digite sua escolha: ";

    std::cin >> choice;
    std::cin.ignore();

    std::string line;

    switch(choice){
        case 1: // Adicionar música
            std::cout << "Digite o nome da música para adicionar, ou deixe em branco para cancelar:\n";
            std::getline(std::cin, line);
            if(line != "") {
                if(songs.searchValue(Song(line)) != -1){
                    std::cout << "Erro: Música \"" << line << "\" já existe.\n";
                }
                else{
                    songs.add(Song(line));
                    std::cout << "Música \"" << line << "\" adicionada com sucesso.\n";
                }
            }
            else{
                std::cout << "Ação cancelada.\n";
            }
            std::cout << "Pressione ENTER para continuar.";
            std::getline(std::cin, line);
            break;
                
        case 2: // Remover música
            std::cout << "Digite o nome da música para remover, ou deixe em branco para cancelar:\n";
            std::getline(std::cin, line);
            if(line != ""){
                if(songs.searchValue(Song(line)) == -1){
                    std::cout << "Erro: Música inválida.\n";
                }
                else{
                    songs.removeValue(Song(line));
                    std::cout << "Música \"" << line << "\" removida com sucesso.\n";
                }
            }
            else{
                std::cout << "Ação cancelada.\n";
            }
            std::cout << "Pressione ENTER para continuar.";
            std::getline(std::cin, line);
            break;

        case 3: // Listar músicas
            if(songs.getSize() == 0){
                std::cout << "Nenhuma música cadastrada.\n";
            }
            else{
                std::cout << "Músicas:\n";
                songs.print();
            }
            std::cout << "Pressione ENTER para continuar.";
            std::getline(std::cin, line);
            break;

        default: // Escolha inválida
            std::cout << "Erro: Escolha inválida!\n";
            std::cout << "Pressione ENTER para continuar.";
            std::getline(std::cin, line);
            break;
    }
}

int mainMenu(LinkedList<Song> &songs, LinkedList<Playlist> &playlists){
    int choice;

    std::cout << "======================\n";
    std::cout << "Menu inicial\n";
    std::cout << "1. Gerenciar playlists\n";
    std::cout << "2. Gerenciar músicas\n";
    std::cout << "0. Sair\n";
    std::cout << "Digite sua escolha: ";

    std::cin >> choice;
    std::cin.ignore();

    switch(choice){
        case 1: 
            playlistMenu(playlists); 
            break;

        case 2: 
            songMenu(songs); 
            break;

        case 0: 
            std::cout << "Programa encerrado.\n";
            return 1;

        default: 
            std::cout << "Erro: Escolha inválida!\n"; 
            break;
    } 

    return 0;
}