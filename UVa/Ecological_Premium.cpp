//Uva 10300 Ecological Premium (ACEPTADO)
#include <iostream>
using namespace std;

int main(){
	int testCases;
	double numFarmers , numAnimals , sizeFarmyiard , friendliness;
	cin >> testCases;

	double average,farmerPremium,finalPremium;
	while(testCases--){
		cin >> numFarmers;
		farmerPremium = 0.0;
		finalPremium = 0.0;
		for(int i=0 ; i<numFarmers ; i++){
			cin >> sizeFarmyiard >> numAnimals >> friendliness;
			average = sizeFarmyiard / numAnimals;
			average *= friendliness;
			farmerPremium = average * numAnimals;
			finalPremium += farmerPremium;
		}
		cout << int(finalPremium) << endl;
	}
	return 0;
}