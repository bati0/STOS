//
// Created by Bartosz Mielewczyk on 20.10.2022.
//
#include "iostream"
using namespace std;

int main() {
    int n;
    float wpis = 0.1;                   //program z założenia przyjmuje tylko liczby całkowite więc na pierwszym kroku inicjalizuję zmienną wpis z wartością poza przyjmowanymi
    cin >> n;
    while (n != wpis) {
        wpis = n;
        cout << wpis << endl;
        cin >> n;
        if (n == wpis) cout << "KONIEC";
    }
}
