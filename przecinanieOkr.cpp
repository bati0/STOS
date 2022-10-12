#include <iostream>
#include "math.h"
using namespace std;

int main() {
    double x1, x2, y1, y2, r1, r2, odl;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    odl = sqrt(pow((x1-x2),2)+ pow((y1-y2),2));
    if (abs(r1-r2)<odl && odl<r1+r2){
        cout << "T";
    } else {
        cout << "F";
    }
    return 0;
}
