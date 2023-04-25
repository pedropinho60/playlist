#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"

//Essa classe implementa listas encadeadas.
template <typename T>
class LinkedList{

    size_t size;
    Node<T> *head; //Ponteiro para o primeiro elemento da lista
    Node<T> *tail; //Ponteiro para o último elemento da lista

public:
    //Construtor padrão da lista encadeada
    LinkedList();
    //Adiciona um nó ao fim da lista
    void add(T value);
    //Remove o nó com valor especificado
    void removeIndex(size_t index);
    void removeValue(T value);
    void print();
};

#endif