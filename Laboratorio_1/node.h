#ifndef _NODE_H_
#define _NODE_H_
template <typename T>
class node{
    private:
        T dato;
        node<T> * sig;
    public:
        node();
        node(T dato);
        node<T>* get_sig();
        T get_dato();
        void set_sig(node<T>*);
        void set_dato(T);
        ~node();
};
template<typename T>
node<T>::node(){
    this->dato = NULL;
    this->sig = nullptr;
}
template<typename T>
node<T>::node(T dato){
    this->dato = dato;
    this->sig = nullptr;
}
template<typename T>
node<T>* node<T>::get_sig(){
    return this->sig;
}
template<typename T>
T node<T>::get_dato(){
    return this->dato;
}
template<typename T>
void node<T>::set_sig(node<T> *siguiente){
    this->sig = siguiente;
    return;
}
template<typename T>
void node<T>::set_dato(T dato){
    this->dato = dato;
    return;
}

template<typename T>
node<T>::~node(){

}
#endif
