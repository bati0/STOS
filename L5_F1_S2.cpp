#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;

   const int MLP = 50;              // Maksymalna liczba pasa?erów
   const int LDT = 7; // Liczba dni w tygodniu
   const int  LG = 12;              // Liczba godzin pomiaru dziennie
   
        //Napisz prototypy funkcji

void generuj(int Bus[][LG]);
void wypisz(int Bus[][LG]);
void sum_pas(int Bus[][LG]);
void pas_dzien(int Bus[][LG]);
void maks_pas_dzien(int Bus[][LG]);
void min_pas_dzien(int Bus[][LG]);
void avg_pas_godz(int Bus[][LG]);
void przekrocz_prog(int Bus[][LG]);
void Menu();


int main()
{
    Menu();
}
/*

  // ----------------------------------------------------------- podpunkt e) 
  // --- sprawdzenie przekroczenia progu


  system("PAUSE");
  return 0;
}
*/
void generuj(int Bus[][LG])
    {
        srand(time(NULL));
        for ( int dzien = 0; dzien < LDT; dzien++ )
            for ( int godzina = 0; godzina < LG; godzina++ )
                Bus[dzien][godzina] = rand()% MLP + 1;
    }
void wypisz(int Bus[][LG])
    {
        cout << "   |" ;
        for ( int godzina = 8; godzina < LG + 8; godzina++ )
            cout << setw(4) << godzina ;
        cout << endl;

        cout << "----" ;
        for ( int godzina = 8; godzina < LG + 8; godzina++ )
            cout << "----" ;
        cout << endl;

        for ( int dzien = 0; dzien < LDT; dzien++ ) {
            cout << "D" << dzien + 1 << " |";
            for ( int godzina = 0; godzina < LG; godzina++ )
                cout << setw(4) << Bus[dzien][godzina];
            cout << endl;
        }

        cout << "----" ;
        for ( int godzina = 8; godzina < LG + 8; godzina++ )
            cout << "----" ;
        cout << endl;
    }
void sum_pas(int Bus[][LG])
{
    int suma = 0;
    for ( int dzien = 0; dzien < LDT; dzien++ )
        for ( int godzina = 0; godzina < LG; godzina++ )
            suma += Bus[dzien][godzina];
    cout << " W tygodniu jechalo " << suma << " pasazerow" << endl;
}
void pas_dzien(int Bus[][LG])
{
    for ( int dzien = 0; dzien < LDT; dzien++ ) {
        int suma = 0;      // przes?ania zmienn? o tej samej nazwie
        for ( int godzina = 0; godzina < LG; godzina++ )
            suma += Bus[dzien][godzina];
        cout << " dnia " << dzien + 1 << " jechalo " << suma << " pasazerow" << endl;
    }
}
void maks_pas_dzien(int Bus[][LG])
{
    for ( int dzien = 0; dzien < LDT; dzien++ ) {
        int maximum = Bus[dzien][0];
        for ( int godzina = 1; godzina < LG; godzina++ )
            if ( Bus[dzien][godzina] > maximum )
                maximum = Bus[dzien][godzina];
        cout << dzien + 1 << " dnia najwieksza liczba pasazerow to " << maximum << endl;
    }
}
void min_pas_dzien(int Bus[][LG])
{
    for ( int dzien = 0; dzien < LDT; dzien++ ) {
        int min_godzina = 0;
        for ( int godzina = 1; godzina < LG; godzina++ )
            if ( Bus[dzien][godzina] < Bus[dzien][min_godzina] )
                min_godzina = godzina;
        cout << dzien + 1 << " dnia najmniej pasazerow jechalo o godzinie "
             << min_godzina + 8 << ":00" << endl;
    }
}
void avg_pas_godz(int Bus[][LG])
{
    double Srednia[LG];
    for ( int godzina = 0; godzina < LG; godzina++ ) {
        Srednia[godzina] = 0;
        for ( int dzien = 0; dzien < LDT; dzien++ )
            Srednia[godzina] += Bus[dzien][godzina];
        Srednia[godzina] = Srednia[godzina] / (1.0 * LDT);
        cout << "O godzinie " << godzina + 8 << ":00 kazdego dnia tygodnia "
             << "jechalo srednio " << Srednia[godzina] << " pasazerow" << endl;
    }
}
void przekrocz_prog(int Bus[][LG])
{
    int prog;
    cout << "Podaj wartosc progowa: ";
    cin >> prog;

    bool znaleziono = false;
    int dzien = 0;
    while (!znaleziono && (dzien < LDT)) {
        // --- przeszukiwanie k-tego wiersza
        int godzina = 0;
        while (!znaleziono && (godzina < LG))
            znaleziono = (Bus[dzien][godzina++] > prog);
        dzien++;
    }

    if (znaleziono)
        cout << "W dniu " << dzien << ". liczba pasazerow przekroczyla " << prog << endl;
    else
        cout << "Kazdego dnia jechalo nie wiecej niz " << prog << " pasazerow" << endl;

}

void Menu()
   {
       int Bus[LDT][LG];
       generuj(Bus);
       int opcja;
       do {
           cout << "1. Wyswietl tablice" << endl;
           cout << "2. Liczba pasazerow w ciagu tygodnia" << endl;
           cout << "3. Liczba pasazerow dla kazdego dnia tygodnia" << endl;
           cout << "4. Maksymalna liczba pasazerow kazdego dnia" << endl;
           cout << "5. Minimalna liczba pasazerow kazdego dnia" << endl;
           cout << "6. Srednia liczba pasazerow dla wszystkich godzin" << endl;
           cout << "7. Sprawdzenie przekroczenia progu ilosci pasazerow" <<endl;
           cout << "Nr funkcji:";
           cin >> opcja;
           switch (opcja)
           {
               case 1:
                   wypisz(Bus);
                   break;
               case 2:
                   sum_pas(Bus);
                   break;
               case 3:
                   pas_dzien(Bus);
                   break;
               case 4:
                   maks_pas_dzien(Bus);
                   break;
               case 5:
                   min_pas_dzien(Bus);
                   break;
               case 6:
                   avg_pas_godz(Bus);
                   break;
               case 7:
                   przekrocz_prog(Bus);
                   break;

               case 0:
                   cout << "Koniec programu" << endl;

               default:
                   break;
           }
           system("PAUSE");
       } while (opcja >0);
   }
