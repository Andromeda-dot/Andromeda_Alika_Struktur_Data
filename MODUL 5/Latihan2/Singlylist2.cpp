#include "Singlylist2.h"
#include <iostream>

using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;

    P->info = x;
    P->next = nullptr;

    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void printInfo(List L) {
    address P = L.First;

    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }

    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void findElm(List L, infotype x, address &P) {
    P = L.First;

    while (P != nullptr && P->info != x) {
        P = P->next;
    }
}