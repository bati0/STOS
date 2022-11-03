#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>



using namespace std;

//**********prototyp funkcji**********
 void menu(int);           //uzupelnij kod
 bool Wspolczynniki(float [], int&); //uzupelnij kod
 double Funkcja(float [],int, double );        //uzupelnij kod
 bool Tablicowanie(float, float, int, int, float [], double []);   //uzupelnij kod
 int monoton(double [],int );        //uzupelnij kod
 int MaxMin(double[],int, double&, double &, double &);        //uzupelnij kod
 int Bisekcja(float ,float ,double ,double&, float [],int );       //uzupelnij kod

//************************************

    const int MAX_N = 1000;
    const int MAX_ST = 5;
    
    
int main()
{
    bool dane_wazne = 0;
    bool tablica_wazna = 0;
    float Wsp[MAX_ST + 1]; //tablica wsp. wielomianu
    float pocz, koniec;
    double wynik; //wartosc wielomianu dla danego x
    int liczba_N, st_wielomianu; //ilosc punktow do tablicowania, st. wielomainu
    int opcja; 
    double Tablica[MAX_N]; //wektor wartosci po tablicowaniu

    
   
    do{
       menu(2);
       cin >> opcja;
       switch(opcja)
       {
       case 1: //wprowadzanie wsp wielomianu
         if(dane_wazne)
          {
           cout << "Czy wprowadzic ponownie wsp. wielomianu [T/N]: ";
           if((getchar() == 't') || (getchar() == 'T'))
           dane_wazne = Wspolczynniki(Wsp, st_wielomianu);  //Wspolczynniki()
           else
            cout << "Wsp. wielomianu pozostaly bez zmian" << endl;
           }
          else
           dane_wazne = Wspolczynniki(Wsp, st_wielomianu); //Wspolczynniki()

          break;    
          
        case 2: //wyliczanie wartosci funkcji dla danego x
           if(!dane_wazne)
           {  
             cout << "Wprowadz wspolczynniki wielomianu (OPCJA 1)" << endl;
             break;
             }
           double x;
           cout << "Podaj wartosc x: ";
           cin >> x;
           cout << "F(" << x << ") = " << Funkcja(Wsp, st_wielomianu, x) << endl; //Funkcja()
            break;
        case 3: //tablicowanie funkcji w podanym przedziale
            if(!dane_wazne)
            {  
             cout << "Wprowadz wspolczynniki wielomianu (OPCJA 1)" << endl;
             break;

             }
           cout << "Tablicowanie funkcji"<< endl;
           cout << "Podaj przedzial tablicowania [xp xk]: ";
           cin >> pocz >> koniec;
           cout << "Podaj liczbe punktow: ";
           cin >> liczba_N;
           tablica_wazna = Tablicowanie( pocz, koniec, liczba_N, st_wielomianu, Wsp, Tablica); //Tablicowanie()
   
           break;
   
           case 4: //badanie monotonicznosci funcji
             if(!(dane_wazne && tablica_wazna))
             {  
            cout << "Wprowadz wspolczynniki wielomianu (OPCJA 1)" << " i wykonaj tablicowanie (OPCJA3)" << endl;
             break;
             }
            cout << "Badanie monotonicznosci funkcji"<<endl;
   
             if(monoton(Tablica, liczba_N) > 0)  //monoton()
             cout << "W przedziale <" << pocz << "; " << koniec <<
             "> funkcja jest monotoniczna i niemalejaca"<<endl;
   
              else if(monoton(Tablica, liczba_N) < 0) //monoton()
              cout << "W przedziale <" << pocz << "; " << koniec <<
   "> funkcja jest monotoniczna i nierosnaca"<<endl;
   
 else 
              cout << "W przedziale <" << pocz << "; " << koniec 
       << "> funkcja nie jest monotoniczna"<<endl;
   break;
   
         case 5: //wyznaczanie wartosci maksymalnej, minimalnej i 
    //sredniej z tablicy wartosci funkcji
             if(!(dane_wazne && tablica_wazna))
              {  
             cout << "Wprowadz wspolczynniki wielomianu (OPCJA 1)" << 
             " i wykonaj tablicowanie (OPCJA3)" << endl;
             break;
             }
             cout<<"Liczenie warosci maksymalnej [max], minimalnej [min] i sredniej [mean]"<<endl;
             double max, min, mean;
   
             MaxMin(Tablica, liczba_N, min, max, mean); 
     //MaxMin()
   
             cout <<"max = "<<max<<"\tmin = "<<min<<"\tmean = "<<mean<<endl;
             break;
   
             case 6: //wyznaczanie miejsca zerowego funcki metoda 
   //bisekcji
  if(!dane_wazne)
      {  
      cout << "Wprowadz wspolczynniki wielomianu (OPCJA 1)" << endl;
       break;
      }
  double wynik;
   
  double blad;
    cout << "Wyznaczanie miejsca zerowego funkcji"<< endl;
    cout << "Podaj przedzial gdzie jest rozwiazanie [xp xk]: ";
    cin >> pocz >> koniec;
    cout << "Podaj dokladnosc: ";
    cin >> blad;
   
     if(
      Bisekcja(pocz, koniec, blad, wynik, Wsp, st_wielomianu) < 0
      ) //Bisekcja()
     {
       cout << "W podanym przedziale nie ma miejsca zerowego"<<endl;
       cout << "lub wystepuje wielokrotnie" << endl;
      }
   else
     cout<<"Rozwiazanie z dokladnoscia "<<blad <<" wynosi: "<< wynik  
          << endl;
   
   break;
         
           case 0:
 cout << "Koniec dzialania programu" <<endl;
   
 break;
          default:
             cout << "Podales bledny parametr" << endl;
    break;
           }
      system("PAUSE");
           
   } while(opcja);
   
    return 0;
}

