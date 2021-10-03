#ifndef _PILA_H_
#define _PILA_H_
#include "node.h"
#include <iostream>
template <typename T>
class Pila
{
   private:
        node<T> *m_pTop;
        node<T> *m_pEnd;
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
template <typename T>
Pila<T>::Pila(){
    this->m_pTop = nullptr;
    this->m_pEnd = nullptr;
    this->size = 0;
}

template <typename T>
bool Pila<T>::is_empty(){
    return !this->m_pTop;
}

template<typename T>
bool Pila<T>::push(T data){
    node<T> * new_node = new node<T>(data);
    node<T> * aux = this->m_pTop;
    this->m_pTop = new_node;
    new_node->set_sig(aux);
    if (!this->m_pTop){
        new_node->set_sig(aux);
    }
    this->size++;
    return true;
}

template <typename T>
bool Pila<T>::pop(){
    if(!this->m_pTop)
        return false;
    else{
        node<T> *aux = this->m_pTop->get_sig();
        delete m_pTop;
        this->m_pTop = aux;
        this->size--;
        return true;
    }
}

template<typename T>
void Pila<T>::reverse_print(){
    Pila<T> new_stack = *this;
    while(new_stack.m_pTop){
        std::cout << new_stack.top() << '\n';
        new_stack.pop();
    }
}

template <typename T>
T Pila<T>::top() {
    if (m_pTop)
        return m_pTop->get_dato();
    return NULL;
}

template <typename T>
Pila<T>::~Pila(){

}


#endif