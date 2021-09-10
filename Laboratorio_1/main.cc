#include<bits/stdc++.h>
#include"Linked_List.h"
using namespace std;
int main(){
    Linked_List<int> L1;
    L1.push_back(250);
    L1.push_back(271);
    L1.push_back(256);
    L1.push_back(25);
    L1.print();
    if(L1.find(271)){
        cout << "Encontrado\n";
    }else{cout << "Nada\n";}
    L1.remove(271);
    L1.remove(789);
    L1.pop_front();
    L1.pop_back();
    L1.push_front(10);
    L1.insert(1);
    L1.print();
    if(L1.find(271)){
        cout << "Encontrado\n";
    }else{cout << "Nada\n";}
    return 1;
}
