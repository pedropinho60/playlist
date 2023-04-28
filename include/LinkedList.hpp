#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "Node.hpp"

//Essa classe implementa listas encadeadas.
template <typename T>
class LinkedList{

private:
    size_t size;
    Node<T> *head; //Ponteiro para o primeiro elemento da lista
    Node<T> *tail; //Ponteiro para o último elemento da lista

public:
    //Construtor da lista encadeada
    LinkedList();
    void clear();
    size_t getSize();
    Node<T> *getHead();
    Node<T> *getTail();
    void setHead(Node<T> *head);
    void setTail(Node<T> *tail);
    //Adiciona um nó ao fim da lista
    void add(T value);
    //Remove o nó com valor especificado
    void removeIndex(size_t index);
    void removeValue(T value);
    void print();
};

template <typename T>
LinkedList<T>::LinkedList(){
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void LinkedList<T>::clear(){
    Node<T> *prev = nullptr;
    Node<T> *curr = head;

    while(curr != nullptr){
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    head = nullptr;
    tail = nullptr;
}

template <typename T>
size_t LinkedList<T>::getSize(){
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

template <typename T>
void LinkedList<T>::add(T value){
    Node<T> *newNode = new Node<T>(value);

    size++;

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

template <typename T>
void LinkedList<T>::removeIndex(size_t index){
    Node<T> *currNode = head;
    Node<T> *prevNode = nullptr;

    // Verifica se índice é válido
    if(index >= size || index < 0){
        return;
    }

    for(int i=0; i<index; i++){
        prevNode = currNode;
        currNode = currNode->getNext();
    }

    size--;

    if(prevNode != nullptr){
        prevNode->setNext(currNode->getNext());
        if(currNode == tail){
            tail = prevNode;
        }
    }
    else{
        head = currNode->getNext();
        if(head == nullptr){
            tail = nullptr;
        }
    }
    delete currNode;
}

template <typename T>
void LinkedList<T>::removeValue(T value){
    Node<T> *currNode = head;
    Node<T> *prevNode = nullptr;

    while(currNode != nullptr){
        if(currNode->getValue() == value){
            if(prevNode != nullptr){
                prevNode->setNext(currNode->getNext());
                if(currNode == tail){
                    tail = prevNode;
                }
            }
            else{
                head = currNode->getNext();
                if(head == nullptr){
                    tail = nullptr;
                }
            }
            delete currNode;
            return;
        }
        prevNode = currNode;
        currNode = currNode->getNext();
    }
}

template <typename T>
void LinkedList<T>::print(){
    Node<T> *currNode = head;

    while(currNode != nullptr){
        std::cout << currNode->getValue() << std::endl;
        currNode = currNode->getNext();
    }
}

#endif