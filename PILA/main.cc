#include<iostream>
#include "Pila.h"
using namespace std;

int main(){
    Pila<int> p1;
    p1.push(54);
    p1.push(16);
    p1.push(2);
    p1.push(947);
    p1.push(156);
    p1.push(648);
    p1.reverse_print();
    return 1;
}