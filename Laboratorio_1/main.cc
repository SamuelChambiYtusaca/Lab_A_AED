#include <bits/stdc++.h>
#include "Linked_List.h"
#include "Double_Linked_List.h"
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

    Double_Linked_List<int> L2;
    L2.insert(10);
    L2.insert(100);
    L2.insert(15);
    L2.insert(25);
    L2.insert(94);
    L2.insert(5);
    L2.insert(1);
    L2.insert(250);
    L2.insert(1626);
    L2.print();
    cout << L2.find(74) << "\n";
    return 1;
}
