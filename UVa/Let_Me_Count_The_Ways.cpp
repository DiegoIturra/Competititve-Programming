/*
Uva 10496 - Collecting Beepers (ACEPTADO)
codigo Propio
uva username: diturra2016
*/
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int UL;

//conjunto de monedas
vector<int> monedas = {1,5,10,25,50};

UL cambio(int& monto){
    vector<UL> dp(monto+1,0);
    dp[0] = 1;

    for(int moneda : monedas){
        for(UL i=1 ; i<dp.size() ; i++){
            if(i >= moneda){
                dp[i] += dp[i - moneda]; //en cada posicion se almacena la cantidad de permutaciones para el monto i
            }
        }
    }
    return dp[monto];
}


int main(){
    int monto;
    while(cin >> monto){
        UL cantPermutaciones = cambio(monto);
        if(cantPermutaciones == 1)
          cout << "There is only "<< cantPermutaciones << " way to produce " << monto << " cents change." << endl;
        else
          cout << "There are " << cantPermutaciones << " ways to produce " << monto << " cents change." << endl;
    }
    return 0;
}
