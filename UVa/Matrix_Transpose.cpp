/*
Uva 10895 Matrix Transpose (ACEPTADO)
Nombre: Diego Iturra Huenteo
codigo propio
uva username: diturra2016
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tuple{
	int row;
	int column;
	int element;
};

int rows[10001];
int columns[10001];
int elements[10001];
vector<Tuple> matrix;
vector<vector<Tuple>> matrix_T;

/*comparador para ordenar por fila y luego por columna*/
bool comparator(const Tuple& t1 , const Tuple& t2){
	return t1.row < t2.row || t1.column < t2.column;
}

void swap(int& row , int& column){
	int temp = row;
	row = column;
	column = temp;
}

int main(){
	int N,M,nonZeros;
	while(cin >> N >> M){

		//para las N filas en la matriz
		for(int i=1 ; i<=N ; i++){
			cin >> nonZeros; //se lee la cantidad de elementos no nulos
			Tuple tuple;
			//ahora se lee la coordenada de la columna en la matriz
			for(int j=1 ; j<=nonZeros ; j++){
				cin >> columns[j];
			}
			//ahora se leen los elementos no nulos
			for(int j=1 ; j<=nonZeros ; j++){
				cin >> elements[j];
			}

			/*Una vez leido la coordenada de la columna y el elemento asociado a cada columna,
			guardar en el vector matrix la tupla (fila,columna,elemento)*/
			for(int j=1 ; j<=nonZeros ; j++){
				tuple.row = i; //fila actual que estamos leyendo
				tuple.column = columns[j]; //columna que guardamos en el vector de columnas
				tuple.element = elements[j]; //elemento que guardamos en el vector de elementos
				matrix.push_back(tuple);
			}
		}

		//trasponer fila y columna
		for(int i=0 ; i<matrix.size() ; i++){
			swap(matrix[i].row,matrix[i].column);
		}
		sort(matrix.begin(),matrix.end(),comparator);

		matrix_T.assign(M+1,vector<Tuple>());

		//generar la matriz traspuesta
		for(int i=0 ; i<matrix.size() ; i++){
			//en la fila correspondiente guardamos la tupla 
			matrix_T[matrix[i].row].push_back(matrix[i]);
		}

		cout << M << " " << N << endl;
		for(int i=1 ; i<matrix_T.size() ; i++){
			if(!matrix_T[i].size()){
				cout << 0;	
			}else{
				cout << matrix_T[i].size() << " "; //imprime los elementos no nulos
			}
			//imprime la fila en lacual estan los elementos no nulos
			for(int j=0 ; j<matrix_T[i].size() ; j++){
				if(j == matrix_T[i].size()-1){
					cout << matrix_T[i][j].column;
				}else{
					cout << matrix_T[i][j].column << " ";	
				}
			}
			cout << endl;
			for(int j=0 ; j<matrix_T[i].size() ; j++){
				if(j == matrix_T[i].size()-1){
					cout << matrix_T[i][j].element;
				}else{
					cout << matrix_T[i][j].element << " ";	
				}
			}
			cout << endl;
		}
		matrix_T.clear();
		matrix.clear();		
	}
	return 0;
}