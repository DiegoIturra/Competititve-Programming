/*
12376 As Long as I Learn, I Live (ACEPTADO)
Codigo Propio
Nombre: Diego Iturra Huenteo
Uva Username: diturra2016
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int bestNode,maxValue = 0;

void dfs(int startNode,vector<vector<int>>& graph,vector<int>& Learning,vector<bool>& visited){
	visited[startNode] = true;

	//si no existen mas vecinos a partir de un nodo es que ya no se puede seguir explorando
	if(!graph[startNode].size())
		return;

	//tomamos el nodo con el maximo valor de aprendizaje
	int maxLearning = 0;
	for(int i=0 ; i<graph[startNode].size() ; i++){
		int currentNode = graph[startNode][i];
		if(Learning[currentNode] > maxLearning){
			maxLearning = Learning[currentNode];
			bestNode = currentNode;
		}
	}

	maxValue += maxLearning; //sumo el mejor aprendizaje

	if(!visited[bestNode])
		dfs(bestNode,graph,Learning,visited); //recursivamente hacer un dfs a partir del mejor nodo
}

int main(){
	
	int testCases,numNodes,numEdges,u,v,learning;
	cin >> testCases;

	for(int k=1 ; k<=testCases ; k++){
		cin >> numNodes >> numEdges;

		vector<vector<int>> graph(numNodes); //grafo
		vector<bool> visited(numNodes); //vector de visitados
		vector<int> Learning(numNodes); //aprendizaje de cada nodo

		//leer el aprendizaje de cada nodo y guardarlo en un vector de enteros
		for(int i=0 ; i<numNodes ; i++){
			cin >> learning;
			Learning[i] = learning;
		}

		//leer las aristas y generar el grafo
		for(int i=0 ; i<numEdges ; i++){
			cin >> u >> v;
			graph[u].push_back(v);
		}

		maxValue = 0;
		dfs(0,graph,Learning,visited);

		cout << "Case " << k << ": " << maxValue << " " << bestNode << endl;

	}	

	return 0;
}