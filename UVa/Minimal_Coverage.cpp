//Uva 10020 Minimal Coverage (ACEPTADO)
/*
Codigo Propio
Nombre:Diego Iturra
uva username: diturra2016
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

/*comparador que permite ordenar el primer elemento en forma ascendente y el segundo elemento
en forma descendente*/
bool comparator(const pair<int,int>& p1 ,const pair<int,int>& p2){
	return p1.first < p2.first || (p1.first == p2.first && p1.second > p2.second);
}

int main(){
	int numCasos,M,left,right;
	cin >> numCasos;

	while(numCasos--){
		cin >> M;
		pair<int,int> intervalo;
		vector<pair<int,int>> intervalos; //vector de intervalos

		//leer entrada
		while(true){
			cin >> left >> right;
			if(left == 0 & right == 0) break;

			//descartar los valores fuera del rango [0-M]
			if(left < 0 && right < 0) continue;
			if(left > M) continue;
			intervalo = make_pair(left,right);
			intervalos.push_back(intervalo);
		}

		//ordenar vector
		sort(intervalos.begin(),intervalos.end(),comparator);

		//vector de soluciones , como maximo el numero de intervalos dados
		pair<int,int> solucion[intervalos.size()];

		int Xcubierto = 0;
		int i = 0;
		int indiceSolucion = 0;


		while(i < intervalos.size() && Xcubierto < M){
			solucion[indiceSolucion].second = 0; //marcar la derecha de la posible solucion actual en 0

			/*mientras el punto izquierdo del segmento actual este dentro del segmento cubierto
			actualmente , entonces buscar el mejor, ya que no podemos tomar un segmento que empiece mas 
			lejos del x cubierto , porque habria un segmento sin cubrir*/
			while(intervalos[i].first <= Xcubierto && i < intervalos.size()){
				//comprobar si el lado derecho es mas lejano al de nuestra solucion actual
				if(intervalos[i].second > solucion[indiceSolucion].second){
					solucion[indiceSolucion] = intervalos[i]; //si es asi, obtenemos una mejor solucion
				}
				i++; //probar siguiente segmento
			}
			
			if(solucion[indiceSolucion].second == Xcubierto) break;
			Xcubierto = solucion[indiceSolucion].second; //ahora el punto maximo cubierto es el lado derecho de nuestra solucion actual
			indiceSolucion++;
		}
		if(Xcubierto < M){ //si no se alcanza a cubrir M es porque no hay segmentos validos
			puts("0");
		}else{
			cout << indiceSolucion << endl;
			for(int i=0 ; i<indiceSolucion ; i++){
				cout << solucion[i].first << " " << solucion[i].second << endl;
			}
		}
		if(numCasos > 0){
			puts("");
		}
	}
	return 0;
}