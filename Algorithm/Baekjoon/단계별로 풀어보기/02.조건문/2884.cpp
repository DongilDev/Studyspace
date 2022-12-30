#include <iostream>

using namespace std;

int main() {
	int H, M;
	cin >> H >> M;
	
	if (M - 45 >= 0) 
		M -= 45;

	else if(M-45 < 0){
		M = M + 60 - 45;

		if (H - 1 >= 0)
			H -= 1;
		else
			H = 23;
	}

	cout << H << " " << M;
		
	return 0;
}