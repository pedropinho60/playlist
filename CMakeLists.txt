cmake_minimum_required(VERSION 3.22.1)
project(Playlist VERSION 0.1 LANGUAGES CXX)

include_directories( include )

add_executable( program
                src/Node.cpp
                src/LinkedList.cpp
                src/main.cpp
                )

set_property(TARGET program PROPERTY CXX_STANDARD 11)
