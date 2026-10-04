#include <iostream>
using namespace std;

int main() {
    int N ;
    cin >> N ;

    int nilai[N] ;
    int total = 0 ;

    for (int i = 0; i < N; i++) {
        cin >> nilai[i] ;
        total += nilai[i] ;
    }

    int rata_rata = total / N ;

    int diatas_rata_rata = 0 ;
    for (int i = 0; i < N; i++) {
        if (nilai[i] > rata_rata) {
            diatas_rata_rata++ ;
        }
    }

    cout << "Rata-rata: " << rata_rata << endl ;
    cout << "Di atas rata-rata: " << diatas_rata_rata << endl ;

    return 0 ;
}