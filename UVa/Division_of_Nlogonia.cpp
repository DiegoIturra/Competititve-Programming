//UVa 11498 Division of Nlogonia (ACEPTADO)
#include <iostream>
using namespace std;

int main(void){
	int queries;
	while(cin >> queries){ //obtener el numero de consultas
		if(queries==0) break;
		int xCenter , yCenter;
		cin >> xCenter >> yCenter; //obtener el punto de origen
		for(int i=0 ; i<queries ;i++){
			int x , y;
			cin >> x >> y;
			//ver en que lado esta
			if(x < xCenter && y > yCenter) 		cout << "NO" << endl;
			else if(x > xCenter && y > yCenter) cout << "NE" << endl;
			else if(x < xCenter && y < yCenter) cout << "SO" << endl;
			else if(x > xCenter && y < yCenter) cout << "SE" << endl;
			else cout << "divisa" << endl;	
		}
	}
	return 0;
}
