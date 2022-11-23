#include<iostream>
#include "cmath"
#include "time.h"
#include "stdlib.h"
using namespace std;

struct punkt{
	double x;
	double y;
};

int wypisz(punkt *wskp){
	cout << wskp->x << " " << wskp->y << endl;
	return 0;
}

double odl(punkt *wsk_pkt){
    return sqrt(wsk_pkt->x*wsk_pkt->x+ wsk_pkt->y*wsk_pkt->y);
}
int wypisz_tab(punkt *wskp, int liczba){
	for(punkt *temp = wskp; temp < wskp + liczba; temp++)
		wypisz(temp);
    cout << endl;
    return 0;
}

int wypisz_odl(punkt *tablica, int liczba_N)
{
    for (int i = 0; i < liczba_N; ++i) {
        wypisz(tablica + i);
        cout << "odl od (0,0): " << odl(tablica+i) << endl;
    }
    return 0;
}

int wypisz_odl_mniejsze(punkt *tablica, int liczba_N, double r)
{
    for (int i = 0; i < liczba_N; ++i) {
        if (odl(tablica+i)<r) wypisz(tablica + i);
    }
    return 0;
}

int zamiana(punkt *tablica, punkt *tablica1)
{
    double x,y;
    x = (*tablica).x;
    y = (*tablica).y;
    (*tablica) = (*tablica1);
    (*tablica1).x = x;
    (*tablica1).y = y;
    return 0;
}

int wypelnij(punkt *tab,int size){
    srand(time(NULL));
    for(int i = 0; i < size; ++i){
        (*(tab+i)).x = rand()%10;
        (*(tab+i)).y = rand()%20;
    }
    return 0;
}

int main(){

	punkt *tab;
	tab = new punkt[3];
	tab[0].x = tab[0].y = 0;
	(*(tab+1)).x = 1;
	(*(tab+1)).y = 2;
	(tab+2)->x = 4;
	(tab+2)->y = 6.5;

    int wymiar = 3; //rozmiar

    punkt *tablica = new punkt[wymiar];
    wypelnij(tablica,wymiar);


    cout << "tablica oryginalna:" << endl;
	wypisz_tab(tab,3);
    cout << endl;

    cout << "A) tablica z odleglosciami od pocz ukl wsp:" << endl;
    wypisz_odl(tab,3); //wypisuje odleglosci dla punktow o danych wsp od pocz ukl wsp
    cout << endl;

    cout << "B) tablica z odleglosciami MNIEJSZYMI OD parametru r (3) od pocz ukl wsp:" << endl;
    wypisz_odl_mniejsze(tab, 3, 3); // z tablicy "tab", wielkosci "liczba_N", o odległości mniejszej niz "r"
    cout << endl;

    cout << "C) tablica z punktami z pewnego prostokata" << endl;
    cout  << wypisz_tab(tablica,wymiar);


    cout << "D) tablica z zamienionymi punktami podanymi jako parametry:" << endl;
    zamiana(&tab[0],&tab[1]);
    cout <<  wypisz_tab(tab,3)<< endl;

    delete [] tablica;
    return 0;
}
