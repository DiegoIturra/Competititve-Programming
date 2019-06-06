//UVa 1062 Containers (ACEPTADO)
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(){
	
	vector<char> containerSet;
	string set;
	int caso = 0;
	while(cin >> set){
		if(set == "end") break;
		caso++;
		int tamSet = set.size();
		containerSet.push_back(set[0]);

		/*si  la letra es menor o igual se reemplaza en la posicion del menor*/
		for(int i=1 ; i<tamSet ; i++){
			bool ingresado = false;
			for(int j=0 ; j<containerSet.size() ; j++){
				if(set[i] <= containerSet[j]){
					containerSet[j] = set[i];
					ingresado = true;
					break;
				}
			}
		/*si no hay un menor entonces agregamos un "stack"*/
			if(ingresado == false){
				containerSet.push_back(set[i]);
			}
		}
		cout << "Case " << caso << ": " << containerSet.size() <<endl;
		containerSet.clear();
	}
	return 0;
}