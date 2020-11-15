/*Uva 11747 Heavy Cycle Edges (ACEPTADO)
nombre: Diego Iturra Huenteo
uva username: diturra2016
Codigo Propio*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

struct Node{
	int id;
	int weight;

	bool operator>(const Node& node) const{
		return this->weight > node.weight;
	}
};

int numNodes,numEdges;
vector<vector<Node>> graph; //lista de adyacencia
vector<bool> taken; //vector de visitados
priority_queue<Node , vector<Node> , greater<Node>> pq;
set<int> setWeights; //conjunto de aristas


void process(int node){
	taken[node] = true;
	//para todos los nodos adyacentes a node
	for(int j=0 ; j<(int)graph[node].size() ; j++){
		Node v = graph[node][j];
		if(!taken[v.id]){ //si no ha sido visitado
			pq.push(v); //insertar en la cola de prioridad
		}
	}
}

void Prim(int node){
	process(node); //procesar nodo 0 inicialmente
	//mientras la cola no este vacia
	while(!pq.empty()){
		Node front = pq.top(); //tomamos la arista con menos costo
		pq.pop();
		int u = front.id;
		int weight = front.weight;
		if(!taken[u]){ //si no ha sido visitada la arista 

			/*Cuando hallamos una arista perteneciente al MST la eliminamos del conjunto*/
			setWeights.erase(weight);
			process(u);
		}
	}
}


int main(){
	while(cin >> numNodes >> numEdges){
		if(!numNodes && !numEdges) break;

		graph.assign(numNodes , vector<Node>());

		int u,v,w;
		Node node;
		for(int i=0 ; i<numEdges ; i++){
			cin >> u >> v >> w;
			node.id = v;
			node.weight = w;
			graph[u].push_back(node);
			node.id = u;
			graph[v].push_back(node);

			//crear un conjunto con todas las aristas
			setWeights.insert(w);
		}

		taken.assign(numNodes,false);

		//buscar un MST desde todas las componentes conexas
		for(int i=0 ; i<numNodes ; i++){
			if(!taken[i]){
				Prim(i);
			}	
		}
		
		vector<int> edges;

		/*Despues de hallar un MST en todas las componentes solo quedan las aristas que 
		forman parte de un ciclo , las cuales ya estan ordenadas de forma creciente al estar en 
		un set de enteros*/
		if(!setWeights.empty()){
			set<int>::iterator it;
			for(it = setWeights.begin() ; it != setWeights.end() ; it++){
				edges.push_back(*it);
			}

			for(int i=0 ; i<(int)edges.size() ; i++){
				if(i < edges.size()-1){
					cout << edges[i] << " ";
				}else{
					cout << edges[i] << endl;
				}
			}
		}else{
			cout << "forest" << endl;
		}

		setWeights.clear();
	}

	return 0;
}
