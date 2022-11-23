// Bartosz Mielewczyk 193313 5
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>



using namespace std;


const int miejsca_pierw = 8*6;
const int miejsca_druga = 10*8;


struct wagon{
    int klasa;
    int liczba_pas;
    char stac_doc[2];
};

void initialize(wagon L[], int &ile_wagon);
int liczba(int a);
int licz(const wagon L[],const int ile_wagon);

int main()
{
    wagon L[10];
    int ile_wagon;
    initialize(L,ile_wagon);
    licz(L,ile_wagon);
    return 0;
}

int liczba(int a){
    srand( time( NULL ) );
    if (a==1){
        return std::rand()%miejsca_pierw;
    } else {
        return std::rand()%miejsca_druga;
    }
}

int licz(const wagon L[],const int ile_wagon){
    int j = 0;
	for(int i=0;i<ile_wagon;i++){
        cout << i << " " << L[i].stac_doc << "--"<< endl;
        if(strcmp(L[i].stac_doc,"B") == 0) {
            j++;
        }
    }
    return j;
}
	
void initialize(wagon L[], int &ile_wagon){
    L[0].klasa = 1;
    L[0].liczba_pas = liczba(L[0].klasa);
    cout << L[0].liczba_pas << endl;
    strcpy(L[0].stac_doc,"B");

    L[1].klasa = 1;
    L[1].liczba_pas = liczba(L[1].klasa);
    strcpy(L[1].stac_doc,"B");

    L[2].klasa = 1;
    L[2].liczba_pas = liczba(L[2].klasa);
    strcpy(L[2].stac_doc,"B");

    L[3].klasa = 2;
    L[3].liczba_pas = liczba(L[3].klasa);
    strcpy(L[3].stac_doc,"B");

    L[4].klasa = 2;
    L[4].liczba_pas = liczba(L[4].klasa);
    cout << L[4].liczba_pas << endl;
    strcpy(L[4].stac_doc,"B");

    L[5].klasa = 2;
    L[5].liczba_pas = liczba(L[5].klasa);
    strcpy(L[5].stac_doc,"B");

    L[6].klasa = 2;
    L[6].liczba_pas = liczba(L[6].klasa);
    strcpy(L[6].stac_doc,"B");

    L[7].klasa = 2;
    L[7].liczba_pas = liczba(L[7].klasa);
    strcpy(L[7].stac_doc,"C");

    L[8].klasa = 2;
    L[8].liczba_pas = liczba(L[8].klasa);
    strcpy(L[8].stac_doc,"C");

    L[9].klasa = 2;
    L[9].liczba_pas = liczba(L[9].klasa);
    strcpy(L[9].stac_doc,"C");
}
