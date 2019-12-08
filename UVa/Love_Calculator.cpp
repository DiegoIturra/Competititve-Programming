//Uva 10424 - Love Calculator (ACEPTADO)
#include <iostream>
#include <map>
#include <iterator>
#include <cctype>
#include <vector>
using namespace std;

int descomponer(int numero){
	int suma = 0;
	int resto;
	while(numero > 0){
		resto = numero % 10;
		numero = numero / 10;
		suma += resto;
	}
	if(suma< 10)
		return suma;
	return descomponer(suma);
}

int parsear(const string& nombre, map<char,int>& abecedario){
	int contador = 0;
	for(int i=0 ; i<nombre.length() ; i++){
		if(nombre[i] >= 'a' || nombre[i] <= 'z'){
			contador += abecedario[nombre[i]];
		}
	}
	return contador;
}


void aMinuscula(string &palabra1 , string& palabra2){
	for(int i=0 ; i<palabra1.length() ; i++){
		if(palabra1[i] >= 'A' || palabra1[i] <= 'Z')
			palabra1[i] = tolower(palabra1[i]);
	}
	for(int i=0 ; i<palabra2.length() ; i++){
		if(palabra2[i] >= 'A' || palabra2[i] <= 'Z')
			palabra2[i] = tolower(palabra2[i]);
	}
}

int main(){
	map<char,int> abecedario;
	int contador = 1;

	//mapear abecedario
	for(char i='a' ; i<='z' ; i++){
		abecedario[i] = contador;
		contador++;
	}

	//leer la entrada
	vector<string> nombres;
	string nombre;
	while(getline(cin , nombre)){
		nombres.push_back(nombre);
	}	

	//recorrer el vector con los nombres;
	string persona1 , persona2;
	int suma1,suma2,menor,mayor;
	int num1 , num2;
	for(int i=0 ; i<=nombres.size()-1 ; i += 2){
		persona1 = nombres[i];
		persona2 = nombres[i+1];
		aMinuscula(persona1,persona2);
		suma1 = parsear(persona1,abecedario);
		suma2 = parsear(persona2,abecedario);
		
		//descomponer hasta lograr un digito
		num1 = descomponer(suma1);
		num2 = descomponer(suma2);

		//hallar el menor
		if(num1 > num2){
			menor = num2;
			mayor = num1;
		}
		else{
			menor = num1;
			mayor = num2;
		}

		//hallar la razon entre los dos resultados
		double razon = double(menor) / double(mayor);
		razon = razon * 100.00;
		printf("%.2f",razon);
		puts(" %");
	}
	return 0;
}