//Uva 11136 Hoax or what(ACEPTADO)
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main(void){
	int testCases;
	while(cin >> testCases){
		if(testCases == 0) break;
		//para todos los casos de prueba
		int k_number;
		multiset<int> urna;
		multiset<int>::iterator itMenor;
		multiset<int>::iterator itMayor;
		unsigned long long int total = 0; //para casos muy grandes int da negativo
		for(int i=0 ; i<testCases ; i++){
			cin >> k_number;
			//para k numeros
			int bill;
			for(int j=0 ; j<k_number ; j++){
				cin >> bill;
				urna.insert(bill);
			}
			itMenor = urna.begin(); //primer elemento
			int menor = *itMenor;
			itMayor = urna.end(); //ultimo elemento
			itMayor--; //ya que end() es una posicion mas alla del termino del multiset
			int mayor = *itMayor;
			
			total = total + (mayor-menor);
			//luego se quitan los elementos de la urna
			//y a la siguiente iteracion se ingresan los del dia siguiente
			urna.erase(itMayor);
			urna.erase(itMenor);
			/*se borra a lo que apunta los iteradores , ya que si borro el elemento directamente
			  se borran todas las ocurrencias*/ 
		}
		cout << total << endl;
	}
	return 0;
}

