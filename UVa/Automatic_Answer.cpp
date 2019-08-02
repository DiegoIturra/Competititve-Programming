//UVa 11547 Automatic Answer (ACEPTADO)
#include <iostream>
#include <string>
using namespace std;

int main(void){
	int numCases;
	int number;
	cin >> numCases;
	for(int i=0 ; i<numCases ; i++){
		cin >> number;
		//para cada numero operamos
		int res = number*567;
		res = res/9;
		res += 7492;
		res *= 235;
		res = res / 47;
		res = res - 498;
		string resST = to_string(res);
		int len = resST.length();
		cout << resST[len-2] << endl;
	}
	return 0;
}
