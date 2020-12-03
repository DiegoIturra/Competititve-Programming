/*
Uva 908 Re-connecting Computer Sites (ACEPTADO)
Codigo Propio
Nombre: Diego Iturra Huenteo
uva username: diturra2016
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Edge{
	int id;
	int cost;

	bool operator>(const Edge& edge) const{
		return this->cost > edge.cost;
	}
};

int numComputers;
vector<vector<Edge>> graph;
vector<bool> taken;
priority_queue<Edge,vector<Edge>,greater<Edge>> pq;


void addEdge(int u,int v,int cost){
	Edge edge;
	edge.id = v;
	edge.cost = cost;
	graph[u].push_back(edge);
	edge.id = u;
	graph[v].push_back(edge);
}

void process(int node){
	taken[node] = true;

	for(int i=0 ; i<(int)graph[node].size() ; i++){
		Edge neighbour = graph[node][i];
		if(!taken[neighbour.id]){
			pq.push(neighbour);
		}
	}
}

int Prim(){
	process(0);
	unsigned int mst_cost = 0;

	while(!pq.empty()){
		Edge front = pq.top();
		pq.pop();
		int u = front.id;
		int cost = front.cost;
		if(!taken[u]){
			mst_cost += cost;
			process(u);
		}
	}
	return mst_cost;
}


int main(){
	int lastCase = 0;

	while(cin >> numComputers){

		int u,v,cost;
		unsigned int totalCost = 0;
		for(int i=0 ; i<numComputers-1 ; i++){
			cin >> u >> v >> cost;
			totalCost += cost; //guardar el costo del primer MST antes de agregar las k nuevas lineas
		}

		int newLines;
		cin >> newLines;

		//asignar memoria
		graph.assign(numComputers,vector<Edge>());
		taken.assign(numComputers,false);

		//agregamos al grafo original las nuevas aristas para calcular un nuevo MST
		while(newLines--){
			cin >> u >> v >> cost;
			addEdge(u-1,v-1,cost);
		}

		//agregar las aristas del grafo original
		int originalSize;
		cin >> originalSize;
		while(originalSize--){
			cin >> u >> v >> cost;
			addEdge(u-1,v-1,cost);
		}

		if(lastCase != 0) cout << "\n";
		cout << totalCost << "\n";
		cout << Prim() << "\n";
		lastCase++;

	}

	return 0;
}