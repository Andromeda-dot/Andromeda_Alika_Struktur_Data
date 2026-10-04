#include <iostream>
using namespace std;

void tukarValue(int x, int y) {
    int temp = x ;
    x = y ;
    y = temp ;
}

void tukarPointer(int *px, int *py) {
    int temp = *px ;
    *px = *py ;
    *py = temp ;
}

void tukarReference(int &px, int &py) {
    int temp = px ;
    px = py ;
    py = temp ;
}

int main() {
    int a = 4, b = 6 ;

    cout << "Kondisi Awal -> a: " << a << " b: " << b << endl;

    tukarValue(a, b) ;
    cout << "Setelah tukarValue -> a: " << a << " b: " << b << endl;

    tukarPointer(&a, &b) ;
    cout << "Setelah tukarPointer -> a: " << a << " b: " << b << endl;

    tukarReference(a, b) ;
    cout << "Setelah tukarReference -> a: " << a << " b: " << b << endl;

    return 0;
}