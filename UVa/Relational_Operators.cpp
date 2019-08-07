//UVa 11172 Relational Operator (ACEPTADO)
#include <iostream>
using namespace std;

int main(){
	int testCases;
	cin >> testCases;
	int number1 , number2;
	while(testCases--){
		cin >> number1 >> number2;
		//case1 : n1 > n2
		if(number1 > number2) cout << ">" << endl;
		//case2 : n1 < n2
		else if(number1 < number2) cout << "<" << endl;
		//case3: equals
		else cout << "=" << endl;
	}
	return 0;
}