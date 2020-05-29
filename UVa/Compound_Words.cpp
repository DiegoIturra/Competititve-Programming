//Uva 10391- Compound Words (ACEPTADO)
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string word;
	vector<string> palabras;

	//leer entrada y guardar strings
	while(cin >> word){
		palabras.push_back(word);
	}

	//ordenar para ejecutar una busqueda binaria
	sort(palabras.begin() , palabras.end());

	//metodo substr(pos_inicial , longitud);

	int size = palabras.size();
	for(int i=0 ; i<size ; i++){
		//si es de tam=1 entonces no es concatenacion de nada
		if(palabras[i].size() == 1){
			continue;
		}
		for(int j=1 ; j<palabras[i].size() ; j++){
			string substring1 = palabras[i].substr(0,j);
			string substring2 = palabras[i].substr(j,palabras[i].size()-1);

			if(binary_search(palabras.begin(),palabras.end(),substring1) && binary_search(palabras.begin(),palabras.end(),substring2)){
				cout << palabras[i] << endl;
				break;
			}
		}
	}

	return 0;
}