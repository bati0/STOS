//
// Created by Bartek on 13.10.2022.
//
#include <iostream>
using namespace std;

int main(){
    float p, c;
    cout << "cena pojazdu" << endl;
    cin >> c;
    cout << "zuzycie paliwa:" << endl;
    cin >>  p;
    if (c<60){
        if (p<7.5){
            cout << "pojazd niedrogi i oszczedny";
        } else {
            cout << "pojazd niedrogi i nieoszczedny";
        }
    } else {
        if (p<7.5){
            cout << "pojazd drogi i oszczedny";
        } else {
            cout << "pojazd drogi i nieoszczedny";
        }
    }

}