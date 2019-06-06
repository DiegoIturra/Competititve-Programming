//UVA 11849 CD (ACEPTADO)
#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main(void){
	int jackCD , jillCD;
	while(cin >> jackCD >> jillCD){
		if(jackCD==0 && jillCD==0) break;
		map<int,int> mapCD; //mapa que guarda numero de CD y sus repeticiones
		int cd;
		//recorremos los cds de Jack
		for(int i=0 ; i<jackCD ; i++){
			cin >> cd;
			mapCD[cd]++;
		}
		//recorremos los cds de Jill
		for(int i=0 ; i<jillCD ; i++){
			cin >> cd;
			mapCD[cd]++;
		}
		//recorremos el mapa para contar los cds con 2 apariciones
		map<int,int>::iterator it;
		int comun = 0;
		for(it=mapCD.begin() ; it!=mapCD.end() ; it++){
			if(it->second == 2){
				comun++;
			}
		}
		cout << comun << endl;
	} 
	return 0;
}