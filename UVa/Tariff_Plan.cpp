//Uva 12157 : Tariff Plan (ACEPTADO)
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int testCases,phoneCalls,callDuration;
	cin >> testCases;
	//para cada caso de prueba
	int Case = 0;
	while(testCases--){
		Case++;
		cin >> phoneCalls;
		//para ambas compañias
		int milePrice = 0;
		int juicePrice = 0;

		//para cada llamada
		while(phoneCalls--){
			cin >> callDuration;
			milePrice += ((callDuration / 30)  + 1) * 10;
			juicePrice += ((callDuration / 60) + 1) * 15;
		}		
		if(milePrice < juicePrice){
			cout << "Case " << Case << ": " << "Mile " << milePrice << endl;
		}else if(milePrice > juicePrice){
			cout << "Case " << Case << ": " << "Juice " << juicePrice << endl;
		}else{
			cout << "Case " << Case << ": " << "Mile " << "Juice " << milePrice << endl;
		}
	}
	return 0;
}