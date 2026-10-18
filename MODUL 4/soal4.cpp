#include <iostream>
#include <string>

using namespace std;

struct Buku {
    string judul;
    int tahunTerbit;
};

typedef Buku infotype;
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

void deleteLast(List &L, address &P) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            P = L.first;
            L.first = NULL;
        } else {
            address Q = L.first;
            while (Q->next->next != NULL) {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = NULL;
        }
    }
}

void printInfo(List L) {
    address P = L.first;
    cout << "Daftar Buku: " << endl;
    while (P != NULL) {
        cout << P->info.judul << "(" << P->info.tahunTerbit << ")" << endl;
        P = P->next;
    }
}

int main() {
    List L;
    createList(L);

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        
        size_t lastSpace = line.find_last_of(' ');
        if (lastSpace != string::npos) {
            string judul = line.substr(0, lastSpace);
            int tahun = stoi(line.substr(lastSpace + 1));
            
            address P = alokasi({judul, tahun});
            insertLast(L, P);
        }
    }

    address BukuDihapus;
    deleteLast(L, BukuDihapus);
    if (BukuDihapus != NULL) {
        delete BukuDihapus;
    }

    printInfo(L);

    return 0;
}