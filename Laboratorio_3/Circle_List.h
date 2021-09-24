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
        void push_back(T dato);
        bool find(T dato);/*Indicador de existencia*/
        void erase(T dato);/*Borrar dato por valor*/
        void printT();/*Print ascendente*/
        void printD();/*Print descendente*/
        int get_size();
        /*Sobrecarga de Operadores*/
        const Circle_List<T> &operator= (const Circle_List<T> &);
        Circle_List<T> operator+ (const Circle_List<T> &); /*Concatenacion de listas con sobrecarga de operador de adicion*/ 
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
        this->head->set_sig(head);
        this->head->set_ant(last);
    }else{
        this->last->set_sig(nuevo);
        nuevo->set_ant(last);
        nuevo->set_sig(head);
        this->last = nuevo;
        this->head->set_ant(last);
    }    
    size++;
    return; 
}

template<typename T>
bool Circle_List<T>::find(T dato){
    if(!this->head)
        return false;
    if(this->head->get_dato() == dato)
        return true;
    else{
        NodoD<T> *aux = this->head->get_sig();
        while(aux != this->head){
            if(aux->get_dato() == dato)
                return true;
            aux = aux->get_sig();
        }
        return false;
    }
}

template<typename T>
void Circle_List<T>::erase(T dato){
    if(!this->head)
        return;
    if(!find(dato))
        return;
    else{
        NodoD<T> *aux = this->head;
        if(aux->get_dato()==dato){
            if(size==1){
                delete head;
                head = nullptr;
                last = nullptr;
                size--;
                return;
            }
            aux = this->head->get_sig();
            delete head;
            head = aux;
            head->set_ant(last);
            last->set_sig(head);
        }else if(this->last->get_dato() == dato){
            aux = last->get_ant();
            delete last;
            last = aux;
            head->set_ant(last);
            last->set_sig(head);
        }else{
            aux = aux->get_sig();
            while(aux != head){
                if(aux->get_dato() == dato){
                    NodoD<T> *aux2 = aux->get_sig();
                    NodoD<T> *aux3 = aux->get_ant();
                    delete aux;
                    aux2->set_ant(aux3);
                    aux3->set_sig(aux2);
                    size--;
                    return;
                }
                aux = aux->get_sig();
            }
        }
        size--;
        return;   
    }
}

template<typename T>
int Circle_List<T>::get_size(){
    return this->size;
}

template<typename T>
void Circle_List<T>::printT(){
    if(!this->head)
        return;
    else{
        NodoD<T> *aux = this->head;
        while(aux != last){
            cout << "[" << aux->get_dato() << "]->";
            aux = aux->get_sig();
        }
        cout << "[" << aux->get_dato() << "]\n";
        return;
    }
}

template<typename T>
void Circle_List<T>::printD(){
    if(!this->head)
        return;
    else{
        NodoD<T> *aux = this->last;
        while(aux != head){
            cout << "[" << aux->get_dato() << "]->";
            aux = aux->get_ant();
        }
        cout << "[" << aux->get_dato() << "]\n";
        return;
    }
}

template<typename T>
const Circle_List<T> &Circle_List<T>:: operator= (const Circle_List<T> &p){
    NodoD<T> *aux{nullptr};
    while(this->head){
        this->last->set_sig(nullptr);
        aux = this->head->get_sig();
        delete head;
        head = aux;
    }
    aux = p.head;
    this->push_back(aux->get_dato());
    aux = aux->get_sig();
    while(aux != p.head){
        this->push_back(aux->get_dato());
        aux = aux->get_sig();
    }
    return *this;
}

template<typename T>
Circle_List<T> Circle_List<T>::operator+ (const Circle_List<T> &p){
    Circle_List<T> nueva;
    NodoD<T> *aux = this->head;
    nueva.push_back(aux->get_dato());
    aux = aux->get_sig();
    while(aux!=head){
        nueva.push_back(aux->get_dato());
        aux = aux->get_sig();
    }
    aux = p.head;
    nueva.push_back(aux->get_dato());
    aux = aux->get_sig();
    while(aux != p.head){
        nueva.push_back(aux->get_dato());
        aux = aux->get_sig();
    }
    return nueva;
}

#endif
