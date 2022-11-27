//Bartosz Mielewczyk s193313 gr5
#include<iostream>
#include "cmath"
#include "time.h"
#include "stdlib.h"
#include <fstream>

using namespace std;
int losowaliczba(int pocz, int koniec)
{
    return rand()%(koniec-pocz+1) + pocz;
}
void nowaTablica(){

}
void zapisz_do_pliku(int *tab) {
    cout << tab[1];
    ofstream plik("bartosz.mielewczyk.s193313.5.txt");
    if (!plik){
        cout << "Plik nie zostal zapisany!\n";
    } else {
        for (int i = 0; i < 10; ++i) {
            plik << "[" << i << "]  " << tab[i] << endl;
        }
        plik.close();
    }

}
void histogram(int *tab,int wielkosc)
{
    int tablica[10]={0,0,0,0,0,0,0,0,0,0};

    for(int i=0; i < wielkosc; i++){
        switch (tab[i]){
        case 0: tablica[0] +=1;
            break;
        case 1: tablica[1] +=1;
            break;
        case 2: tablica[2] +=1;
            break;
        case 3: tablica[3] +=1;
            break;
        case 4: tablica[4] +=1;
            break;
        case 5: tablica[5] +=1;
            break;
        case 6: tablica[6] +=1;
            break;
        case 7: tablica[7] +=1;
            break;
        case 8: tablica[8] +=1;
            break;
        case 9: tablica[9] +=1;
            break;

        }

    }
    cout << tablica[1] << " " << tablica[9] << endl;
    zapisz_do_pliku(tablica);
}


int main()
{
    srand(time(NULL));
    int wtablicy = losowaliczba(1000,2000);
    int *tab = new int[wtablicy];

    for (int i=0; i < wtablicy; i++){
        tab[i] = losowaliczba(0,9);
    }
    histogram(tab,wtablicy);


    delete [] tab;

}
