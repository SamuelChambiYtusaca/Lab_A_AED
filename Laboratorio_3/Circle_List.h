#ifndef _CIRCLE_LIST_H_
#define _CIRCLE_LIST_H_
#include "NodoD.h"
#include <iostream>
using namespace std;
template <typename T>
class Circle_List{
    private:
        NodoD<T> *head;
        NodoD<T> *last;
        int size;
    public:
        Circle_List<T>();
        Circle_List<T>(const Circle_List<T> &p);
        Circle_List<T>(Circle_List<T> &&p);
        void push_back(T dato);
        bool find(T dato);
        void erase(T dato);
        void printT();
        void printD();
};

template<typename T>
Circle_List<T>::Circle_List(){
    this->head = nullptr;
    this->last = nullptr;
    this->size = 0;
}

template <typename T>
void Circle_List<T>::push_back(T dato){
    NodoD<T> *nuevo = new NodoD<T>(dato);
    if(!this->head){
       this->head = nuevo;
       this->last = nuevo;
    }else{
       NodoD<T> *aux = this->head;
       while(aux->get_sig()!=head){
           aux = aux->get_sig();
       }
       this->last = nuevo;
       aux->set_sig(last);
    }
    this->last->set_sig(head);
    this->head->set_ant(last); 
    size++;    
}























#endif
