//UVA 11286 Conformity (ACEPTADO)
#include <iostream>
#include <map>
#include <set>
#include <iterator>
#include <string>
using namespace std;

int main(void){
	int testCases;
	while(cin >> testCases){
		if(testCases == 0) break;
		int num;
		set<int> cursos;
		map<string , int > mapCursos; //almacena el string clave y la cantidad de repeticiones de la clave
		//leemos cada linea para cada caso
		for(int i=0 ; i<testCases ;i++){
			for(int j=0 ; j<5 ; j++){
				cin >> num;
				cursos.insert(num); //se inserta al set
			}
			//pasamos la clave a un string
			set<int>::iterator setIt;
			string clave = "";
			for(setIt = cursos.begin() ; setIt != cursos.end() ; setIt++){
				clave += to_string(*setIt);
			}
			//mapeamos la clave
			mapCursos[clave]++;
			cursos.clear();
		}
		//buscar el mas popular
		map<string,int>::iterator it;
		int mayor = 0;
		for(it=mapCursos.begin() ; it!=mapCursos.end() ; it++){
			if(mayor < it->second){
				mayor = it->second;
			}
		}
		//buscar cuantas veces existe un mayor
		int masPopular = 0;
		for(it=mapCursos.begin() ; it!=mapCursos.end() ; it++){
			if(it->second == mayor){
				masPopular += it->second;
			}
		}
		//imprimir cantidad de alumnos que escogen el curso mas popular
		cout << masPopular << endl;
	}
	return 0;
}

