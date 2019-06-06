//uva 11462- Age Sort (ACEPTADO)
#include <iostream>
#include <vector>
#include <algorithm>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main(){
	int cant;
	int num;	
	optimizar_io; //permite que "cout" y "cin" no sean tan lentos

	while(cin >> cant){
		if(cant == 0) break;
		vector<int> vec;
		for(int i = 0 ; i<cant ; i++){
			int num;
			cin >> num;
			vec.push_back(num);
		}
		sort(vec.begin(),vec.end());
		int tam = vec.size();
		for(int i=0 ; i<tam ; i++){
			cout << vec[i];
			if(i<(tam-1)) cout << " ";
		}
		cout << "\n";
	}
	return 0;
}