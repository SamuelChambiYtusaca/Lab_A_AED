#ifndef COLA_H
#define COLA_H

#include "node.h"
#include "iostream"
template<typename T>
class Cola
{
    private:
        node<T> *head;
        int size;
    public:
        Cola();
        void enqueue(T);
        void dequeue();
        node<T> * get_h();
        ~Cola();

};
template <typename T>
Cola<T>::Cola(){
    this->head = nullptr;
    this->size = 0;
}

template<typename T>
void Cola<T>::enqueue(T dato){
    node<T>*nuevo = new node<T>(dato);
    if(!this->head)
        head = nuevo;
    else{
        node<T>*aux = head;
        while(aux->get_sig()){
            aux = aux->get_sig();
        }
        aux->set_sig(nuevo);
    }
    size++;
    return;
}

template<typename T>
void Cola<T>::dequeue(){
    if(!this->head)
        return;
    else{
        node<T>*aux = this->head->get_sig();
        delete head;
        head = aux;
        size--;
        return;
    }
}

template <typename T>
node<T>* Cola<T>::get_h(){
    return this->head;
}

template <typename T>
Cola<T>::~Cola(){
    while(this->size)
        this->dequeue();
    delete head;
}
#endif // COLA_H
