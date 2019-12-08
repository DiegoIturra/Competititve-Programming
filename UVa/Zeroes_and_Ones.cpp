//Uva 10324 - Zeros and Ones (ACEPTADO)
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

char sequence[1000009];

int main(){
	int numQueries,	left , right;
	int Case = 0;
	while(scanf("%s %d",sequence, &numQueries) == 2){
		Case++;
		cout << "Case " << Case << ":" << endl;
		while(numQueries--){
			cin >> left >> right;
			int leftSide = min(left,right);
			int rightSide = max(left,right);

			//recorrer la secuencia en los limites dados
			bool valid = true;
			for(int i=leftSide ; i<=rightSide-1 ; i++){
				if(sequence[i] != sequence[i+1]){
					valid = false;
					break;
				}
			}
			if(valid == false)
				puts("No");
			else
				puts("Yes");
		}
	}
	return 0;
}