#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int X, Y;
	for (int i = 0; i < n; i++) 
	{

		cin >> X >> Y;
		int distance = Y - X;	// 거리

		int max = sqrt(distance);	// 소수점 버림

		if ((double)max == sqrt(distance)) {
			cout << max * 2 - 1 << endl;
		}
		else if (distance <= max * max + max) {
			cout << max * 2 << endl;
		}
		else {
			cout << max * 2 + 1 << endl;
		}

	}
}