//**********definicje funkcji*************
 void menu(int sw)   //uzupelnij kod
{
     switch(sw)
     {
       case 1:
         cout << setw(15) << "Laboratorium Podstaw Programowania" << endl;
         cout << setw(15) << "Witaj w programie Analiza funkcji" << endl;
         cout << setw(15) << "Przed przystapieniem do pracy zapoznaj sie z instrukcja do zadania" << endl;
         cout << "\n\t";
         system("PAUSE");
           break;
       case 2:
            system("cls");
            cout << "1. Wprowadz wspolczynniki wielomianu" << endl;
            cout << "2. Wylicz wartosc funkcji dla danego x" << endl;
            cout << "3. Tablicowanie funkcji" << endl;
            cout << "4. Sprawdz monotonicznosc funkcji" << endl;
            cout << "5. Wyznaczenie wartosci maksymalnej i minimalnej i sredniej" << endl;
            cout << "6. Wyznaczenie miejsca zerowego w podanym przerdziale (bisekcja)" << endl;
            cout << "0. Koniec programu" << endl;
            cout << endl << endl << "Wybierz opcje: ";
           break;
     }
     
}

bool Wspolczynniki(float Tab_wsp[], int& st)   //uzupelnij kod
{
     cout << endl << "Podaj stopien wielomianu [" << MAX_ST << "]: ";
     cin >> st;
     if( st < 0 || st > MAX_ST)
     {   
         cout << "Podany stopien wielomianu jest poza zakresem" << endl;
         return 0;
     }
     for(int i = st; i >= 0; i--)
     {
             cout << "Podaj wsp " << char('A' + st - i) << ": ";
             cin >> Tab_wsp[i];
     }
     cout << endl;
     cout << "F(x) =";
     for (int i = st; i > 0; i--)
         cout << "(" << Tab_wsp[i] << " * x^" << i <<") + ";
     cout << Tab_wsp[0] << endl;
     
     return 1;
}  

 double Funkcja(float tab_wsp[],int st, double x)  // przyklad funkcji rekurencyjnej
 //uzupelnij kod
{
    double y = tab_wsp[st] * pow(x,st);
    if(st >=0 )return y += Funkcja(tab_wsp, st-1, x);
    else return 0;
}


       
 bool Tablicowanie(float xp,float xk, int sampleN, int st, float Tab_wsp_fun[], double Tab_Fun[] )    //uzupelnij kod
{
    double x;
    double delta_x = (xk - xp)/(sampleN - 1);  //xp, xk - poczatkowe i koncowe 
    //wartosci przedzialu tablicowania
    for(int i = 0; i < sampleN; i++)           // sampleN - ilosc tablicowanych 
  //elementow
    {
            x = xp + delta_x * i;
            Tab_Fun[i] = Funkcja(Tab_wsp_fun, st, x);  //Tab_Fun - tablica 
             //wartosci
          //Tab_wsp_fun - 
        //tablica wsp. funkcji
            cout <<setw(15) << "x = "<<x<<setw(15) << "y = "<<Tab_Fun[i]<<endl;
    }
            
    return 1;
}
 int monoton(double Tab_Fun[],int sampleN )  ////uzupelnij kod
{
   int mono;
   if(Tab_Fun[0] <= Tab_Fun[1])
   {
      mono = 1;
      for(int i = 1; i < sampleN - 1; i++)
      {
         if(Tab_Fun[i] > Tab_Fun[i + 1])
            return 0;
      }
   }
   
   else 
   {
       mono = -1;
       for(int i = 1; i < sampleN - 1; i++)
      {
         if(Tab_Fun[i] < Tab_Fun[i + 1])
            return 0;
      }
   }
   
    return mono;
}
            
int MaxMin( double tab_Fun[] , int sampleN,double& Min,double& Max,double& mean) //uzupelnij kod
{
    double suma = tab_Fun[0];
    Min = tab_Fun[0];        //wartosc minimalna
    Max = tab_Fun[0];        //wartosc maksymalna
    
    
    for(int i = 1; i < sampleN; i++)
    {
            if(tab_Fun[i] < Min) Min = tab_Fun[i];
            if(tab_Fun[i] > Max) Max = tab_Fun[i];
            suma += tab_Fun[i];
            }
    mean = suma/sampleN;  //wartosc srednia
    return 0;
}
            
            
            
    
int Bisekcja(float xp,float xk, double acc ,double& out,float Tab_wsp[],int st ) //uzupelnij kod
{
      double c, yp, yk, yc;        //xp-x pocz, xk-x koncowe, acc - 
    //dokladnosc
    //Tab_wsp - tablica wsp wielomianu, st - 
    //stopien wielomianu
      yp = Funkcja(Tab_wsp, st, xp);
      yk = Funkcja(Tab_wsp, st, xk);
      if( yp*yk > 0 ) //sprawdzenie czy w przedziale znajduje sie 
        //rozwiazanie
          return -1;
      else
      {
          do{
   c = (xk + xp)/2;
         yp = Funkcja(Tab_wsp, st, xp);
         yc = Funkcja(Tab_wsp, st, c);
         yk = Funkcja(Tab_wsp, st, xk);
   if((yp * yc) <= 0)
       xk = c;
   else if (( yk * yc) <= 0)
       xp = c;
   else
       return -1;
       
            }while((xk - xp) > acc);
             out = (xk + xp)/2;    
            return 0;
      }
}

