//
// Created by Bartek on 13.10.2022.
//
#include "iostream"
#include "cmath"

using namespace std;
int main(){
    double x[10]={-10,-5,-1,-0.5,-0,0.4, 1, 2.5,4,8.5},wynik;
    for (int i = 0; i < 10; ++i) {
        if(x[i] >=-9.5 && x[i] <= -1 || x[i] >= 1 && x[i] < 4) {

                wynik = log(4 - x[i]) + sqrt(pow(x[i], 2) - 1) + pow((x[i] + 9.5), 0.25);
                cout << wynik << endl;

        } else cout << x[i] << " f(x) nieokreslona" << endl;
    }
}