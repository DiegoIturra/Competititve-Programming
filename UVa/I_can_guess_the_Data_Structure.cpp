//UVa 11995 I Can Guess the Data Structure! (ACEPTADO)
#include <iostream>
#include <utility>
#include <stack>
#include <queue>
using namespace std;

int main(){
	int testCases;
	int command,x;
	while(cin >> testCases){
		//para cada caso de prueba
		vector<pair<int,int>> instructions;
		for(int i=0 ; i<testCases ; i++){
			cin >> command >> x;
			instructions.push_back(make_pair(command,x));
		}
		//una vez obetenido el caso de prueba vamos insertando en una queue,stack y pq
		//para cada elemento en el vector de instrucciones se inserta o se remueve un elemento
		int len = instructions.size();
		stack<int> myStack;
		queue<int> myQueue;
		priority_queue<int> myPriorityQueue;
		bool isStack = true;
		bool isQueue = true;
		bool isPQ = true;
		for(int i=0 ; i<len ; i++){
			//si es un 1 entonces se inserta en las estructuras
			if(instructions[i].first == 1){
				myStack.push(instructions[i].second);
				myQueue.push(instructions[i].second);
				myPriorityQueue.push(instructions[i].second);
			}
			//si es un 2 , entonces sacamos de la estructura
			else if(instructions[i].first == 2){
				//verificar que no saque elementos si estan vacios
				if(!myStack.empty() && !myQueue.empty() && !myPriorityQueue.empty()){
					if(instructions[i].second != myStack.top()) isStack = false;
					if(instructions[i].second != myQueue.front()) isQueue = false;
					if(instructions[i].second != myPriorityQueue.top()) isPQ = false;
					myStack.pop();
					myQueue.pop();
					myPriorityQueue.pop();
				}
				//si ambas estructuras estan vacias
				else{
					isPQ = false;
					isStack = false;
					isQueue = false;
				}
			}
		}
		//vemos que tipo de estructura es
		if(isStack && !isQueue && !isPQ) cout << "stack" << endl;
		else if(isQueue && !isStack && !isPQ) cout << "queue" << endl;
		else if(isPQ && !isStack && !isQueue) cout << "priority queue" << endl;
		else if(!isPQ && !isStack && !isQueue) cout << "impossible" << endl;
		else cout << "not sure" << endl;
	}
	return 0;
}
