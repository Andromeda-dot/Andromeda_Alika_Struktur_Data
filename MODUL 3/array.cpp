#include <iostream>

using namespace std;

void tampilkanArray2D(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j =0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray2D(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *px, int *py) {
    int temp = *px ;
    *px = *py ;
    *py = temp ;
}

int main() {
    int array1[3][3];
    int array2[3][3];
    int nilaiA;
    int nilaiB;
    int r;
    int c;

    cout << "Masukkan nilai A: ";
    cin >> nilaiA;
    cout << "Masukkan nilai B: ";
    cin >> nilaiB;

    int *px = &nilaiA;
    int *py = &nilaiB;

    cout << "Input Array 1: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> array1[i][j];
        }
    }

    cout << "Input Array 2: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> array2[i][j];
        }
    }

    cout << "MENUKAR ISI 2 VARIABEL:" << endl;
    cout << "Sebelum ditukar -> *px = " << *px << ", *py = " << *py << endl;
    tukarPointer(px, py);
    cout << "Setelah ditukar -> *px = " << *px << ", *py = " << *py << endl;

    cout << "\n-----------------------------------" << endl;
    cout << "Array 1:" << endl;
    tampilkanArray2D(array1);
    
    cout << "\nArray 2:" << endl;
    tampilkanArray2D(array2);

    cout << "\nMasukkan indeks posisi yang ingin ditukar:" << endl;
    cout << "Baris ke-: ";
    cin >> r;
    cout << "Kolom ke-: ";
    cin >> c;

    if (r >= 0 && r < 3 && c >= 0 && c < 3) {
        tukarArray2D(array1, array2, r, c);

        cout << "\nHASIL SETELAH DITUKAR PADA [" << r << "][" << c << "] " << endl;
        cout << "Array 1:" << endl;
        tampilkanArray2D(array1);
        
        cout << "\nArray 2:" << endl;
        tampilkanArray2D(array2);
    } else {
        cout << "Indeks baris atau kolom tidak valid! Harus antara 0 sampai 2." << endl;
    }

    return 0;
}