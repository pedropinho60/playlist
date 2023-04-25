#include "Node.hpp"
#include <iostream>

template <typename T>
Node<T>::Node(const T value){
    setValue(value);
    setNext(nullptr);
}

template <typename T>
T Node<T>::getValue(){
    return value;
}

template <typename T>
Node<T> *Node<T>::getNext(){
    return next;
}

template <typename T>
void Node<T>::setValue(T value){
    this->value = value;
}

template <typename T>
void Node<T>::setNext(Node<T> *next){
    this->next = next;
}

template class Node<int>;