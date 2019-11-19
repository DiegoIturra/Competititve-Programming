//Uva 12049: Just Prune The List (ACEPTADO)
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
	int testCases;
	cin >> testCases;
	int lenList1 , lenList2;
	int element;
	multiset<int> mset1 , mset2, intersection;
	while(testCases--){
		cin >> lenList1 >> lenList2;

		//llenar set 1
		for(int i=0 ; i<lenList1 ; i++){
			cin >> element;
			mset1.insert(element);
		}

		//llenar set 2
		for(int i=0 ; i<lenList2 ; i++){
			cin >> element;
			mset2.insert(element);
		}

		//crear interseccion de ambos conjuntos
		set_intersection(mset1.begin(),mset1.end() , mset2.begin(),mset2.end() , inserter(intersection , intersection.begin()));
		int size1 = mset1.size();
		int size2 = mset2.size();
		int interSize = intersection.size();
		int answer;

		if(size1 == interSize && size2 == interSize && size1 == size2){
			answer = 0;
		}else if(interSize == 0){
			answer = size1 + size2;
		}else{
			answer = abs(interSize - size1) + abs(interSize -size2);
		}

		cout << answer << endl;

		mset1.clear();
		mset2.clear();
		intersection.clear();
	}
	return 0;
}
