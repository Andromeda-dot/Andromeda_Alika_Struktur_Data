#include <iostream>
#include <string>
using namespace std;

string eja(int n) {
        string satuan[] = {"", "satu ", "dua ", "tiga ", "empat ", "lima ", "enam ", "tujuh ", "delapan ", "sembilan ", "sepuluh ", "sebelas "};

        if (n == 0) return "nol";
        if (n < 12) return satuan[n];
        if (n < 20) return satuan[n % 10] + "belas ";
        if (n < 100) return satuan[n / 10] + "puluh " + satuan[n % 10];
        if (n == 100) return "seratus";
        return "";
    }

int main() {
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;
    cout << eja(angka) << endl;
    return 0;
}