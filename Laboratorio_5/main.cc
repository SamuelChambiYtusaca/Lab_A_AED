#include<iostream>
#include "Binary_Tree.h"
using namespace std;
int main(){
    Binary_Tree<int> arbol;
    /*Insercion de elementos al arbol Binario*/
    arbol.add(21);
    arbol.add(15);
    arbol.add(25);
    arbol.add(10);
    arbol.add(17);
    arbol.add(24);
    arbol.add(27);
    arbol.add(7);
    arbol.add(11);
    arbol.add(23);
    arbol.add(26);
    arbol.add(28);
    /*Implementacion de los Metodos*/
    cout << "Altura del arbol: " << arbol.altura(21) << "\n";
    cout << "Peso del arbol: " << arbol.peso() << "\n";
    arbol.sucesores(10);
    arbol.sucesores(25);
    arbol.antecesores(23);
    cout << "Altura del nodo 7: " << arbol.altura(7) << "\n";
    cout << "Altura del nodo 10: " << arbol.altura(10) << "\n";
    cout << "Altura del nodo 25: " << arbol.altura(25) << "\n";    
    cout << "\nRecorrido preOrder:\n";
    arbol.preOrder();
    cout << "\nRecorrido inOrder:\n";
    arbol.inOrder();
    cout << "\nRecorrido postOrder:\n";
    arbol.postOrder();
    return 1;
}