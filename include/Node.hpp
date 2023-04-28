#ifndef NODE_HPP
#define NODE_HPP

// @brief Essa classe representa um nó de uma lista encadeada
template <typename T>
class Node{

    T value; //Valor do nó atual da lista encadeada
    Node<T> *next; //Ponteiro para o próximo nó da lista encadeada

public:
    //Construtor que recebe o valor a ser colocado no nó
    Node(const T &value);
    //Retorna o valor do nó atual
    T getValue();
    //Retorna o ponteiro para o próximo nó
    Node *getNext();
    //Altera o valor do nó atual
    void setValue(T value);
    //Altera o ponteiro para o próximo nó
    void setNext(Node<T> *next);
};

template <typename T>
Node<T>::Node(const T &value){
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

#endif