//Uva 855 Lunch in Grid City (ACEPTADO)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Obtener la mediana baja que pertenezca al conjunto de datos*/
int median(vector<int>& listaDatos){
	int size = listaDatos.size();
	int half;
	if(size % 2 != 0){
		half = size / 2;
	}else{
		half = (size / 2) - 1;
	}
	return listaDatos[half];
}

int main(){
	int casosPrueba;
	cin >> casosPrueba;

	int numCalles , numAvenidas,numAmigos;
	vector<int> calles , avenidas;
	int calle,avenida;

	while(casosPrueba--){
		cin >> numCalles >> numAvenidas >> numAmigos;
		for(int i=0 ; i<numAmigos ; i++){
			cin >> calle >> avenida;
			calles.push_back(calle);
			avenidas.push_back(avenida);
		}

		sort(calles.begin() , calles.end());
		sort(avenidas.begin() , avenidas.end());
		int calleMediana = median(calles);
		int avenidaMediana = median(avenidas);

		cout << "(Street: " << calleMediana << ", Avenue: " << avenidaMediana << ")" << endl;
		calles.clear();
		avenidas.clear();
	}
	return 0;
}