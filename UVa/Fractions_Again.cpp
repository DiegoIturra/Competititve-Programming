//Uva 10976: Fractions Again?! (ACEPTADO)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//imprime el resultado final
//solo usar cuando se halle el par correspondiente
string getSum(int k,int den1 , int den2){
	int mayor = max(den1,den2);
	int menor = min(den1,den2);
	string combinacion = "1/"+to_string(k)+" = "+"1/"+to_string(mayor)+" + 1/"+to_string(menor);
	return combinacion;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	while(cin >> k){
		vector<string> sumas;
		for(int i=k+1 ; i<=2*k ; i++){
			if((i*k) % (i-k) == 0){
				string s = getSum(k,(i*k)/(i-k),i);
				sumas.push_back(s);
			}
		}
		cout << sumas.size() << endl;
		for(int i=0 ; i<sumas.size() ; i++){
			cout << sumas[i] << endl;
		}
	}
	return 0;
}


