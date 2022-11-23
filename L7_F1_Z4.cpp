#include<iostream>

using namespace std;

int zagadka(int a){
	char *wsk = (char*)&a;
	int i;
	for(i = 0; i < sizeof(int); i++){
		for(unsigned char maska = 1 << 7; maska; maska >>= 1){
			cout << ((wsk[i] & maska) ? 1 : 0);
		}
		cout << " ";
	}
	cout << endl;
	return 0;
}

int main(){	
	zagadka(255);
	return 0;
}
