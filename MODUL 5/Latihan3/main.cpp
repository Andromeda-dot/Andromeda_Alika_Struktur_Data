#include "Singlylist3.h"
#include <iostream>

using namespace std;

int main(){
    List L;
    address P1, P2, P3, P4, P5 = nullptr;
    address found = nullptr;
    infotype x;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> x;
    findElm(L, x, found);
    cout << x << " ditemukan dalam list" << endl;

    int total = totalElm(L);
    cout << "Total info dari kelima elemen dalam list: " << total << endl;

    return 0;
}