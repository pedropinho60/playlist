/**
 * @file main.cpp
 * @brief Arquivo principal do programa.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"
#include "menu.hpp"

/**
 * @brief Setup inicial do programa, que adiciona exemplos de
 * músicas e playlists para demonstrar as funcionalidades do
 * programa.
 * 
 * @param songs Lista encadeada (LinkedList) de músicas (Song) do sistema.
 * @param playlists Lista encadeada (LinkedList) de playlists (Playlist) do sistema.
 */
void setup(LinkedList<Song> &songs, LinkedList<Playlist> &playlists){
    int choice;

    std::cout << "Deseja executar o setup inicial? Isso irá adicionar\n" <<
                 "alguns exemplos de músicas e playlists\n";
    std::cout << "1. Sim\n";
    std::cout << "0. Não\n";
    std::cout << "Digite sua escolha: ";

    std::cin >> choice;
    std::cin.ignore();

    if(choice == 0) return;

    Song mus1("Música 1", "Autor 1");
    Song mus2("Música 2", "Autor 2");
    Song mus3("Música 3", "Autor 3");
    Song mus4("Música 4", "Autor 4");

    Playlist pl1("Playlist 1");
    Playlist pl2("Playlist 2");
    Playlist pl3("Playlist 3");

    songs.add(mus1);
    songs.add(mus2);
    songs.add(mus3);
    songs.add(mus4);

    playlists.add(pl1);
    playlists.add(pl2);
    playlists.add(pl3);

    auto pl1ptr = playlists.searchValue(pl1);
    auto pl2ptr = playlists.searchValue(pl2);
    auto pl3ptr = playlists.searchValue(pl3);

    pl1ptr->addSong(mus1);
    pl1ptr->addSong(mus2);
    pl1ptr->addSong(mus3);

    pl2ptr->addSong(mus1);
    pl2ptr->addSong(mus4);

    std::cout << "Setup completo\n";
    std::cout << "Pressione ENTER para continuar.";
    std::cin.get();
}

/**
 * @brief Lê o arquivo e adiciona as playlists e músicas ao sistema.
 * 
 * @param in_file Arquivo de entrada.
 * @param songs Lista encadeada de músicas.
 * @param playlists Lista encadeada de playlists.
 */
void parseFile(std::ifstream& in_file, LinkedList<Song>& songs, LinkedList<Playlist> &playlists){
    std::string line;
    while(std::getline(in_file, line)){
        std::istringstream iss{line};
        std::string pl_title;
        std::getline(iss, pl_title, ';');
        
        Playlist playlist{pl_title};
        playlists.add(playlist);

        std::string song_string;
        while(std::getline(iss, song_string, ',')){
            std::istringstream iss_song{song_string};
            std::string song_title;
            std::string song_author;

            std::getline(iss_song, song_title, ':');
            std::getline(iss_song, song_author);

            Song song{song_title, song_author};
            songs.add(song);

            playlists.searchValue(playlist)->addSong(song);
        }
    }
}

/**
 * @brief Escreve as playlists e músicas do sistema ao arquivo.
 * 
 * @param out_file Arquivo de saída.
 * @param songs Lista encadeada de músicas.
 * @param playlists Lista encadeada de playlists.
 */
void writeFile(std::ofstream& out_file, LinkedList<Song>& songs, LinkedList<Playlist> &playlists){
    auto plRunner = playlists.getHead();

    while(plRunner != nullptr){
        auto currPl = plRunner->getValue();

        out_file << currPl.getName() << ';';

        auto songRunner = currPl.getSongs().getHead();

        while(songRunner != nullptr){
            auto currSong = songRunner->getValue();

            out_file << currSong.getTitle() << ':';
            out_file << currSong.getAuthor();

            if(songRunner->getNext() != nullptr){
                out_file << ',';
            }

            songRunner = songRunner->getNext();
        }

        out_file << '\n';
        plRunner = plRunner->getNext();
    }
}

int main(int argc, char *argv[]){
    LinkedList<Playlist> playlists;
    LinkedList<Song> songs;

    if(argc != 2){
        std::cout << "Número de argumentos inválido! Esperado 1 argumento (nome do arquivo).\n";
        return 1;
    }
    
    std::ifstream in_file;
    in_file.open(argv[1]);

    if(!in_file.is_open()){
        std::cout << "Não foi possível abrir o arquivo \"" << argv[1] << "\"!\n";
        return 1;
    }
    
    parseFile(in_file, songs, playlists);

    in_file.close();

    int exit{0};

    while(exit == 0){
        exit = mainMenu(songs, playlists);
    }

    std::ofstream out_file;
    out_file.open(argv[1]);

    writeFile(out_file, songs, playlists);

    out_file.close();

    playlists.clear();
    songs.clear();

    return 0;
}
