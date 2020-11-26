#include <iostream>
//Uva 902 Password Search (ACEPTADO)
#include <map>
#include <string>
#include <iterator>
using namespace std;

int main(){

	int size;
	string encode;

	while(cin >> size >> encode){
		map<string,int> stringCounter;
		string token;

		//contar la frecuencia de un sub string de longitud "size"
		for(int i=0 ; i<encode.size()-size+1 ; i++){
			token = encode.substr(i,size);
			stringCounter[token] = stringCounter[token] + 1;
		}

		//hallar el token con mayor cantidad de ocurrencias
		int maxOcurrency = -1;
		for(map<string,int>::iterator it = stringCounter.begin() ; it != stringCounter.end() ; it++){
			if(it->second > maxOcurrency){
				maxOcurrency = it->second;
				token = it->first;
			}
		}
		cout << token << endl;
	}
	return 0;
}