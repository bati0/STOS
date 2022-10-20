//L3_F1_S2.cpp          ITERACJE - Rysowanie kafelkow

#include<iostream>

using namespace std;

int main() {
    const int n_Max = 79;
    char zn1 = '#';
    char zn2 = '-';
    int k1;                    // ilosc  zn1  w aktualnym wierszu kafelka
    int k2;                    // ilosc  zn2  w aktualnym wierszu kafelka
    int n;                     // ilosc wierszy w kafelku
    int w;                     // numer wiersza rysowanego
    int ile_pionowo;         // ilosc kafalkow w pionie                  //333
    int ile_poziomo;         // ilosc kafelkow w poziomie                //333

    cout << "Podaj rozmiar kafelka n [1," << n_Max << "] :";
    cin >> n;
    if (n % 2 == 0 or n > 79 or n < 1) {            //111
        cout << "zle dane" << endl;
        system("pause");
        return 0;
    }
    cout << "Podaj ilosc kafelkow w poziomie i w pionie  [1," << 80 / n << "] : \n";  //333
    cin >> ile_poziomo;                                                         //333
    cin >> ile_pionowo;                                                         //333


    for (int i = 0; i < ile_pionowo; ++i) {
        w = n / 2;//111             numer wiersza pocz¹tkowego
        k2 = w;                      //111            ilosc  '-'  w aktualnym wierszu kafelka
        k1 = n - 2 * k2;//111            ilosc  '#'  w aktualnym wierszu kafelka
        while (abs(w) <= n / 2)            //111    petla dziala dla w zakresie od n/2 do 0     //222
        {

            for (int i = 0; i < ile_poziomo; ++i) {
                for (int i = 0; i < k2; ++i) cout << "-";//111    znaki '-'
                for (int i = 0; i < k1; ++i) cout << "#";//111    znaki '#'
                for (int i = 0; i < k2; ++i) cout << "-";//111    znaki '-'
            }
            cout << endl;
            //111    przejdz do nowej linii
            w--;                 // zmiana numeru wiersza
            // ustalenie ilosci zn1 i zn2 dla kolejnego wiersza kafelka
            k2 = abs(w);                   //111                                           //222
            k1 = n - (2 * k2);                   //111

        }
    }
    system("pause");
    return 0;
}
