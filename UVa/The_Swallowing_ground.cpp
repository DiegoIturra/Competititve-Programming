//Uva 10963 :The Swallowing Ground (ACEPTADO)
#include <iostream>
using namespace std;

int main(){
	int testCases,numColumns,y1,y2,Case=0;
	cin >> testCases;
	int test = testCases;

	while(testCases--){
		Case++;
		cin >> numColumns;
		int result,first;
		int total = 0;
		bool flag = false;
		for(int i=0 ; i<numColumns ; i++){
			cin >> y1 >> y2;
			
			if(i == 0){
				flag = true;
				first = y1 - y2;
			}
			if(flag == true){
				result = y1 - y2;
				if(result == first){
					total++;
				}
			}			
		}
		if(Case < test){
			if(total == numColumns)
				puts("yes");
			else
				puts("no");
			printf("\n");
		}else{
			if(total == numColumns)
				puts("yes");
			else
				puts("no");
		}
	}
	return 0;
}