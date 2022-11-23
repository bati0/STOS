//#include "iostream"
//#include "math.h"
//
//using namespace std;
//
//int main(){
//    int a,b;
//    double wynik;
//    char znak;
//    cout << "podaj liczby" << endl;
//    cin >> a >> b;
//    if (a<1000 && a>-1000){
//        if (b<1000 && b>-1000){
//            cout << "podaj znak dzialania" << endl;
//            cin >> znak;
//            switch (znak) {
//                case '+':
//                    wynik = a+b;
//                    cout << "Wynik dzialania to:" << wynik;
//                    break;
//                case '-':
//                    wynik = a - b;
//                    cout << "Wynik dzialania to: " << wynik;
//                    break;
//                case '*':
//                    wynik = a*b;
//                    cout << "Wynik dzialania to: " << wynik;
//                    break;
//                case '/':
//                    if (b!=0) {
//                        wynik = a / b;
//                        cout << "Wynik dzialania to: " << wynik;
//                        break;
//                    } else {
//                        cout << "Nie mozna dzielic przez zero";
//                        break;
//                    }
//                case '%':
//                    if (b!=0){
//                        cout << "Wynik dzialania to: " << a%b;
//                        break;
//                    } else {
//                        cout << "Nie mozna dzielic przez zero";
//                        break;
//                    }
//                default:
//                    cout << znak << "bledna operacja"
//
//            }
//        } else {
//            cout << "Niewlasciwe liczby";
//        }
//    } else {
//        cout << "Niewlasciwe liczby";
//    }
//}
#include "iostream"
#include "math.h"

using namespace std;

int main(){
    long int a,b;
    double wynik;
    char znak;
    do {
        cin >> znak >> a >> b;
        switch (znak) {
            case '+':
                wynik = a+b;
                cout << wynik << endl;
                break;
            case '-':
                wynik = a - b;
                cout <<  wynik << endl;
                break;
            case '*':
                wynik = a*b;
                cout <<  wynik << endl;
                break;
            case '/':
                if (b!=0) {
                    wynik = a / b;
                    cout <<  wynik << endl;
                    break;}
            case '%':
                if (b!=0){
                    cout <<  a%b << endl;
                    break;
                }
        }
    } while (cin);



}