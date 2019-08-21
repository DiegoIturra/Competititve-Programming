//Timus 1025. Democracy in Danger (ACEPTADO)
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int groups;
	cin >> groups;
	int numVoters;
	vector<int> groupPeople;
	//leer los grupos de votantes e insertarlos en un vector
	while(groups--){
		cin >> numVoters;
		groupPeople.push_back(numVoters);
	}
	//ordenar el vector
	sort(groupPeople.begin() , groupPeople.end());
	//obtener la mitad de los grupos con menos personas
	int size = groupPeople.size();
	float half = (float)size/2;
	size = round(half);
	//recorrer hasta la mitad redondeada obteniendo el 50% de los grupos con menor gente
	int sum = 0;
	float mid;
	for(int i=0 ; i<size ; i++){
		mid = (float)groupPeople[i] / 2;
		groupPeople[i] = round(mid);
		sum += groupPeople[i]; //sumar hasta la mitad del vector el 50% de votantes a favor
	}
	cout << sum << endl;
	return 0;
}