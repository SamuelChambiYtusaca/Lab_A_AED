#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include "node.h"
#include "iostream"
using namespace std;

template<typename T>
class Linked_List{
    private:
        node<T> *head;
        int size;
    public:
        /*Constructores*/
        Linked_List();/*Defecto*/
        Linked_List(const Linked_List<T> &p);/*Copia*/
        Linked_List(Linked_List<T> &&p);/*Movimiento*/
        /*Funciones miembro*/
        bool find(T dato);/*Retorna un valor que verifique la existencia de un elemento*/
        void remove(T dato);/*Remueve un elemento que se le pase como argumento*/
        void insert(T dato);/*Inserta un elemento de forma ordenada ascedente*/
        void push_back(T dato);/*Inserta elementos al final de la lista*/
        void push_front(T dato);/*Inserta elementos al inicio de la lista*/
        void pop_front();/*Elimina el primer elemento de la lista*/
        void pop_back();/*Elimina el ultimo elemento de la lista*/
        void print();
        ~Linked_List();
};

template<typename T>
Linked_List<T>::Linked_List(){
    this->head = nullptr;
    this->size = 0;
}

template<typename T>
Linked_List<T>::Linked_List(const Linked_List<T> &p){
    node<T> *aux = p.head;
    this->head = nullptr;
    this->size = 0;
    while(aux){
        this->push_back(aux->get_dato());
        aux = aux->get_sig();
    }
}

template<typename T>
Linked_List<T>::Linked_List(Linked_List<T> &&p){
    this->head = p.head;
    this->size = p.size;
    p.head = nullptr;
    p.size = 0;
}

template<typename T>
void Linked_List<T>::push_front(T dato){
    node<T> *new_node = new node<T>(dato);
        if(head==nullptr){
            head = new_node;
        }else{
            node<T> *Inicio = head;
            head = new_node;
            head->set_sig(Inicio);  
        }
        size++;
}

template<typename T>
void Linked_List<T>::push_back(T dato){
    node<T> *new_node = new node<T>(dato);
    node<T> *temp = head;
    if(this->head==nullptr){
        this->head = new_node;
    }else{
        while(temp->get_sig()!=nullptr){
            temp = temp->get_sig();
        }
        temp->set_sig(new_node);
    }
    size++;
}

template<typename T>
void Linked_List<T>::pop_front(){
    if(!this->head){
        cout << "La lista esta vacia.\n";
    }else{
        node<T> *nuevo = this->head->get_sig();
        delete head;
        head = nuevo;
    }
    size--;
}

template<typename T>
void Linked_List<T>::pop_back(){
    if(!this->head){
        cout << "La lista esta vacia.\n";
    }else if(size == 1){
        delete head;
        this->head = nullptr;
    }else{
        node<T> *act = this->head;
        node<T> *ant;
        while(act->get_sig()){
            ant = act;
            act = act->get_sig();
        }
        ant->set_sig(nullptr);
        delete act;
    }
    size--;
}

template<typename T>
bool Linked_List<T>::find(T dato){
    if(!this->head){
        cout << "La lista se encuentra vacia\n";
        return false;
    }else{
        node<T>*ptr = this->head;
        while(ptr){
            if(ptr->get_dato()==dato){
                return true;
            }else{
                ptr = ptr->get_sig();
            }
        }
        return false;
    }
}

template<typename T>
void Linked_List<T>::insert(T dato){
    node<T> *new_node = new node<T>(dato);
    node<T> *temp = this->head;
    if(!this->head){
        this->head = new_node;
    }else{
        if (this->head->get_dato() > dato) {
            new_node->set_sig(this->head);
            this->head = new_node;
        } else {
            while ((temp->get_sig() != NULL) && (temp->get_sig()->get_dato() < dato)) {
                temp=(temp->get_sig());
            }
            new_node->set_sig(temp->get_sig());
            temp->set_sig(new_node);
        }
    }
    size++;
}

template<typename T>
void Linked_List<T>::remove(T data){
    node<T> *temp = this->head;
    node<T> *temp2 = this->head->get_sig();
    if(!temp){
        cout << "La lista se encuentra vacia.\n";
        return;
    }
    else{
        if(temp->get_dato()==data){
            this->pop_front();
            return;
        }
        else{
            while(temp2){
                if(temp2->get_dato()==data){
                    temp->set_sig(temp2->get_sig());
                    delete temp2;
                    size--;
                    return;
                }
                temp = temp->get_sig();
                temp2 = temp2->get_sig();
            }
            cout << "El dato '"<< data <<"' no se encuentra en la Lista.\n";
            return;
        }
    }
}

template<typename T>
void Linked_List<T>::print(){
    node<T> *ptr = head;
    if(!head){
        cout << "La lista esta vacia.\n";
    }else{
        int i = 1;
        while(i<this->size){
            cout<<"[" << i << ":" << ptr->get_dato() << "]->";
            ptr = ptr->get_sig();
            i++; 
        }
        cout << "[" << i << ":" << ptr->get_dato() << "]\n";
        return;
    }
}

template<typename T>
Linked_List<T>::~Linked_List(){
    while(this->size){
        this->pop_back();
    }
    delete head;
}

#endif
