#include <iostream>
#include <string>

using namespace std;

typedef string infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        insertFirst(L, P);
    } else {
        address Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first != NULL) {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void printQueue(List L) {
    if (L.first == NULL) {
        cout << "Antrean: Kosong" << endl;
    } else {
        address P = L.first;
        cout << "Antrean: ";
        while (P != NULL) {
            cout << P ->info;
            if (P ->next != NULL) {
                cout << " -> ";
            };
            P = P ->next;
        }
        cout << endl;
    }
}

int main() {
    List L;
    createList(L);
    int pilihan;
    string nama;

    do {
        cout << "Pilihan: ";
        cin >> pilihan;
        if (pilihan == 1) {
            cout << "Masukkan nama: ";
            cin >> nama;
            address P = alokasi(nama);
            insertLast(L, P);
            printQueue(L);
        } else if (pilihan == 2) {
            address P;
            deleteFirst(L, P);
            if (P != NULL) {
                cout << "Nama yang keluar: " << P->info << endl;
                dealokasi(P);
            } else {
                cout << "Antrean kosong" << endl;
            }
            printQueue(L);
        } else if (pilihan == 3) {
            cout << "Keluar dari program." << endl;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 3);
}