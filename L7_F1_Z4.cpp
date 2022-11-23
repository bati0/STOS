#include<iostream>

using namespace std;

int zagadka(double a){
	char *wsk = (char*)&a;
	int i;
	for(i = sizeof(double); i > 0 ; i--){
		for(unsigned char maska = 1 << 7; maska; maska >>= 1){
			cout << ((wsk[i] & maska) ? 1 : 0);
		}
		cout << " ";
	}
	cout << endl;
	return 0;
}

int main(){	
	zagadka(3.25);
	return 0;
}
