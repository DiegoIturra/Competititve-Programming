/*Uva 820 Internet Bandwidth (ACEPTADO)
Nombre: Diego Iturra Huenteo
Codigo propio
uva username: diturra2016
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 1e9
#define MAX_V 100
using namespace std;

int source,destination,max_flow,flow;

int graph[MAX_V][MAX_V]; //grafo
vector<int> parents; //guarda el BFS spanning tree

/*encontrar camino aumentante a partir de un nodo*/
void augment(int v , int minEdge){
	if(v == source){
		flow = minEdge;
		return;
	}else if(parents[v] != -1){
		augment(parents[v] , min(minEdge , graph[parents[v]][v]));
		graph[parents[v]][v] -= flow;
		graph[v][parents[v]] += flow;
	}
}


/*No existen dos aristas entre dos nodos iguales , sino la suma 
de las capacidades de ambas aristas*/
void addEdge(int u , int v , int capacity){
	graph[u][v] += capacity;
	graph[v][u] += capacity;
}


int main(){
	int numNodes,numEdges;
	int numCase = 1;
	while(cin >> numNodes , numNodes){
		cin >> source >> destination >> numEdges;
		source--; destination--;

		int from,to,capacity;

		//setear grafo con capacidades en cero
		memset(graph, 0, sizeof(graph));

		//crear grafo
		for(int i=0 ; i<numEdges ; i++){
			cin >> from >> to >> capacity;
			from--;	to--;
			addEdge(from,to,capacity);
		}

		//algoritmo de Edmonds Karp (sacado de libro competitive programming 3)
		max_flow = 0;
		while(1){
			flow = 0;
			
			vector<int> dist(numNodes,INF);
			dist[source] = 0;

			queue<int> q;
			q.push(source); //pushear nodo fuente en la cola
			parents.assign(numNodes,-1);
			
			//BFS
			while(!q.empty()){
				int u = q.front();
				q.pop();
				if(u == destination) break;
				for(int v=0 ; v<numNodes ; v++){
					if(graph[u][v] > 0 && dist[v] == INF){
						dist[v] = dist[u] + 1;
						q.push(v); //agregar el vecino a la cola
						parents[v] = u; //el padre del nodo v es u
					}
				}
			}

			augment(destination,INF); //hallar la arista con menor capacidad en el camino actual
			if(flow == 0) break; //ya no se puede enviar mas flujo
			max_flow += flow;
		}
		cout << "Network " << numCase++ << endl;
		cout << "The bandwidth is " << max_flow << "." << endl;
		cout << endl;
 	}

	return 0;
}