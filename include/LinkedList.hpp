#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "Song.hpp"
#include "Node.hpp"

/**
 * @brief Classe que implementa listas encadeadas do tipo template.
 * 
 * @tparam T Tipo do valor armazenado na lista.
 */
template <typename T>
class LinkedList{

private:
    Node<T> *head; //Ponteiro para o primeiro elemento da lista
    Node<T> *tail; //Ponteiro para o último elemento da lista

public:
    LinkedList();
    void clear();
    size_t getSize() const;
    Node<T> *getHead();
    Node<T> *getTail();
    void setHead(Node<T> *head);
    void setTail(Node<T> *tail);
    void add(T value);
    int searchValue(T value);
    void removeIndex(size_t index);
    void removeValue(T value);
    void print();
};

/**
 * @brief Construtor da lista encadeada.
 * 
 * 
 */
template <typename T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

/**
 * @brief Remove todos os elementos da lista.
 */
template <typename T>
void LinkedList<T>::clear(){
    Node<T> *prev = nullptr;
    Node<T> *curr = head;

    while(curr != nullptr){
        prev = curr;
        curr = curr->getNext();
        delete prev;
    }
    head = nullptr;
    tail = nullptr;
}

/**
 * @brief Retorna o tamanho da lista encadeada.
 * 
 * 
 * @return Tamanho da lista.
 */
template <typename T>
size_t LinkedList<T>::getSize() const{
    size_t size = 0;
    Node<T> *curr = head;

    while(curr != nullptr){
        curr = curr->getNext();
        size++;
    }
    return size;
}

template <typename T>
Node<T> *LinkedList<T>::getHead(){
    return head;
}

template <typename T>
Node<T> *LinkedList<T>::getTail(){
    return tail;
}

template <typename T>
void LinkedList<T>::setHead(Node<T> *head){
    this->head = head;
}

template <typename T>
void LinkedList<T>::setTail(Node<T> *tail){
    this->tail = tail;
}

/**
 * @brief Adiciona um novo elemento com valor especificado ao final da lista.
 * 
 * 
 * @param value Valor a ser adicionado.
 */
template <typename T>
void LinkedList<T>::add(T value){
    Node<T> *newNode = new Node<T>(value);

    // Verifica se a lista é vazia
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->setNext(newNode);
        tail = newNode;
    }
}

/**
 * @brief Procura um elemento específico na lista. 
 * 
 * 
 * @param value Valor a ser buscado.
 * @return Retorna o índice do valor, caso ele esteja na lista, ou -1, caso contrário.
 */
template <typename T>
int LinkedList<T>::searchValue(T value){
    Node<T> *curr = head;
    int index = 0;
    while(curr != nullptr){
        if(curr->getValue() == value){
            return index;
        }
        index++;
    }
    return -1;
}

/**
 * @brief Remove o elemento no índice especificado da lista, caso o índice seja válido.
 * 
 * 
 * @param index Índice do valor a ser removido.
 */
template <typename T>
void LinkedList<T>::removeIndex(size_t index){
    Node<T> *curr = head;
    Node<T> *prev = nullptr;

    // Verifica se índice é válido
    if(index >= getSize()){
        return;
    }

    for(int i=0; i<index; i++){
        prev = curr;
        curr = curr->getNext();
    }

    if(prev != nullptr){
        prev->setNext(curr->getNext());
        if(curr == tail){
            tail = prev;
        }
    }
    else{
        head = curr->getNext();
        if(head == nullptr){
            tail = nullptr;
        }
    }
    delete curr;
}

/**
 * @brief Remove o elemento especificado da lista.
 * 
 *
 * @param value Valor a ser removido.
 */
template <typename T>
void LinkedList<T>::removeValue(T value){
    Node<T> *curr = head;
    Node<T> *prev = nullptr;

    while(curr != nullptr){
        if(curr->getValue() == value){
            if(prev != nullptr){
                prev->setNext(curr->getNext());
                if(curr == tail){
                    tail = prev;
                }
            }
            else{
                head = curr->getNext();
                if(head == nullptr){
                    tail = nullptr;
                }
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->getNext();
    }
}


/**
 * @brief Imprime todos os elementos da lista recursivamente.
 * 
 * 
 * @param curr Ponteiro para o próximo elemento a ser impresso.
 * Caso não especificado, será usado o primeiro elemento da lista.
 */
template <typename T>
void LinkedList<T>::print(){
    printAux(head);
}

template <typename T>
void printAux(Node<T> *curr){
    if(curr != nullptr){
        std::cout << curr->getValue() << std::endl;
        printAux(curr->getNext());
    }
}

#endif