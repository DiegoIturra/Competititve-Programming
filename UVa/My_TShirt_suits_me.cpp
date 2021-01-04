/*
11045 My T-shirt suits me (ACEPTADO)
Nombre: Diego Iturra Huenteo
codigo Propio
uva username: diturra2016
*/
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <iterator>
#include <vector>
#include <queue>
#include <map>
#define INF 1e9	
using namespace std;

int max_flow , flow , s , t;
vector<int> p; //guarda el BFS Spanning Tree

int N,M;
vector<vector<int>> graph; //matriz de adyacencia

void augment(int v , int minEdge){
	if(v == s){
		flow = minEdge;
		return;
	}else if(p[v] != -1){
		augment(p[v],min(minEdge,graph[p[v]][v]));
		graph[p[v]][v] -= flow;
		graph[v][p[v]] += flow;
	}
}

/*todas las aristas que van desde las tallas hasta los usuarios , solo pueden llevar una talla
por usuario*/
void parse(const string& size,int index){
	if(size == "XS")
		graph[1][index] = 1;
	else if(size == "S")
		graph[2][index] = 1; 
	else if(size == "M")
		graph[3][index] = 1;
	else if(size == "L")
		graph[4][index] = 1;
	else if(size == "XL")
		graph[5][index] = 1;
	else
		graph[6][index] = 1;
}

//agregar una arista dirigida en el grafo
void addEdge(int u , int v , int capacity){
	graph[u][v] = capacity;
}

void showGraph(int size){
	for(int i=0 ; i<size ; i++){
		for(int j=0 ; j<size ; j++){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
	int numCases;
	cin >> numCases;

	while(numCases--){
		cin >> N >> M; //leer numero de poleras y usuarios
		string size1 , size2;

		/*Como maximo 36 usuarios + 2 nodos (s y t) mas nodos correspondientes a las 
		tallas de ropa*/
		graph.assign(44,vector<int>(44));

		/*Flujo total desde el nodo S hata los nodos de las poleras es repartiendo el numero
		de poleras entre todas las tallas disponibles (Enunciado dice N multiplo de 6)*/
		int initial_capacity = N / 6;

		//Nodos: total de usuarios(M) + 2 nodos imaginarios (s y t) + 6 tallas disponibles
		int numNodes = M + 8;

		//leer M lineas
		for(int i=7 ; i<numNodes-1 ; i++){
			cin >> size1 >> size2;
			parse(size1,i);
			parse(size2,i);
		}

		/* crear aristas desde el nodo fuente s=0 hacia los nodos correspondientes
		a las tallas de las poleras */
		for(int i=1 ; i<=6 ; i++){
			addEdge(0,i,initial_capacity);
		}

		/*Crear aristas desde los nodos usuarios al nodo destino t (ultimo nodo)*/

		/*Si se modelan las aristas hasta el nodo t con la sumatoria de las capacidades
		de entrada del nodo anterior,da WA*/
		for(int i=7 ; i<numNodes-1 ; i++){
			addEdge(i,numNodes-1,1);
		}

		//Algoritmo Edmonds Karp (Competitive programming 3)
		max_flow = 0;
		s = 0; //primer nodo
		t = numNodes-1; //ultimo nodo en el grafo
		while (1) {
			flow = 0;
			vector<int> dist(numNodes, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			p.assign(numNodes, -1);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				if (u == t)
					break;
				for (int v = 0; v < numNodes; v++){
					if (graph[u][v] > 0 && dist[v] == INF){
						dist[v] = dist[u] + 1;
						q.push(v);
						p[v] = u;
					}
				}
			}
			augment(t, INF);
			if (flow == 0)
				break;
			max_flow += flow;
		}

		/*El problema es un problema de asignación modelado como un max flow, agregando dos nodos extra
		(s y t), si el total de poleras que podemos mandar de s hasta t es igual a numero de usuarios entre los
		cuales se tienen que asignar las poleras es porque se realizo una correcta asignacion de poleras*/
		if(max_flow == M){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}