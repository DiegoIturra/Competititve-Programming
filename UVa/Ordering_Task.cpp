/*
Uva 10305 Ordering Tasks (ACEPTADO)
Nombre: Diego Iturra
uva username: diturra2016
Codigo Propio
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
stack<int> sorted;

void topoSort(int u){
	visited[u] = true;
	
	for(int i=0 ; i<(int)graph[u].size() ; i++){
		int neighbour = graph[u][i];
		if(!visited[neighbour]){
			topoSort(neighbour);
		}
	}
	sorted.push(u); //al hacer backtracking pushear nodo en el stack
}

int main(){
	int numTask,numOrder;
	while(cin >> numTask >> numOrder){
		if(!numTask && !numOrder) break;
		int u,v;
		graph.assign(numTask,vector<int>());
		visited.assign(numTask,false);

		/*Como el valor de aristas puede ser 0 , crear un grafo en el que el nodo
		i tenga de vecino al nodo i+1 (Nodo Siguiente)*/
		if(!numOrder){
			for(int i=0 ; i<numTask-1 ; i++){
				graph[i].push_back(i+1);
			}
		}else{ //si no guardar el grafo como viene en la entrada
			while(numOrder--){
				cin >> u >> v;
				graph[u-1].push_back(v-1);
			}
		}
		//recorrer todos los nodos y por cada nodo no visitado , hacer un orden topologico (DFS)
		for(int i=0 ; i<numTask ; i++){
			if(!visited[i]){
				topoSort(i);
			}
		}
		//imprimir nodos en el orden reverso , por eso el uso de un Stack
		while(!sorted.empty()){
			cout << sorted.top()+1 << " ";
			sorted.pop();
		}
		cout << endl;
	}
	return 0;
}