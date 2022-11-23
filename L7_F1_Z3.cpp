#include <iostream>
#include <cstring>

using namespace std;

struct osoba{
	char *imie;
	char *nazwisko;
	int rok_urodzenia;
};

/** Funkcja sortuje adresy struktur z tablicy adresów struktur typu osoba*/
int sortuj(osoba **tablica, int liczba){
	int i, j;
	osoba *temp;
	for(i = 0; i < liczba; i++)
		for(j = 0; j < liczba; j++)
			if( tablica[i]->rok_urodzenia > tablica[j]->rok_urodzenia){
				temp = tablica[i];
				tablica[i] = tablica[j];
				tablica[j] = temp;
			}
	return 0;
}
int sortuj_nazw(osoba **tablica, int liczba){
    int i, j;
    osoba *temp;
    for(i = 0; i < liczba; i++)
        for(j = 0; j < liczba; j++)
            if( strcmp(tablica[i]->nazwisko, tablica[j]->nazwisko)<0){
                temp = tablica[i];
                tablica[i] = tablica[j];
                tablica[j] = temp;
            }
    return 0;
}

/** Funkcja wypisuje elementy tablicy, która zawiera struktury osoba*/
int wypisz(osoba *tablica, int liczba){
	while(liczba--){
		cout << tablica->imie << " " << tablica->nazwisko;
cout << " " << tablica->rok_urodzenia << endl;
		tablica++;
	}
	return 0;
}

/** Funkcja wypisuje struktury, których adresy zawiera tablica*/
int wypisz_wsk(osoba **tablica, int liczba){
	while(liczba--){
		cout << (*tablica)->imie << " " << (*(*tablica)).nazwisko << " " << (*tablica)->rok_urodzenia << endl; // 2 sposoby na wywolanie danych z tablicy, iloœæ gwiazdek musi sie zgadzac, -> robi za jedna gwiazdke
		tablica++;
	}
	return 0;
}

int main(){
	struct osoba dane[4] = {{"Antoni", "Adamski", 1985},{"Bartosz", "Barbarski",1972},{"Celina","Cezarska",1992}};
	dane[3].imie = "Dominik";
	dane[3].nazwisko = "Danucki";
	wypisz(dane, 4);
	struct osoba **dane_wsk = new struct osoba*[4];
	for(int i = 0; i < 4; i++) dane_wsk[i] = dane + i; //Przepisywanie adresów tablicy adresów
	sortuj(dane_wsk,4);
	wypisz_wsk(dane_wsk,4);
    cout << endl;
    sortuj_nazw(dane_wsk,4);
    wypisz_wsk(dane_wsk,4);
	return 0;
}