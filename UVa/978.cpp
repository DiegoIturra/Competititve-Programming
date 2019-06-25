#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
	int testCases;
	cin >> testCases; 
	
	//para cada caso de prueba
	for(int i=0 ; i<testCases ; i++){
		/*contenedor de los poderes de cada lemming de  ambos ejercitos */
		priority_queue<int> greenArmy , blueArmy; 
		int battlefields , greenLemmings , blueLemmings;
		cin >> battlefields >> greenLemmings >> blueLemmings; //leemos cada caso de prueba
		int greenPower , bluePower;
		//para cada Lemming verde
		for(int j=0 ; j<greenLemmings ; j++){
			cin >> greenPower;
			greenArmy.push(greenPower);
		}
		//para cada Lemming azul
		for(int j=0 ; j<blueLemmings ; j++){
			cin >> bluePower;
			blueArmy.push(bluePower);
		}
		//procesar info
	}
	return 0;
}

		//imprimir info de cada ejercito
		/*
		while(!greenArmy.empty()){
			cout << greenArmy.top() << " ";
			greenArmy.pop();
		}
		cout << endl;
		while(!blueArmy.empty()){
			cout << blueArmy.top() << " ";
			blueArmy.pop();
		}
		cout << endl; */
//lemmings , entrada leida de forma correcta