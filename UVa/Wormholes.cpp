#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1<<20
using namespace std;

vector<vector<pair<int,int>>> graph;
vector<int> dist;

void Bellman_Ford(int V,int start){
	dist[start] = 0;
	for(int i=0 ; i<V-1 ; i++){ //relajar todas las aristas V-1 veces

		//para cada nodo u en el grafo, relajar la arista de u->v
		for(int u=0 ; u<V ; u++){
			for(int v=0 ; v<(int)graph[u].size() ; v++){
				//obtenemos el nodo adyacente al nodo u
				pair<int,int> neighbour = graph[u][v];
				/*nos quedamos con la disntacia minima entre la distancia actual hacia el vecino
				y la distancia del nodo actual mas el costo (tiempo) de ir al nodo vecino*/

				if(dist[u] + neighbour.second < dist[neighbour.first]){
					dist[neighbour.first] = dist[u] + neighbour.second;
				}
			}
		}
	}

	//comprobar si hay un ciclo negativo
	bool hasNegativeCycle = false;
	for(int u=0 ; u<V ; u++){
		for(int v=0 ; v<(int)graph[u].size() ; v++){
			pair<int,int> neighbour = graph[u][v];
			//si la suma de los tiempos es menor al tiempo de de u->v, es porque hay un ciclo negativo
			if(dist[u] + neighbour.second < dist[neighbour.first]){
				hasNegativeCycle = true;
			}
		}
	}
	if(hasNegativeCycle){
		cout << "possible" << endl;
	}else{
		cout << "not possible" << endl;
	}
}	

int main(){
	int testCases;
	cin >> testCases;

	while(testCases--){
		int numSpaces,numWormholes;
		int x,y,time;
		cin >> numSpaces >> numWormholes;

		graph.assign(numSpaces , vector<pair<int,int>>()); //crear grafo
		dist.assign(numSpaces,INF);

		for(int i=0 ; i<numWormholes ; i++){
			cin >> x >> y >> time;
			graph[x].push_back(make_pair(y,time)); //creamos una arista de x-y con un peso: time
		}

		Bellman_Ford(numSpaces,0); //lanzamos el algoritmo a partir del nodo 0

	}

	return 0;
}