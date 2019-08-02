//UVa 514 - Rails (ACEPTADO)
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
	int N;
	int carril;
	while(1){
		vector<int> permutacion;
		cin >> N; //leemos el primer numero que indica el largo del tren
		if(N == 0) break; //si es un cero termina el fichero
		while(1){
			cin >> carril;
			permutacion.push_back(carril);
			//si lee un cero entre la entrada , entonces imprime un salto de linea para pasar a la siguiente
			if(carril == 0){
				cout << "\n";
				break;
			}
			//este vector de numeros es la permutacion que se lee por entrada
			for(int i=1 ; i<N ; i++){
				cin >> carril;
				permutacion.push_back(carril);
			}

			//ahora necesitamos una estacion que sera un stack
			int carrilActual = 1;
			int indicePermutacion = 0;
			stack<int> estacion;
						
			//para ingresar en orden los carriles al stack
			while(carrilActual <= N){
				estacion.push(carrilActual);
				while(!estacion.empty() && estacion.top() == permutacion[indicePermutacion]){
					estacion.pop();
					indicePermutacion++;
				}
				carrilActual++;
			}
			permutacion.clear();
			if(estacion.empty()){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}	
		}
	}
	return 0;
}
