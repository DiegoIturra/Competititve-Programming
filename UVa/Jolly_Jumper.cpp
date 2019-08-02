//UVA 10038 Jolly Jumper (ACEPTADO)
#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int N;
	//leemos los N numeros de la secuencia
	while(cin >> N){
		vector<int> secuencia;
		vector<int> diferencias;
		//ingresamos la secuencia de numeros
		for(int i=0 ; i<N ; i++){
			int num;
			cin >> num;
			secuencia.push_back(num);
		}
		//calculamos las diferencias absolutas y las guardamos en un vector
		vector<bool> numeros(N+1,false);
		int dif;
		if(N==1){
			dif = secuencia[0];
			diferencias.push_back(dif);
		}
		else{
			for(int i=0 ; i<N-1 ; i++){
				dif = abs(secuencia[i] - secuencia[i+1]);
				diferencias.push_back(dif);
				numeros[dif] = true;
			}
		}
		//vemos si estan los numeros de 1 a n-1 en nuestro vector de booleanos
		bool flag = true;
		for(int i=1 ; i<N ; i++){
			if(numeros[i] == false){
				cout << "Not jolly" << endl;
				flag = false;
				break;
			}
		}
		if(flag == true){
			cout << "Jolly" << endl;
		}
	}
	return 0;
}
