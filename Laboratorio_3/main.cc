#include <iostream>
#include "Circle_List.h"
using namespace std;

int main(){
    Circle_List<int> L1;
    L1.push_back(64);
    L1.push_back(3);
    L1.push_back(84);
    cout << "Lista 1:\n";
    L1.printT();
    Circle_List<int> L2;
    L2.push_back(789);
    L2.push_back(97);
    L2.push_back(314);
    cout << "Lista 2:\n";
    L2.printT();
    Circle_List<int> L3;
    L3 = L1 + L2;
    cout << "Lista 3:\n";
    cout << "Ascendente: "; L3.printT();
    cout << "Descendente: ";L3.printD();
    cout << "Comprobacion de funciones implementadas:\n";
    cout << L3.find(84) << "\n";
    L3.erase(3);
    cout << L3.find(3) << "\n";
    return 1; 
}
