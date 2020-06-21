/*
Uva 10684 The jackpot (ACEPTADO)
Codigo propio
uva username: diturra2016
*/
#include <iostream>
#include <vector>
using namespace std;

//Algoritmo de Kadane's , O(n)
int max_sum(vector<int>& array , int size){
    int suma = 0;
    int respuesta = 0;
    for(int i=0 ; i<size ; i++){
        if(suma + array[i] > 0) //si se obtienen valores positivos continuamos sumando
          suma += array[i];
        else //si no , entonces seteamos la suma a cero
          suma = 0;
        respuesta = max(suma,respuesta); // y siempre nos quedamos con el maximo valor hasta el momento
    }
    return respuesta;
}


int main(){
    int tam,apuesta;

    while(true){
        cin >> tam;
        if(tam == 0) break;
        vector<int> apuestas;
        int apuesta;
        for(int i=0 ; i<tam ; i++){ //guardar valores de las apuestas
            cin >> apuesta;
            apuestas.push_back(apuesta);
        }

        int maximo = max_sum(apuestas,tam); //calcular la maxima suma
        if(maximo > 0)
          cout << "The maximum winning streak is " << maximo << "." << endl;
        else
          cout << "Losing streak." << endl;
    }

    return 0;
}
