#include "iostream"
using namespace std;

int main()
{
    int l1,l2,l3,n1,n2,n3;
    cin >> l1;
    cin >> l2;
    cin >> l3;
    if(l1>l2){
        if (l1>l3){
            n1 = l1;
            if (l2>l3){
                n2 = l2;
                n3 = l3;
            } else {
                n2 = l3;
                n3 = l2;
            }
        } else {
            n1 = l3;
            n2 = l1;
            n3 = l2;
        }
    } else {
        if (l2>l3){
            n1=l2;
            if (l1>l3){
                n2=l1;
                n3=l3;
            } else {
                n2=l3;
                n3=l1;
            }
        } else {
            n1=l3;
            n2=l2;
            n3=l1;
        }
    }
    cout << n1 << " " << n2 << " " << n3;
    return 0;
}