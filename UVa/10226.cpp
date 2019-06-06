//UVA 10226 Hardwood Species (ACEPTADO)
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>
using namespace std;

int main(void){
	int testCases;
	string linea;

	//leer con dos saltos extras o se detenia en el primer espacio antes de los casos
	scanf("%d\n\n",&testCases);
	int casoIncial = testCases;
	while(testCases--){
		//usar map porque asi no insertamos duplicados y solo contamos la cantidad de arboles asociados a un nombre 
		map<string,int> trees;
		int cantElementos = 0;
		while(true){
			getline(cin,linea);
			if(linea == "") break;
			trees[linea] = trees[linea] + 1; //sumamos al valor asociado cada vez que pille el elemento
			cantElementos++;
		}

		map<string, int>::iterator it;
		if(testCases != casoIncial-1) cout << "\n";	//condicion callampa para que no imprimiera el ultimo espacio
		for(it = trees.begin() ; it != trees.end() ; it++){
			//por cada elemento en el map , imprimos su valor correspondiente en porcentaje
			float porcentaje = (100.0000 * float(it->second)) / float(cantElementos);
			cout << it->first << " ";
			printf("%.4f\n",porcentaje);
		}
	}
	return 0;
}