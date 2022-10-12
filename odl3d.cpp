#include <iostream>
#include "math.h"
using namespace std;
int main() {
    double x1,y1,z1,x2,y2,z2,odl;
    cout.precision(7);
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;
    odl = sqrt(pow((y1-y2),2)+pow((z1-z2),2)+pow((x1-x2),2));
    cout << odl;
    return 0;
}
