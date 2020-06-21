//Uva 108 Maximum Sum (ACEPTADO)
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

typedef vector<vector<int>> Matriz;

int maxima_suma(Matriz& matriz , int& N){
    int maxSub_matriz = INT_MIN;
    int sub_matriz;
    /*Para cada sub Matriz desde (i,j) hasta (k,l)
    siendo (k,l) >= (i,j)*/
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            for(int k=i ; k<N ; k++){
                for(int l=j ; l<N ; l++){
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


void generar_suma_matriz(Matriz& matriz , Matriz& dp , int& N){
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
    //luego para todos los valores sumar los de la fila anterior
    for(int i=0 ; i<N ; i++){
        for(int j=1 ; j<N ; j++){
            dp[i][j] += dp[i][j-1];
        }
    }
}



int main(){
    int N;
    Matriz matriz, dp;

    cin >> N;
    matriz.resize(N,vector<int>(N));
    dp.resize(N,vector<int>(N));

    //leer y rellenar matriz
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            cin >> matriz[i][j];
        }
    }

    //generamos una matriz con la suma de los valores de las filas y columnas anteriores
    generar_suma_matriz(matriz,dp,N);
    //ahora calculamos el valor maximo a partir de la matriz de sumas
    cout << maxima_suma(dp,N) << endl;

    return 0;
}
