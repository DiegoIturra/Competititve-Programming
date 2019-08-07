//UVa 12577 Hajj-e-Akbar(ACEPTADO)
#include <iostream>
using namespace std;

int main(){
	string name;
	int numCase = 0;
	while(true){
		cin >> name;
		numCase++;
		if(name == "*") break;
		if(name == "Hajj") cout << "Case " << numCase << ": " << "Hajj-e-Akbar" << endl; 
		else if(name == "Umrah") cout << "Case " << numCase << ": " << "Hajj-e-Asghar" << endl; 
	}
	return 0;
}

