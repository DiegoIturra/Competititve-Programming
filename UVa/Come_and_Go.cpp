/*
Uva 11838 Come and Go (ACEPTADO)
Nombre: Diego Iturra Huenteo
uva username: diturra2016
Codigo Propio
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

vector<int> low,num,S; //S para pushear nodos visitados

//numero de componentes fuertemente conexas y de componentes conexas
int numSCC = 0 , numCC = 0 , numVisited = 0;

/*Algoritmo de Tarjan del libro Competitive programming 3*/
void tarjanSCC(int u){
	low[u] = num[u] = numVisited++;
	S.push_back(u); 
	visited[u] = true;
	for(int j=0 ; j<(int)graph[u].size() ; j++){
		int neighbour = graph[u][j];
		if(num[neighbour] == 0){
			tarjanSCC(neighbour);
		}
		if(visited[neighbour]){
			low[u] = min(low[u],low[neighbour]);
		}
	}
	if(low[u] == num[u]){
		++numSCC;
		while(true){
			int v = S.back();
			S.pop_back();
			visited[v] == false;
			if(u == v){
				break;
			}
		}
	}
}


int main(){
	int NumNodes , numEdges , u,v,links;
	//leer la entrada mientras los valores sean distintos a cero
	while(cin >> NumNodes >> numEdges,NumNodes,numEdges){

		//asignar memoria para los vectores
		graph.assign(NumNodes,vector<int>());
		visited.assign(NumNodes,false);
		low.assign(NumNodes,0);
		num.assign(NumNodes,0);

		while(numEdges--){
			cin >> u >> v >> links;

			//crear grafo
			if(links == 1){
				graph[u-1].push_back(v-1); //crea una arista de u->v
			}else{
				graph[u-1].push_back(v-1); //crea arista desde u->v y de v->u
				graph[v-1].push_back(u-1);
			}
		}

		//recorrer el grafo y ver las SCC
		for(int i=0 ; i<NumNodes ; i++){
			if(!visited[i]){
				tarjanSCC(i);
				numCC++;
			}
		}

		/*si tenemos una sola SCC y una sola CC es porque el grafo es conexo y ademas fuertemente conexo,
		de los contrario pueden haber varias componentes fuertemente conexas pero no es un grafo conexo*/
		if(numCC == 1 && numSCC == 1){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
		numSCC = 0;
		numCC = 0;
	}
	return 0;
}