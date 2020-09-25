/*
Uva 280 Vertex (ACEPTADO)
Codigo Propio
Nombre: Diego Iturra
uva username: diturra2016
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;


void dfs(int start){
	for(int i=0 ; i<graph[start].size() ; i++){
		int neighbour = graph[start][i];
		if(!visited[neighbour]){
			visited[neighbour] = true;
			dfs(neighbour);
		}
	}
}

int main(){

	int numNodes;

	while(cin >> numNodes , numNodes){

		graph.assign(numNodes, vector<int>()); //nodos de 0 a n-1

		int startNode;
		while(cin >> startNode,startNode){ //leer el nodo de comienzo hasta que lea un cero
			startNode--;

			int neighbour;
			while(cin >> neighbour,neighbour){ //leer los vecinos hasta que lea un cero
				neighbour--;
				graph[startNode].push_back(neighbour); //crear grafo
			}
		}

		int numQueries,start;
		cin >> numQueries;
		while(numQueries--){ //por cada consulta leer el nodo de partida y hacer un dfs a partir de ese nodo
			cin >> start;
			start--;
			visited.assign(numNodes,false);

			dfs(start);

			//una vez hecho el dfs ,ver los nodos que quedaron sin visitar
			int count = 0;
			vector<int> nonVisited;
			for(int i=0 ; i<visited.size() ; i++){
				if(!visited[i]){
					count++;
					nonVisited.push_back(i+1);
				}
			}


			if(!count){
				cout << 0 << '\n';
			}else{
				cout << count << " ";
				int size = nonVisited.size();
				for(int i=0 ; i<size ; i++){
					if(i < size-1)
						cout << nonVisited[i] << " ";
					else
						cout << nonVisited[i] << '\n';
				}
			}
		}
	}
	return 0;
}