	#include <iostream>

	using namespace std;

	int main() {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == b && b == c)
			cout << 10000 + a * 1000;
		else if (a == b || a == c || b==c) {
			if (a == c)
				cout << 1000 + c * 100;
			else
				cout << 1000 + b * 100;
		}
		
		else {
			if (a > b) {
				if (a > c)
					cout << a * 100;
				else
					cout << c * 100;
			}
			else {
				if (b > c)
					cout << b * 100;
				else
					cout << c * 100;
			}
		}
			
		return 0;
	}

//     #include <cstdio>

// int main()
// {
//     int x, y, z;
//     scanf("%d %d %d", &x, &y, &z);
    
//     if ((x == y) && (x == z)) printf("%d", 10000 + (x * 1000));
//     else if ((x == y) || (x == z)) printf("%d", 1000 + (x * 100));
//     else if (y == z) printf("%d", 1000 + (y * 100));
//     else
//     {
//         int max = ((x > y) ?
//                    ((x > z) ? x : z) :
//                    ((y > z) ? y : z));
//         printf("%d", max * 100);
//     }
// }