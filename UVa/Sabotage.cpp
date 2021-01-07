/*Uva 10480 Sabotage (ACEPTADO)
Nombre: Diego Iturra Huenteo
Codigo Propio
uva username: diturra2016
codigo para min-cut: https://www.geeksforgeeks.org/minimum-cut-in-a-directed-graph/
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 1e9
#define MAX_V 51 
using namespace std;

int graph[MAX_V][MAX_V],res[MAX_V][MAX_V];
bool visited[MAX_V];

int N,M,flow,source,destination,max_flow;
vector<int> parents;

void addEdge(int u,int v,int capacity){
	graph[u][v] = capacity;
	graph[v][u] = capacity;
}

void augment(int v, int minEdge){
	if(v == source){
		flow = minEdge;
		return;
	}else if(parents[v] != -1){
		augment(parents[v] , min(minEdge , res[parents[v]][v]));
		res[parents[v]][v] -= flow;
		res[v][parents[v]] += flow;
	}
}

//copiar matriz
void copy(int numNodes){
	for(int i=0 ; i<numNodes ; i++){
		for(int j=0 ; j<numNodes ; j++){
			res[i][j] = graph[i][j];
		}
	}
}


void dfs(int s,int numNodes){
	visited[s] = true;
	for(int i=0 ; i<numNodes ; i++){
		if(res[s][i] && !visited[i]){
			dfs(i,numNodes);
		}
	}
}

int main(){
	while(cin >> N >> M){
		if(!N && !M) break;

		memset(graph,0,sizeof(graph));
		memset(visited,false,sizeof(visited));
		memset(res,0,sizeof(res));

		int from,to,capacity;
		source = 0;
		destination = 1;
		for(int i=0 ; i<M ; i++){
			cin >> from >> to >> capacity;
			from--; to--;
			addEdge(from,to,capacity);
		}

		//Generar un grafo residual , y guardar grafo original
		copy(N);

		//una vez se crea la red , usar Edmond Karp (Competitive programming 3)
		max_flow = 0;
		while(1){
			flow = 0;
			
			vector<int> dist(N,INF);
			dist[source] = 0;

			queue<int> q;
			q.push(source); //pushear nodo fuente en la cola
			parents.assign(N,-1);
			
			//BFS
			while(!q.empty()){
				int u = q.front();
				q.pop();
				if(u == destination) break;
				for(int v=0 ; v<N ; v++){
					if(res[u][v] > 0 && dist[v] == INF){
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

		/*Lanzar un DFS a partir del nodo fuente S , y marcar los vertices que fueron 
		acanzados en el recorrido , el dfs se hace en el grafo residual una vez obtenido
		el max flow*/
		dfs(0,N);
		
		/*Recorrer el grafo y ver si existe una arista u-v dentro del grafo el vertice u este 
		visitado (pertenece a un conjunto S) y el vertice v no este visitado (Pertenece a otro
		conjunto T), si cumple dicha condicion es porque la arista u-v pertence al min-cut*/
		for(int i=0 ; i<N ; i++){
			for(int j=0 ; j<N ; j++){
				if(visited[i] && !visited[j] && graph[i][j]){
					cout << i+1 << " " << j+1 << endl;
				}
			}
		}
		cout << endl;
	}
	return 0;
}