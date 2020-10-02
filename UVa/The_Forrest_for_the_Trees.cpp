/*
Uva 599 The Forrest for the Trees (ACEPTADO)
Codigo Propio
Nombre: Diego Iturra Huenteo
uva username: diturra2016
*/


#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


map<char,vector<char>> graph;
vector<pair<char,char>> Edges;
vector<char> Nodes;
map<char,bool> visited;

int contador = 0; //contador de vecinos de un nodo

void dfs(char u){
	visited[u] = true;
	for(auto vec_iter = graph[u].begin() ; vec_iter != graph[u].end() ; ++vec_iter){
		if(!visited[*vec_iter]){
			contador++; //si el nodo tiene un vecino es porque es un arbol
			dfs(*vec_iter);
		}
	}
}


int main(){
	int testCases;
	string edges,u,v;
	cin >> testCases; //leer los casos

	while(testCases--){
		while(cin >> edges){ //leer las aristas
			if(edges[0] == '*'){ //cuando encuentra un * , finaliza la lectura de aristas
				break;
			}
			Edges.push_back(make_pair(edges[1],edges[3])); //guardar el par (nodo,nodo)
		}

		string nodes;
		cin >> nodes; //leer todos los nodos del grafo

		//parsear y guardar solo los nodos omitiendo comas y espacios
		for(int i=0 ; i<nodes.size() ; i++){
			if(nodes[i] != ' ' && nodes[i] != ','){
				Nodes.push_back(nodes[i]);
			}
		}

		//generar grafo
		for(int i=0 ; i<Edges.size() ; i++){
			graph[ Edges[i].first ].push_back( Edges[i].second );
			graph[ Edges[i].second ].push_back( Edges[i].first );
		}

		//marcar visitados como falso
		for(int i=0 ; i<Nodes.size() ; i++){
			visited[Nodes[i]] = false;
		}
		
		int conected_component = 0;
		int num_trees = 0;
		int num_acorns = 0;
		for(int i=0 ; i<Nodes.size() ; i++){
			if(!visited[Nodes[i]]){
				dfs(Nodes[i]); 
				if(!contador) //si luego del dfs el contador queda en 0 es porque no hay vecinos
					num_acorns++; //por lo tanto es un acorn
				else //si hay vecinos 
					num_trees++; //es un arbol
			}
			contador = 0;
		}

		cout << "There are " << num_trees << " tree(s) and " << num_acorns << " acorn(s)." << endl;

		Edges.clear();
		graph.clear();
		Nodes.clear();
		visited.clear();
	}
	return 0 ;
}