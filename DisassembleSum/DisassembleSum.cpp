#include <iostream>
#include <math.h>
#include <vector>

using namespace std;



int main()
{
	int n;

	cin >> n;

	int answer = 0;
	for (int i = 1; i < n; ++i)
	{
		int num = i;
		int disassem = num;
		int sum = 0;
		while (disassem)
		{
			sum += disassem % 10;
			disassem /= 10;
		}
		if (n == num + sum)
		{
			answer = num;
			break;
		}
	}

	cout << answer;
}

