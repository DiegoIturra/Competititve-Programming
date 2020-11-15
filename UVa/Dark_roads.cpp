/*Uva 11631 Dark roads (ACEPTADO)
Nombre: Diego Iturra Huenteo
uva username: diturra2016
Codigo Propio*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int id;
	int length;

	//comparar por campo length
	bool operator>(const Node& node) const{
		return this->length > node.length;
	}
};

int numNodes , numEdges; //numero de nodos y aristas respectivamente
vector<vector<Node>> graph;
vector<bool> taken;
priority_queue<Node,vector<Node>,greater<Node>> pq;


/*Toma todas las aristas adyacentes a un nodo y las inserta en una cola de prioridad*/
void process(int node){
	taken[node] = true; //marcar nodo incial como tomado

	//para todos los nodos adyacentes a node
	for(int j=0 ; j<(int)graph[node].size() ; j++){
		Node v = graph[node][j];
		if(!taken[v.id]){ //si no ha sido visitado
			pq.push(v); //insertar en la cola de prioridad
		}
	}
}

/*Algoritmo de Prim para obtener un MST,sacado de libro Competitive Programming 3*/
int Prim(){
	taken.assign(numNodes,false); //asignar memoria
	process(0); //procesar nodo 0 inicialmente
	unsigned long long mst_cost = 0; //costo del minimum spanning tree

	//mientras la cola no este vacia
	while(!pq.empty()){
		Node front = pq.top(); //tomamos la arista con menos costo
		pq.pop();
		int u = front.id;
		int length = front.length;
		if(!taken[u]){ //si no ha sido visitada la arista 
			mst_cost += length; //entonces sumar la longitud de la menor arista al costo del MST
			process(u); //y procesar el nodo a cual lleva la menor arista
		}
	}
	return mst_cost;
}

/*solo muestra info del grafo creado*/
void printGraph(int numNodes){
	for(int i=0 ; i<numNodes ; i++){
		cout << "Node " << i << " -> ";
		for(int j=0 ; j<graph[i].size() ; j++){
			cout << graph[i][j].id << ":" << graph[i][j].length << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
	while(cin >> numNodes >> numEdges){
		if(!numNodes && !numEdges) break;

		graph.assign(numNodes , vector<Node>());

		unsigned long long total_length = 0; //suma total de la longitud de las aristas
		int u,v,length; //nodo u-v y su longitud
		Node node; //nodo para ir guardando info de cada conexion
		while(numEdges--){
			cin >> u >> v >> length;
			total_length += length;

			//generar grafo
			node.id = v;
			node.length = length;
			graph[u].push_back(node);
			node.id = u;
			graph[v].push_back(node);
		}
		/*lo que se ahorra es la suma de todas las aristas , menos la suma del MST */
		cout << total_length - Prim() << endl;
	}
	return 0;
}
