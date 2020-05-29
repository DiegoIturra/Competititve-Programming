//Uva 11553 - Grid Game (ACEPTADO)
/*
Nombre: Diego Iturra
usuario UVA: diturra2016 - 1028885
codigo PROPIO
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
	int testCases,tam_grid;
	vector<vector<int>> grid;
	vector<int> v;

	//leer la entrada
	cin >> testCases;

	while(testCases--){
		cin >> tam_grid;

		grid.resize(tam_grid,vector<int>(tam_grid));
		for(int i=0 ; i<tam_grid ; i++){
			for(int j=0 ; j<tam_grid ; j++){
				cin >> grid[i][j];
			}
		}
		
		v.resize(tam_grid);
		iota(v.begin(),v.end(),0); //vector [0,1,..n-1]

		int resultado1 = 0;
		int resultado2 = INT_MAX;

		/*crear un vector de largo n y con valores de 0 a n-1
		y para cada permutacion posible del vector probar todas las posibles
		intersecciones para una fila en la matriz*/
		do{
			for(int i=0 ; i<v.size() ; i++){
				resultado1 += grid[i][v[i]]; //sumar las posibles ganancias o perdidas
			}

			if(resultado1 < resultado2){
				resultado2 = resultado1; //quedarnos con el mejor resultado
			}
			resultado1 = 0; //setear a cero para probar el siguiente resultado

		}while(next_permutation(v.begin(),v.end()));

		cout << resultado2 << endl;

		grid.clear();
	}
	return 0;
}