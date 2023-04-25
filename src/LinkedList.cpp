#include <iostream>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Musica.hpp"
#include "Playlist.hpp"

template <typename T>
LinkedList<T>::LinkedList(){
    size = 0;
    head = nullptr;
    tail = nullptr;
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

// template <typename T>
// void LinkedList<T>::removeNode(size_t index){
//     Node<T> *currNode = head;
//     Node<T> *prevNode = nullptr;

//     for(size_t i=0; i<index; i++){
//         if(currNode == nullptr){
//             return;
//         }
//         prevNode = currNode;
//         currNode = currNode->getNext();
//     }
    
//     if(currNode != nullptr){
//         if(prevNode != nullptr){
//             prevNode->setNext(currNode->getNext());
//         }
//         else{
//             head = currNode->getNext();
//         }
//         delete currNode;
//     }
// }

template <typename T>
void LinkedList<T>::print(){
    Node<T> *currNode = head;

    while(currNode != nullptr){
        std::cout << currNode->getValue() << std::endl;
        currNode = currNode->getNext();
    }
}

template class LinkedList<Musica>;
template class LinkedList<Playlist>;