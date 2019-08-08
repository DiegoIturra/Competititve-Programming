//UVa 11799  Horror Dash (ACEPTADO)
#include <iostream>
using namespace std;

int main(){
	int testCases;
	cin >> testCases;
	int numStudents;
	int firstSpeed , numCase = 0;
	while(testCases--){
		numCase++;
		cin >> numStudents >> firstSpeed;
		int max = firstSpeed , speed;
		for(int i=0 ; i<numStudents-1 ; i++){
			cin >> speed;
			if(speed > max) max = speed;
			firstSpeed = max;
		}
		cout << "Case " << numCase << ": "<< max <<endl;
	}
	return 0;
}