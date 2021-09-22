/*
    Fecha: 21-09-2021
    Autores: 
    - Samuel Felipe Chambi Ytusaca
    - Erick Hualla Puelles
    - Angela Aquise Santos
    - Moises Alejandro Casaverde Aleman
*/

#ifndef _PILA_H_
#define _PILA_H_

#include "Node.h"

template <typename T>
class Pila
{
    private:
        Node<T> *m_pTop;
        Node<T> *m_pEnd;
        int size;
    public:
        Pila();
        ~Pila();
        bool is_empty();
        bool push(T data);
        bool pop();
        T top();
        void reverse_print();
};

template<typename T>
Pila<T>::Pila(){
    this->m_pTop = nullptr;
    this->m_pEnd = nullptr;
    this->size = 0;
}

template <typename T>
bool Pila<T>::is_empty()
{
    if(!this->m_pTop)
    {
        return true;
    }
    return false;
}

template<typename T>
bool Pila<T>::push(T data){
    Node<T> * new_node = new Node<T>(data);
    Node<T> * aux = this->m_pTop;
    this->m_pTop = new_node;
    new_node->next = aux;
    if (!this->m_pTop){
        new_node->next = aux;
    }
    this->size++;
    return true;
}

template <typename T>
bool Pila<T>::pop(){
    if(!this->m_pTop)
        return false;
    else{
        Node<T> *aux = this->m_pTop->next;
        delete m_pTop;
        this->m_pTop = aux;
        this->size--;
        return true;
    }
}

template<typename T>
void Pila<T>::reverse_print()
{
    Pila<T> new_stack = *this;
    while(new_stack.m_pTop)
    {
        std::cout << new_stack.top() << '\n';
        new_stack.pop();
    }
}

template <typename T>
T Pila<T>::top() {
    if (m_pTop)
        return m_pTop->data;
    return NULL;
}
template<typename T>
Pila<T>::~Pila()
{
}
#endif