#ifndef NODE_H
#define NODE_H

template <typename T>
class Pila;

template <typename T>
class Node
{
private:
    T data;
    Node<T>* next;
    friend class Pila<T>;
public:
    //Constructor
    Node<T>(T data);
    Node<T>* getSig();
    T get_Dato();
    ~Node<T>();
};

template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr;
}

template <typename T>
Node<T>* Node<T>::getSig(){
    return this->next;
}

template <typename T>
T Node<T>::get_Dato(){
    return this->data;
}

template <typename T>
Node<T>::~Node(){
    
}

#endif  //NODE_H