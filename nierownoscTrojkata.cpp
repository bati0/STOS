#include <iostream>
using namespace std;

int main() {
    double a,b,c;
    cin >> a >> b >> c;
    if ((a*b*c)==0){
        cout << "0";
    } else {
        if (a+b>c){
            if (a+c>b){
                if (b+c>a){
                    cout << "1";
                    return 0;
                }
            }
        }
        cout << "0";
    }
    return 0;
}
