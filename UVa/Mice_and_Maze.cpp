/*Uva 1112 	Mice and Maze (ACEPTADO)
Nombre: Diego Iturra
uva username: diturra2016
Codigo Propio*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 99999
using namespace std;

vector<vector<int>> graph;

void initialize(int size,int idExitCell){
	for(int i=0 ; i<size ; i++){
		for(int j=0 ; j<size ; j++){
			graph[i][j] = INF;
			//si es la celda de salida el camino es directo, el cual es 1
			if(i == idExitCell-1 && j == idExitCell-1){
				graph[i][j] = 1;
			}
		}
	}
}

void floyd_Warshall(int size){
	for(int k=0 ; k<size ; k++){
		for(int i=0 ; i<size ; i++){
			for(int j=0 ; j<size ; j++){
				if(graph[i][j] > graph[i][k] + graph[k][j]){
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}


int main(){
	int testCases;
	cin >> testCases;

	int numCells,idExitCell,total_time,numConections;
	for(int j=0 ; j<testCases ; j++){
		cin >> numCells >> idExitCell >> total_time >> numConections;

		//asignar memoria al grafo
		graph.assign(numCells , vector<int>(numCells)); 
		initialize(numCells,idExitCell);
		
		//leer conexiones del grafo y asignar los tiempos correspondientes
		int u,v,time;
		while(numConections--){
			cin >> u >> v >> time;

			graph[u-1][v-1] = time;
		}

		floyd_Warshall(numCells);

		/*Recorrer la columna correspondiente al nodo de salida , ya que es la distancia de 
		todos los nodos hasta el nodo de salida*/
		int answer = 0;
		for(int i=0 ; i<numCells ; i++){
			if(graph[i][idExitCell-1] <= total_time){
				answer++;
			}
		}

		//si es el ultimo caso
		if(j == testCases-1){
			cout << answer << endl;
		}
		else{
			cout << answer << endl;
			cout << endl;
		}
	}
	return 0;
}