// L3_F1_S1.cpp  Program oblicza n kolejnych wyrazow ciagu Fibonacciego

#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    int n;                              // ilosc wyrazow ciagu [1,47]
    unsigned long int F;                // wartosc biezacego elementu ciagu
    unsigned long int F_i_minus_1;      // wartosc elementu F(i-1)
    unsigned long int F_i_minus_2;      // wartosc elementu F(i-2)
    int i;                              // licznik wyrazow ciagu

    cout << "Podaj ile wyrazow ciagu Fibonacciego obliczyc:";
    cin >> n;

    if (n <= 0 or n > 47) cout << "Liczba wyrazow powinna byc w przedziale [1,47]" << endl;
    else {
        if (n == 1) {
            cout << setw(15) << "1" << endl;
            i = 1;
        } else if (n == 2) {
            cout << setw(15) << "1" << setw(15) << "1" << endl;
            i = 2;
        } else {                    // dla n >= 2
            F_i_minus_1 = 1;                                     //$$$  wpisz dane
            F_i_minus_2 = 1;                                     //$$$  poczatkowe
            cout << setw(15) << "1" << setw(15) << "1";                               //$$$  wypisz je na ekranie

            for (i = 3; i < n; i++)                                                           //$$$ przygotuj petle
            {
                F = F_i_minus_1 + F_i_minus_2;                                            //$$$ oblicz wartosc F
                cout << setw(15) << F;
                if (i % 5 == 0) cout << endl;                      //$$$ po kazdej piatce liczb przejdz do nast. linii
                F_i_minus_2 = F_i_minus_1;                      //$$$ przygotuj wartosci zmiennych F_i_minus_1 oraz
                F_i_minus_1 = F;                                //$$$ F_i_minus_2 do kolejnej iteracji. Kolejnosc ?
            }
        }
        cout << "\nLiczba wypisanych wyrazow = " << i - 1 << endl;
    }

    system("pause");
    return 0;
}
