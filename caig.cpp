//
// Created by Bartosz Mielewczyk on 26.10.2022.
//
#include "iostream"
using namespace std;

int main(){
    float a1=1,an,an1,wynik[12],wieksze=0,srednia;
    cout.precision(7);
    an1 = a1;
    wynik[0] = a1;
    cout <<  "0 " << wynik[0] << endl;
    for (int i = 1; i < 12; ++i) {
        an=1+(1/an1);
        wynik[i]=an;
        an1 = an;
        srednia = srednia + wynik[i];
        if (wynik[i] > 1.618039){
            wieksze++;
        } else {
            cout << i << " " << wynik[i] << endl;

        }

    }
    srednia = srednia/12;
    cout.precision(3);
    cout << srednia << endl;
    cout.precision(7);
    for (float i : wynik) {
        cout << i << " ";
    }
    cout <<endl;
    for (int i = 0; i < 12; ++i) {

        if (wynik[i]>wynik[i-1])cout << "+";
        else cout << "-";
    }
}