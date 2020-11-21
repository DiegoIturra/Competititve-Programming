/*
Uva 872 Ordering (ACEPTADO)
Nombre: Diego Iturra Huenteo
uva username: diturra2016
Codigo Propio
funcion para todos los ordenes topologicos: https://www.techiedelight.com/find-all-possible-topological-orderings-of-dag/
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> indegree; //vector que guarda el grado de incidencia de cada nodo
vector<bool> visited;
map<int,char> hashNodes; //mapear de char a int
map<char,int> aux; //mapear de int a char
vector<vector<int>> all_path; //guarda todos los caminos posibles


//Generar arista 
void addEdge(int u, int v){
	graph[u].push_back(v); //digrafo
	indegree[v]++; //existe un arco de u->v , por lo tanto v aumenta su grado de llegada
}

//imprimir combinacion
void printPath(vector<int> path){
	for(int i=0 ; i<path.size() ; i++){
		if(i < path.size()-1){
			cout << hashNodes[path[i]] << " ";
		}else{
			cout << hashNodes[path[i]] << endl;
		}
	}
}

//generar todos los ordenes topologicos de un DAG
void all_topo_sort(vector<int>& path ,int numNodes){
	//probar combinaciones para cada uno de los nddos
	for(int v=0 ; v<numNodes ; v++){
		//si el nodo actual no tiene aristas de llegada y no ha sido visitado
		if(indegree[v]==0 && !visited[v]){

			//disminuimos el grado de llegada de todos los nodos adyacentes al nodo actual
			for(int u: graph[v]){
				indegree[u]--;
			}

			//agregar el nodo actual al path y marcarlo como visitado
			path.push_back(v);
			visited[v] = true;

			//recusivamente hacerlo para los nodos adyacentes
			all_topo_sort(path,numNodes);

			//backtracking
			//aumentar la cantidad de nodos de llegada de los nodos adyacentes al nodo actual
			for(int u : graph[v]){
				indegree[u]++;
			}

			//quitarlo del path y desmarcarlo como visitado para pasar al siguiente nodo
			path.pop_back();
			visited[v] = false;
		}
	}

	//una vez recorrido todos los nodos ver en cada paso de la recursion si estan todos los nodos
	if(path.size() == numNodes){
		all_path.push_back(path);
	}
}

int main(){
	int testCases;
	scanf("%d\n\n",&testCases);

	for(int numCase=0 ; numCase<testCases ; numCase++){
		string tasks;
		getline(cin,tasks);

		string constraints;
		getline(cin,constraints);

		string blankLine;
		getline(cin,blankLine);

		vector<char> nodes;
		
		//recorrer string y guardar los nodos en un vector
		for(int i=0 ; i<tasks.size() ; i++){
			if(tasks[i] != ' '){
				nodes.push_back(tasks[i]);
			}
		}

		/*Ordenar antes de hacer un mapeo de los nodos y evitar ordenes distintos*/
		sort(nodes.begin() , nodes.end());

		//mapear nodos
		for(int i=0 ; i<nodes.size() ; i++){
			hashNodes[i] = (char)nodes[i];
			aux[(char)nodes[i]] = i;
		}

		//casignar memoria
		int numNodes = nodes.size();
		graph.assign(numNodes , vector<int>());
		visited.assign(numNodes,false);
		indegree.assign(numNodes,0); //todos los nodos parten con grado de llegada igual a cero

		//leer las restricciones y crear el grafo
		int index = 0;
		int u,v;
		for(int index=0 ; index < constraints.size() ; index += 2){
			u = aux[constraints[index]];
			index += 2;
			v = aux[constraints[index]];
			addEdge(u,v);
		}

		//generar todos los ordenes topologicos
		vector<int> path;
		all_topo_sort(path,numNodes);
		
		if(all_path.size()){
			//si no es el ultimo caso, imprimir un salto de linea entre caso
			if(numCase < testCases-1){
				for(auto path: all_path){
					printPath(path);
				}
				cout << endl;
			}else{
				for(auto path : all_path){
					printPath(path);
				}
			}
		}else{
			if(numCase < testCases-1){
				cout << "NO" << endl;
				cout << endl;
			}else{
				cout << "NO" << endl;;
			}
		}

		all_path.clear();
		aux.clear();
		hashNodes.clear();
	}	
	return 0;
}