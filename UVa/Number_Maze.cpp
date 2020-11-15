/*Uva 929 	Number Maze (ACEPTADO
Nombre: Diego Iturra huenteo
uva username: diturra2016
Codigo Propio
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 99999
using namespace std;

int maze[1000][1000]; //grafo (grilla)
int dist[1000][1000]; //matriz de distancias desde (0,0) hasta (x,y)
int N,M; //dimensiones de la matriz

const int moveX[] = {-1,1,0,0};
const int moveY[] = {0,0,-1,1};


struct Node{
	int x,y;
	int wheight;

	//sobrecargar operador > para comparar en base al peso del nodo
	bool operator>(const Node& node) const{
		return this->wheight > node.wheight;
	}
};	


void Dijkstra(int source_x , int source_y){
	priority_queue<Node,vector<Node>,greater<Node>> Queue; //cola de prioridad

	dist[source_x][source_y] = maze[source_x][source_y]; //la distancia del nodo inicial es cero

	Node node;
	node.x = source_x; //(x,y) parte en 0,0
	node.y = source_y; 
	node.wheight = maze[0][0]; //costo del nodo inicial
	Queue.push(node); //agregar nodo incial a la cola de prioridad

	while(!Queue.empty()){
		//extraer el minimo de la cola de prioridad
		Node current = Queue.top();
		Queue.pop();


		//para todos los vecinos adyacentes al nodo
		for(int i=0 ; i<4 ; i++){
			/*4 posibles movimientos (arriba,abajo,izquierda,derecha)*/
			int x = current.x + moveX[i];
			int y = current.y + moveY[i];

			//verificar que el vecino este dentro de los limites matriz
			if(x >= 0 && y >= 0 && x < N && y < M){
				if(dist[current.x][current.y] + maze[x][y] < dist[x][y]){
					dist[x][y] = dist[current.x][current.y] + maze[x][y];

					//actualizar los valores y volver a insertar en la cola de prioridad
					node.x = x;	
					node.y = y;
					node.wheight = dist[x][y];
					Queue.push(node);
				}
			}
		}
	}	
	cout << dist[N-1][M-1] << endl;
}


int main(){
	int numMazes;
	cin >> numMazes;

	while(numMazes--){
		cin >> N >> M;

		//leer grafo
		for(int i=0 ; i<N ; i++){
			for(int j=0 ; j<M ; j++){
				cin >> maze[i][j];
				dist[i][j] = INF; //iniciar la matriz de distancias en infinito
			}
		}
		Dijkstra(0,0);
	}
	return 0;
}