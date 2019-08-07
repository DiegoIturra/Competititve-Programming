//UVa 11044 - Searching for Nessy (ACEPTADO)
#include <iostream>
using namespace std;

int main(){
	int testCases;
	cin >> testCases;
	int row,column;
	while(testCases--){
		cin >> row >> column;
		cout << (row/3)*(column/3) << endl;
	}
	return 0;
}

/*Cada sonda ocupa una celda en la matriz , lo que significa que por cada sonda ocupa
3x3 espacios contiguos , incluyendo el mismo , por lo que hay que dividir el numero de filas
por 3 y el numero de columnas por 3 y multiplicarlos ambos*/