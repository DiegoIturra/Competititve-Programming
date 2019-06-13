//UVa 10954	Add All (ACEPTADO)
#include <iostream>
#include <queue>
#include <functional> //para crear un minHeap
#include <iterator>
using namespace std;

int main(){
	int testCases;
	while(cin >> testCases){
		if(testCases == 0) break;
		//para cada caso de prueba
		priority_queue<int,vector<int>,greater<int>> queueNumbers;
		int num;
		for(int i=0 ; i<testCases ; i++){
			cin >> num;
			queueNumbers.push(num);
		}
		/*al tenerlos en orden ascendete la suma es la menor de todas las otras combinaciones*/
		int num1,num2,sum = 0;
		while(queueNumbers.size() > 1){
			//extraigo los dos primeros numeros de la queue
			num1 = queueNumbers.top();
			queueNumbers.pop();
			num2 = queueNumbers.top();
			queueNumbers.pop();
			//almaceno la suma de los numeros extraidos
			//y se suma con el costo anterior
			int sumAux = num1 + num2;
			queueNumbers.push(sumAux);
			sum = sum + sumAux;
		}
		cout << sum << endl;
	}
	return 0;
}