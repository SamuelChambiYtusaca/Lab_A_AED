#include <iostream>
#include "Cola.h"
#include "Pila.h"
using namespace std;
int main(){
    Cola<int> c1;
    Pila<string> p1;
    c1.enqueue(664);
    c1.enqueue(54);
    c1.enqueue(21);
    c1.enqueue(749);
    c1.print();
    c1.dequeue();
    c1.print();
    c1.enqueue(31);
    c1.print();
    p1.push("Hola");
    p1.push("amiguitos");
    p1.push("de todo el Mundo");
    p1.reverse_print();
    return 1;
}