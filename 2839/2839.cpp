#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 설탕 배달
int main()
{
	int n;
	cin >> n;

	int cnt = -1;
	int multiple5 = n / 5;

	while (multiple5 >= 0)
	{
		int a = n - (5 * multiple5);
		if (a == 0)
		{
			cnt = multiple5;
			break;
		}

		if (a % 3 == 0)
		{
			cnt = multiple5 + a / 3;
			break;
		}

		--multiple5;
	}

	cout << cnt;

}