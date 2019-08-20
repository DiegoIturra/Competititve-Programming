//Timus 1068 - Sum (ACEPTADO)
#include <iostream>
using namespace std;

int main(){
	int num , sum = 0;
	cin >> num;
	if(num > 0)
		for(int i=1 ; i <= num ; i++) sum += i;
	else
		for(int i=1 ; i >= num ; i--) sum += i;
	cout << sum << endl;
	return 0;
}

