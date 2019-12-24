//Uva 11078 Open Credit System (ACEPTADO)
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int testCases,student,numStudents;
	cin >> testCases;
	while(testCases--){
		cin >> numStudents;
		vector<int> students;
		while(numStudents--){
			cin >> student;
			students.push_back(student);
		}

		//comparar
		int maxValue = -10000000,maxDifference = -100000000;
		for(int i=0 ; i<students.size()-1 ; i++){
			if(students[i] > maxValue)
				maxValue = students[i];
			if(maxValue - students[i+1] > maxDifference)
				maxDifference = maxValue - students[i+1];
		}
		cout << maxDifference << endl;
	}
	return 0;
}