#include <iostream>
#include "math.h"
using namespace std;

int main() {
    cout.precision(7);

    double a,b,c,p,pole;

    cin >> a >> b >> c;
    p= (a+b+c)/2;
    pole = sqrt(p *(p-a)*(p-b)*(p-c));
    cout << pole;
    return 0;
}
