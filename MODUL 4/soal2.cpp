#include <iostream>

using namespace std;

typedef int infotype;
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

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != NULL && P->info != x) {
        P = P->next;
    }
    return P;
}

void insertAfter(List &L, address P, address Prec) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info;
        if (P->next != NULL) {
            cout << " -> ";
        }
        P = P->next;
    }
    cout << endl;
}

int main() {
    List L;
    createList(L);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        infotype x;
        cin >> x;
        address P = alokasi(x);
        insertLast(L, P);
    }

    int target;
    cout << "Masukkan elemen yang ingin dicari: ";
    cin >> target;

    int nilaiBaru;
    cout << "Masukkan nilai baru yang akan disisipkan: ";
    cin >> nilaiBaru;

    address Prec = findElm(L, target);

    if (Prec != NULL) {
        address P = alokasi(nilaiBaru);
        insertAfter(L, P, Prec);
    }

    printInfo(L);

    return 0;
}