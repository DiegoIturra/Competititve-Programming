//Uva 11565 Simple Equations (ACEPTADO)
/*
Nombre: Diego Iturra
usuario UVA: diturra2016 - 1028885
Codigo PROPIO
*/
#include <iostream>
using namespace std;

int main(){
	int testCases;
	cin >> testCases;

	int A,B,C;
	bool solucion_encontrada;
	for(int i=0 ; i<testCases ; i++){
		cin >> A >> B >> C;
		solucion_encontrada = false;

		//evaluar posibles soluciones
		/*el mayor valor que puede tener una variable es |100| para que no supere los 10.000*/
		int x,y,z;
		for(int i = -100 ; i <= 100 && !solucion_encontrada ; i++){ //para cada valor de i probar todas las
			for(int j = -100 ; j <= 100 && !solucion_encontrada ; j++){ //combinaciones de j y k
				for(int k = -100 ; k <= 100 && !solucion_encontrada ; k++){
					if(i+j+k == A && i*j*k == B && (i*i) + (j*j) + (k*k) == C && i != j && i != k && j != k){
						x = i;
						y = j;
						z = k;
						solucion_encontrada = true;
					}
				}
			}
		}
		/*si se cumple una solucion entonces esta es la minima posible y detenemos las iteraciones*/
		if (solucion_encontrada){
			cout << x << " " << y << " " << z << endl;
		}else{
			cout << "No solution." << endl;
 		}
	}
	return 0;
}