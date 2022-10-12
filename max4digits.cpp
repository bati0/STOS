#include <iostream>
using namespace std;

int main() {

    int size=4, tab[4];
    cin >> tab[0] >> tab[1] >> tab[2] >> tab[3];
    for (int i = 0; i < size; ++i) {
        for (int j=0; j < size-1; j++){
            if (tab[j] < tab[j + 1])
                swap(tab[j], tab[j + 1]);
        }
    }

    cout << tab[0] <<endl;
    return 0;
}
