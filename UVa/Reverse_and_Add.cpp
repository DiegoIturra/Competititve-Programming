//Uva 10018 - Reverse and Add (ACEPTADO)
#include <iostream>
#include <string>
using namespace std;

long int descompose(long int number){
	long int remainder,numInv = 0;
	while(number > 0){
		remainder = number % 10;
		number = number / 10;
		numInv = numInv*10+remainder;
	}
	return numInv;
}

bool palindrome(long int& number){
	long int aux = number;
	long int resto,numInv = 0;
	while(aux > 0){
		resto = aux % 10;
		aux = aux / 10;
		numInv = (numInv*10)+resto;
	}
	if(numInv == number)
		return true;
	return false;
}

int main(){
	long int testCases,number;
	cin >> testCases;
	while(testCases--){
		cin >> number;
		long int iterations = 0;
		
		//hacer una descomposicion y sumarlo al numero actual
		number += descompose(number);
		iterations++;

		//mientras el numero no sea palindromo , volver a descomponerlo y sumarlo
		while(!palindrome(number)){
			iterations++;
			number += descompose(number);
		}
		cout << iterations << " " << number << endl;
	}
	return 0;
}

