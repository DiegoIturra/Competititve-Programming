//UVa 11764 Jumping Mario
#include <iostream>
using namespace std;

int main(){
	int testCases;
	cin >> testCases;
	int numWalls;
	int firstWall;
	int numCase = 0;
	int lowJump = 0 , highJump = 0;
	while(testCases--){
		numCase++;
		cin >> numWalls >> firstWall;
		int nextWall;
		for(int i=0 ; i<numWalls-1 ; i++){
			cin >> nextWall;
			if(nextWall > firstWall) highJump++;
			else if(nextWall < firstWall) lowJump++;
			firstWall = nextWall;
		}
		cout << "Case " << numCase << ": " << highJump << " " << lowJump << endl;
		highJump = lowJump = 0;
	} 
	return 0;
}