//UVa 11727 - Cost Cutting (ACEPTADO)
#include <iostream>
using namespace std;

int main(){
	int casos;
	cin >> casos;

	for(int i=0 ; i<casos ; i++){
		int a,b,c;
		cin >> a >> b >> c;
		/* comparamos todos los numeros y nos quedamos con el que esta al
		medio entre el menor valor y el mayor valor*/ 
		cout<<"Case "<<i+1<<": ";
		if(a<b && b<c) cout<<b<<"\n";
		if(a<c && c<b) cout<<c<<"\n";
		if(b<a && a<c) cout<<a<<"\n";
		if(b<c && c<a) cout<<c<<"\n";
		if(c<a && a<b) cout<<a<<"\n";
		if(c<b && b<a) cout<<b<<"\n";
	}
	return 0;
}

