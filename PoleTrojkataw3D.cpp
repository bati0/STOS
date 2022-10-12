#include <iostream>
#include <math.h>

using namespace std;

int main() {
    cout.precision(7);
    double x[3],y[3],z[3],vectorAB[3],vectorAC[3],iloczyn[3],razem;
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i] >> z[i];
    }
    vectorAB[0]= (x[1]-x[0]);
    vectorAB[1]= y[1] - y[0];
    vectorAB[2] = z[1]-z[0];
    vectorAC[0]= x[2]-x[0];
    vectorAC[1]= y[2]-y[0];
    vectorAC[2]= z[2]-z[0];
    //iloczyn=((vectorAB[1]*vectorAC[2])-(vectorAB[2]*vectorAC[1])-((vectorAB[0]*vectorAC[2])-(vectorAB[2]*vectorAC[0]))+((vectorAB[0]*vectorAC[1])-(vectorAB[1]*vectorAC[0])));
    iloczyn[0] =(vectorAB[1]*vectorAC[2])-(vectorAB[2]*vectorAC[1]);
    iloczyn[1]= -((vectorAB[0]*vectorAC[2])-(vectorAB[2]*vectorAC[0]));
    iloczyn[2]=((vectorAB[0]*vectorAC[1])-(vectorAB[1]*vectorAC[0]));
    razem = (sqrt(pow(iloczyn[0],2)+ pow(iloczyn[1],2)+ pow(iloczyn[2],2)))/2;
    cout << razem;
}
