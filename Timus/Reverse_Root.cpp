//Timus	1001 Reverse Root(ACEPTADO)
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	vector<double> vec;
	double number;
	//leer todos los numeros y guardarlos en un vector
	while(cin >> number){
		vec.push_back(number);
	}
	//leer el vector de forma reversa y calcular la raiz cuadrada e imprimirla
	for(int i = vec.size()-1 ; i >= 0 ; i--){
		double squareRoot = sqrt(vec[i]);
		printf("%.4f\n",squareRoot);
	}
	return 0;
}
