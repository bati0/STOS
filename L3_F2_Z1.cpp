//
// Created by Bartosz Mielewczyk on 20.10.2022.
//
#include "iostream"
using namespace std;

int main(){
    int n,  ilosc_parzystch = 0,    ilosc_cyfr = 0, liczba;
    cout << "Podaj liczbe z zakresu [1;99999999]:";
    cin >> n;
    if (n<1 or n>99999999){
        cout << "liczba spoza zakresu" << endl;
        system("pause");
        return 0;
    }
    liczba = n;
    while (n>0){
        if ((n%10)%2==0) ilosc_parzystch++;
        ilosc_cyfr++;
        n=n/10;
    }
    cout << liczba << " sklada sie z " << ilosc_cyfr << " cyfr(y) w tym " << ilosc_parzystch << " parzystych";
    return 0;
}