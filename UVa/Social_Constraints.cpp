//Uva-11742 Social Constraints (ACEPTADO)
/*
Nombre: Diego Iturra
usuario UVA: diturra2016 - 1028885
codigo PROPIO
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

//valores de las restricciones
struct valores{
	int a;
	int b;
	int c;
};

//retorna la posicion donde se encuentra el elemento
int posicion(vector<int>& vec,int elemento,int tam){
	int pos;
	for(int i=0 ; i<tam ; i++){
		if(vec[i] == elemento){
			pos = i;
			break;
		}
	}
	return pos;
}


int main(){

	int num_personas,num_restricciones;

	while(true){
		cin >> num_personas >> num_restricciones;
		if(num_personas == 0 && num_restricciones == 0) break;

		int a,b,c;

		vector<int> vec(num_personas);
		vector<valores> restricciones;

		//llenar vector [0,n-1]
		iota(vec.begin(),vec.end(),0);

		int size = vec.size();
		int permutaciones_validas = 0;
		int posA,posB;

		//almacenar todas las restricciones existentes
		valores val;
		for(int i=0 ; i<num_restricciones ; i++){
			cin >> a >> b >> c;
			val.a = a;
			val.b = b;
			val.c = c;
			restricciones.push_back(val);
		}

		do{
			bool cumple_restriccion = true;
			/*para cada restriccion existente , verificar
			que se cumplan todas y cada una de ellas*/ 
			for(int i=0 ; i<num_restricciones && cumple_restriccion ; i++){
				posA = posicion(vec,restricciones[i].a,size);
				posB = posicion(vec,restricciones[i].b,size);

				//si C es positivo , la distancia entre a y b 
				//tiene que ser de a lo mas c asientos
				if(restricciones[i].c > 0){
					if(abs(posA - posB) > restricciones[i].c){
						cumple_restriccion = false;
						//basta que no cumpla una restriccion ,
						//para pasar la siguiente permutacion
					}
				//si C es negativo, la distancia entre a y b
				//tiene que ser de a lo menos -c asientos
				}else if(restricciones[i].c < 0){
					if(abs(posA - posB) < -restricciones[i].c){
						cumple_restriccion = false;
					}
				}
			}
			if(cumple_restriccion){
				permutaciones_validas++; //cumple todas las restricciones dadas
			}
		} while (next_permutation(vec.begin(),vec.end()));
		cout << permutaciones_validas << endl;
	}
	return 0;
}






