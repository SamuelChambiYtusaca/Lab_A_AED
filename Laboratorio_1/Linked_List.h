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
        Linked_List();
        Linked_List(const Linked_List<T> &p);
        Linked_List(Linked_List<T> &&p);
        void remove(T dato);
        void insert(T dato);
        void push_back(T dato);
        void push_front(T dato);
        void pop_front();
        void pop_back();
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
        std::cout << "La lista se encuentra vacia.\n";
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
            std::cout << "El dato '"<< data <<"' no se encuentra en la Lista.\n";
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
        while(ptr){
            cout<<"Nodo "<<i<<": [" << ptr->get_dato() << "]\n";
            ptr = ptr->get_sig();
            i++; 
        }
    }
}



template<typename T>
Linked_List<T>::~Linked_List()
{
}

#endif