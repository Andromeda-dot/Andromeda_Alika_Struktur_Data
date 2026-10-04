#include <iostream>
#include <string>
using namespace std;

int kembalikanNilai(string kata, char target) {
    int jumlah = 0 ;

    for (int i = 0; i < kata.length(); i++) {
        if (kata[i] == target) {
            jumlah++ ;
        }
    }
    return jumlah ;
}

int main() {
    string kata ;
    char target ;

    cin >> kata ;
    cin >> target ;

    cout << kembalikanNilai(kata, target) << endl ;

    return 0 ;
}