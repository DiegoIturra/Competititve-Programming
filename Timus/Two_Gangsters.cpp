//Timus 1409. Two Gangsters (ACEPTADO)
#include <iostream>
using namespace std;

int main(){
	int Harry ,Larry;
	cin >> Harry >> Larry;
	int total = Harry + Larry;
	/*el total de latas menos 1 ya que ambos le dieron a la misma  , menos
	las latas a las que le dispararon cada uno */
	cout << total - 1 - Harry << " " << total - 1 - Larry << endl;
	return 0;
}