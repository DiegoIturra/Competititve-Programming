// Uva 247 	Calling Circles (ACEPTADO)
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#define UNVISITED 0
using namespace std;

set<string> nameSet; //set para verificar que no se incremente el id de cada persona
map<int,string> nameMap; //mapear los nombres de las personas a enteros

map<string,int> idMap; //mapear a los nombres un string

vector<vector<int>> graph; //lista de adyacencia
vector<bool> onStack; //marca los nodos que actualmente estan en el stack
vector<int> low,ids; //low es para el low link , e ids es el vector de visitados 
stack<int> S; //stack de nodos
int numVisited = 0;

int dfsNumberCounter = 0;


bool exist(const string& name){
	if(nameSet.count(name))
		return true;
	return false;
}

void tarjanSCC(int u){
	low[u] = ids[u] = dfsNumberCounter++;
	S.push(u); //agragamos el nodo al stack
	onStack[u] = true; //marcamos el nodo como puesto en el stack

	for(int i=0 ; i<graph[u].size() ; i++){
		int v = graph[u][i]; //nodo vecino
		if(ids[v] == UNVISITED){ //si el id del nodo vecino no ha sido visitado
			tarjanSCC(v); //recursivamente se llama a tarjanSCC
		}
		if(onStack[v]){
			low[u] = min(low[u],low[v]);
		}
	}
	//es la raiz
	if(low[u] == ids[u]){
		while(true){
			int v = S.top();
			S.pop();
			onStack[v] = false;

			if(u == v){
				cout << nameMap[v] << endl;
				break;
			}else{
				cout << nameMap[v] << ", ";
			}
		}
	}
}


int main(){
	int numPeople,numCalling;
	int numCase = 0;
	bool endLine = false;
	string name1,name2;

	//leer hasta que ambos sean ceros
	while(cin >> numPeople >> numCalling){

		if(!numPeople && !numCalling)
			break;

		graph.assign(numPeople,vector<int>()); //asignar memoria para el grafo
		onStack.assign(numPeople,false); //al comienzo ningun nodo esta en el stack
		ids.assign(numPeople,UNVISITED); //marcar todos los nodos como no visitados
		low.assign(numPeople,0); //marcar todos los low-links como 0

		int index = 0;

		//leer entrada y mapear nombres
		while(numCalling--){
			cin >> name1 >> name2;

			if(!exist(name1)){
				idMap[name1] = index;//al nombre le asigno un numero
				nameMap[index] = name1; //al numero le asigno un nombre
				nameSet.insert(name1);//inserto el nombre al set
				index++; //aumenta el indice
			}
			if(!exist(name2)){
				idMap[name2] = index;
				nameMap[index] = name2;
				nameSet.insert(name2);
				index++;
			}

			//crear grafo
			int node1 = idMap[name1];
			int node2 = idMap[name2];
			graph[node1].push_back(node2);
		}


		//ejecutar algoritmo de Tarjan
		if(!endLine){
			endLine = true;
		}else{
			cout << endl;
		}
		cout << "Calling circles for data set "<< ++numCase << ":" << endl;
		for(int i=0 ; i<graph.size() ; i++){
			if(ids[i] == UNVISITED){
				tarjanSCC(i);
			}
		}
		nameSet.clear();
	}
	return 0;
}