//Uva 1237 - Expert Enough? (ACEPTADO)
#include <iostream>
#include <vector>	
using namespace std;

struct Car{
	string brand;
	int lowPrice;
	int highPrice;
};

int main(){
	int testCases,sizeDB;
	cin >> testCases;
	//para cada caso de prueba
	while(testCases--){
		cin >> sizeDB;
		string brand;
		int lowestPrice,highestPrice,numQueries;
		vector<Car> infoCar;
		Car car;

		//leer la info de cada marca
		while(sizeDB--){
			cin >> brand;
			cin >> lowestPrice >> highestPrice;

			//almacenar info de cada marca
			car.brand = brand;
			car.lowPrice = lowestPrice;
			car.highPrice = highestPrice;
			infoCar.push_back(car);
		}

		//leer las consultas
		cin >> numQueries;
		int query;
		while(numQueries--){
			cin >> query;
			//para cada consulta
			int counter = 0;
			string match;
			for(int i=0 ; i<infoCar.size() ; i++){
				//si esta dentro del rango
				if(query >= infoCar[i].lowPrice && query <= infoCar[i].highPrice){
					counter++;
					match = infoCar[i].brand;
				}
				if(counter > 1){
					break;
				}
			}
			if(counter == 0 || counter > 1){
				cout << "UNDETERMINED" << endl;
			}else{
				cout << match << endl;
			}
		}
		if(testCases != 0)
			cout << endl;
	}
	return 0;
}

