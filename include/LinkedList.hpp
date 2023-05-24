/**
 * @file LinkedList.hpp
 * @brief Arquivo que contém a classe LinkedList.
 */

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "Song.hpp"
#include "Node.hpp"

/**
 * @brief Classe que implementa uma lista encadeada template.
 * 
 * @tparam T Tipo do valor armazenado na lista.
 */
template <typename T>
class LinkedList{

private:
    Node<T> *head; //!< Ponteiro para o primeiro elemento da lista
    Node<T> *tail; //!< Ponteiro para o último elemento da lista

public:
    // Construtor da lista encadeada. 
    LinkedList();
    // Construtor cópia da lista encadeada.
    LinkedList(const LinkedList<T> &other);
    // Destrutor da lista encadeada, que remove todos os elementos.
    ~LinkedList();
    // Remove todos os elementos da lista. 
    void clear();
    // Retorna o tamanho da lista encadeada. 
    size_t getSize() const;
    // Retorna a cabeça da lista. 
    Node<T> *getHead() const;
    // Retorna a cauda da lista. 
    Node<T> *getTail() const;
    // Altera o ponteiro cabeça da lista. 
    void setHead(Node<T> *head);
    // Altera o ponteiro cauda da lista. 
    void setTail(Node<T> *tail);
    // Adiciona um novo elemento com valor especificado ao final da lista. 
    void add(T value);
    // Adiciona todos os elementos de uma lista ao final da lista.
    void add(const LinkedList<T> &other);
    // Procura um elemento específico na lista. 
    T *searchValue(T value);
    // Remove o elemento no índice especificado da lista.
    void popBack();
    // Remove o elemento especificado da lista. 
    int removeValue(T value);
    // Remove os elementos de uma outra lista da lista. Remove apenas a primeira ocorrência de cada elemento.
    void removeValue(LinkedList<T> &other);
    // Imprime todos os elementos da lista recursivamente. 
    void print();

    LinkedList<T> operator+(LinkedList<T> &other);
    const LinkedList<T>& operator>>(Node<T> &node);
    LinkedList<T>& operator<<(const Node<T> &node);
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
 * @brief Construtor cópia da lista encadeada.
 * 
 * @param other Referência para a lista a ser copiada.
 */
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other){
    head = nullptr;
    tail = nullptr;

    add(other);
}

/**
 * @brief Destrutor da lista encadeada, que remove todos os elementos.
 */
template <typename T>
LinkedList<T>::~LinkedList(){
    clear();
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

/**
 * @brief Retorna a cabeça da lista.
 * 
 * @return Ponteiro para o primeiro elemento da lista.
 */
template <typename T>
Node<T> *LinkedList<T>::getHead() const{
    return head;
}

/**
 * @brief Retorna a cauda da lista.
 * 
 * @return Ponteiro para o último elemento da lista.
 */
template <typename T>
Node<T> *LinkedList<T>::getTail() const{
    return tail;
}

/**
 * @brief Altera o ponteiro cabeça da lista.
 * 
 * @param head Novo ponteiro.
 */
template <typename T>
void LinkedList<T>::setHead(Node<T> *head){
    this->head = head;
}

/**
 * @brief Altera o ponteiro cauda da lista.
 * 
 * @param tail Novo ponteiro.
 */
template <typename T>
void LinkedList<T>::setTail(Node<T> *tail){
    this->tail = tail;
}

/**
 * @brief Adiciona um novo elemento com valor especificado ao final da lista.
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
 * @brief Adiciona todos os elementos de uma lista ao final da lista.
 * 
 * @param other Lista a ser adicionada.
 */
template <typename T>
void LinkedList<T>::add(const LinkedList<T> &other){
    Node<T> *currNode = other.getHead();
    
    while(currNode != nullptr){
        this->add(currNode->getValue());
        currNode = currNode->getNext();
    }
}

/**
 * @brief Procura um elemento específico na lista. 
 * 
 * 
 * @param value Valor a ser buscado.
 * @return Retorna o ponteiro para o valor, caso ele esteja na lista, ou nullptr, caso contrário.
 */
template <typename T>
T *LinkedList<T>::searchValue(T value){
    Node<T> *curr = head;

    while(curr != nullptr){
        if(curr->getValue() == value){
            return &(curr->getValue());
        }
        curr = curr->getNext();
    }
    return nullptr;
}

/**
 * @brief Remove o elemento no índice especificado da lista.
 * 
 * @param index Índice do elemento a ser removido.
 */
template <typename T>
void LinkedList<T>::popBack(){
    Node<T> *curr = head;
    Node<T> *prev = nullptr;

    while(curr->getNext() != nullptr){
        prev = curr;
        curr = curr->getNext();
    }

    if(prev != nullptr){
        prev->setNext(nullptr);
        tail = prev;
    }
    else{
        head = nullptr;
        tail = nullptr;
    }

    delete curr;
}

/**
 * @brief Remove o elemento especificado da lista.
 *
 * @param value Valor a ser removido.
 * @return 1 se o elemento foi removido, 0 caso contrário.
 */
template <typename T>
int LinkedList<T>::removeValue(T value){
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
            return 1;
        }
        prev = curr;
        curr = curr->getNext();
    }
    return 0;
}

/**
 * @brief Remove todos os elementos de uma lista da lista.
 * 
 * @param other Lista com elementos a serem removidos.
 */
template <typename T>
void LinkedList<T>::removeValue(LinkedList<T> &other){
    Node<T> *currNode = other.getHead();

    while(currNode != nullptr) {
        removeValue(currNode->getValue());
        currNode = currNode->getNext();
    }
}

/**
 * @brief Imprime todos os elementos da lista recursivamente.
 */
template <typename T>
void LinkedList<T>::print(){
    printAux(head);
}

/**
 * @brief Auxiliar para a função print. Imprime a lista recursivamente a partir
 * do elemento especificado.
 * 
 * @param curr Primeiro elemento da lista a ser impresso.
 */
template <typename T>
void printAux(Node<T> *curr){
    if(curr != nullptr){
        std::cout << curr->getValue() << std::endl;
        printAux(curr->getNext());
    }
}

template <typename T>
LinkedList<T> LinkedList<T>::operator+(LinkedList<T> &other){
    LinkedList<T> newList;
    newList.add(*this);
    newList.add(other);

    return newList;
}

template <typename T>
const LinkedList<T>& LinkedList<T>::operator>>(Node<T> &node){
    Node<T> *currNode = head;

    while(currNode->getNext() != nullptr){
        currNode = currNode->getNext();
    }

    node = *currNode;
    popBack();

    return *this;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator<<(const Node<T> &node){
    // if(node != nullptr) ?????
    add(node.getValue());
    
    return *this;
}

#endif