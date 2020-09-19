/*
10928 - My Dear Neighbours (ACEPTADO)
Codigo Propio
Nombre: Diego Iturra Huenteo
Uva Username: diturra2016
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int numCases,numPlaces;

	cin >> numCases;

	while(numCases--){
		cin >> numPlaces;
		getchar(); //evitar leer espacios vacios

		vector<int> graph(numPlaces);

		//leer entrada y contar numero de vecinos
		for(int i=0 ; i<numPlaces ; i++){
			string neighbours;
			getline(cin,neighbours);

			int numNeighbours = 1; //si tiene n vecinos , existen n-1 espacios entre los vecinos
			for(int k=0 ; k<neighbours.size() ; k++){
				if(neighbours[k] == ' '){
					numNeighbours++;
				}
			}
			graph[i] = numNeighbours; //no interesan cuales sean los vecinos, sino cuantos son
		}

		//hallar el minimo numero de vecinos
		int minNeighbours = *min_element(graph.begin() , graph.end());
		
		//obtener todos los que tengan el minimo numero de vecinos
		vector<int> nodes;
		for(int i=0 ; i<graph.size() ; i++){
			if(graph[i] == minNeighbours){
				nodes.push_back(i);
			}
		}

		//imprimir
		if(nodes.size() == 1)
			cout << nodes[0] + 1 << '\n'; //+1 porque estan enumerados desde 0,..,n-1
		else
			for(int i=0 ; i<nodes.size() ; i++){
				if(i < nodes.size()-1)
					cout << nodes[i] + 1 << " ";
				else
					cout << nodes[i] + 1 << '\n';
			}
	}
	return 0;
}