/*
Uva 821 Page Hopping (ACEPTADO)
Nombre: Diego Iturra Huenteo
uva username: diturra2016
Codigo Propio
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1 << 20 //2^20
using namespace std;

vector<vector<int>> dist; //grafo con las distancias correspondientes
vector<pair<int,int>> adyacency; //vector temporal para guardar aristas entre nodos

/*inicia la matriz de distnacias (grafo)*/
void initialize(int size){
	for(int i=0 ; i<size ; i++){
		for(int j=0 ; j<size ; j++){
			if(i == j){
				dist[i][j] = 0;
			}else{
				dist[i][j] = INF;
			}
		}
	}
}

/*Aplicar algoritmo Floyd Warshall para All Pairs Shortest Path*/
void floyd_Warshall(int size){
	for(int k=0 ; k<size ; k++){
		for(int i=0 ; i<size ; i++){
			for(int j=0 ; j<size ; j++){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

/*Funcion para entregar el resultado de clicks*/
double solve(int size){
	int counter = 0; //contar la cantidad de distancias totales
	int totalSum = 0; //suma total de los valores 
	for(int i=0 ; i<size ; i++){
		for(int j=0 ; j<size ; j++){
			if(dist[i][j] != 0 && dist[i][j] != INF){
				totalSum += dist[i][j]; //si existe camino, va sumando las distancias
				counter++; //hallamos una distancia valida
			}
		}
	}
	return double(totalSum) / double(counter); 
}

int main(){
	int u,v;
	int numCase = 0;
	while(true){
		int maxNode = -1;

		//Parsear Input
		cin >> u >> v; //leo la primera linea 
		if(u == 0 && v == 0) break; //si es 0,0 es porque leyo el fichero completo y termina

		/*si no entra en el if entonces nos quedamos con el valor de u,v actual*/
		maxNode = max({u,v,maxNode});

		adyacency.push_back(make_pair(u,v));

		/*Se toma el maximo valor de u,v para saber de que dimension sera la matriz
		de distancias*/
		while(cin >> u >> v,u,v){
			maxNode = max({maxNode,u,v});
			adyacency.push_back(make_pair(u,v));
		}

		//creamos una matriz de adyacencia para representar el grafo
		dist.assign(maxNode,vector<int>(maxNode));

		//inicializar distancias
		initialize(maxNode);

		//en la matriz asignar con valor 1 los enlaces existentes
		for(int i=0 ; i<adyacency.size() ; i++){
			//distancia es 1 entre cada par de nodos
			dist[adyacency[i].first-1][adyacency[i].second-1] = 1;
		}

		floyd_Warshall(maxNode);

		printf("Case %d: average length between pages = %.3f clicks\n",++numCase,solve(maxNode));

		adyacency.clear();
	}
	return 0;
}