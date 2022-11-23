#include<iostream>
#include "cmath"
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
	return 0;
}
int wypisz_odl(punkt *tablica,int liczba_N,double r)
{
    for (int i = 0; i < liczba_N; ++i) {
        if (odl(tablica+i)<r) wypisz(tablica + i);
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
	wypisz_tab(tab,3);
    wypisz_odl(tab,3,3);
	return 0;
}
