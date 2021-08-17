
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long value[100000] = { 0, };
long long length[100000] = { 0, };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;



	for (int i = 0; i < n-1; ++i)
	{
		cin >> length[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> value[i];
	}

	long long answer = 0;
	long long min_value = 1000000000;
	for (int i = 0; i < n - 1; ++i)
	{

		if (min_value > value[i])
			min_value = value[i];

		answer += length[i] * min_value;
	}

	cout << answer;

}
