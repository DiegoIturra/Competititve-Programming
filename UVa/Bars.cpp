//Uva 12455 : Bars (ACEPTADO)
/*
Nombre: Diego Iturra
usuario UVA: diturra2016 - 1028885
Codigo PROPIO
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int testCases,length_bar,num_bars,bar;
	vector<int> bars;
	cin >> testCases;


	while(testCases--){
		cin >> length_bar;
		cin >> num_bars;
		int n = num_bars;
		while(num_bars--){
			cin >> bar;
			bars.push_back(bar);
		}

		int total_subsets = (1 << n); //2^n
		bool suma_encontrada = false;
		//iterar sobre todos los subconjuntos posibles
		for(int subSet=0 ; subSet<total_subsets ; subSet++){
			int sum = 0;
			for(int j=0 ; j<n ; j++){

				//si el elemento esta en el conjunto entonces lo sumamos
				if(subSet & (1 << j) != 0){
					sum += bars[j];
				}

				//si logramos la suma deseada
				if(sum == length_bar){
					suma_encontrada = true;
					break;
				}
			}
		}
		if(suma_encontrada)
			puts("YES");
		else
			puts("NO");
		bars.clear();
	}
	return 0;
}

