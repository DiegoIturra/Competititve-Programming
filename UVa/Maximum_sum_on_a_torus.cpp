/*
Uva 10827: Maximum sum on a torus (ACEPTADO)
CODIGO PROPIO
uva nickname: diturra2016
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<vector<int>> Matriz;

/*Generalizacion de Algoritmo de Kadane's para un vector de dos dimensiones*/
int maxima_suma(Matriz& matriz , int N){
    int maxSub_matriz = INT_MIN;
    int sub_matriz;
    /*Para cada sub Matriz desde (i,j) hasta (k,l)
    siendo (k,l) >= (i,j)*/
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            for(int k=i ; k< i + N ; k++){ //para poder llegar hasta la matriz copiada de forma "adyacente"
                for(int l=j ; l< j + N ; l++){
                    sub_matriz = matriz[k][l]; //tomar como valor el extremo derecho
                    if(i > 0)
                      sub_matriz -= matriz[i-1][l]; //restar valor de la fila anterior
                    if(j > 0)
                      sub_matriz -= matriz[k][j-1]; //restar valor de la columna anterior
                    if(i > 0 && j > 0)
                      sub_matriz += matriz[i-1][j-1]; //sumar valor de la submatriz anterior
                    maxSub_matriz = max(maxSub_matriz,sub_matriz);
                }
            }
        }
    }
    return maxSub_matriz;
}

/*con esta funcion generamos una matriz auxiliar llamada dp la cual almacena la suma de las submatrices
que se generan al ir sumando las submatrices anteriores*/
void generar_suma_matriz(Matriz& matriz , Matriz& dp , int N){
    //copiamos la primera fila de la matriz original
    for(int i=0 ; i<N ; i++){
        dp[0][i] = matriz[0][i];
    }
    //para todos los valores sumar los valores de la fila anterior
    for(int i=1 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            dp[i][j] = matriz[i][j] + dp[i-1][j];
        }
    }
    //luego para todos los valores sumar los de la columna anterior
    for(int i=0 ; i<N ; i++){
        for(int j=1 ; j<N ; j++){
            dp[i][j] += dp[i][j-1];
        }
    }
}

int main(){
    int numCasos,N;
    cin >> numCasos;


    //leer entrada y rellenar matriz
    while(numCasos--){
        cin >> N;
        Matriz matriz,dp;
        int newN = 2*N; //para poder aplicar algoritmo de suma de submatrices en una matriz cuadrada
        matriz.resize(newN,vector<int>(newN)); //redimensionar a 2*N x 2*N
        dp.resize(newN,vector<int>(newN)); //redimensionar dp a 2*N x 2*N
        int numero;
        for(int i=0 ; i<N ; i++){
            for(int j=0 ; j<N ; j++){
                cin >> numero;
                //asignar el mismo valor a las 4 matrices iguales
                matriz[i][j] = numero;
                matriz[i][j+N] = numero;
                matriz[i+N][j] = numero;
                matriz[i+N][j+N] = numero;
            }
        }

        generar_suma_matriz(matriz,dp,newN);
        cout << maxima_suma(dp,N) << endl;
    }

    return 0;
}
