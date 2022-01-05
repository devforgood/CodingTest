#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int n, k;
int answer = 0;
string arr[15];
int dp[15][1 << 15];

void func(int x, int visited, string num)
{
	if (visited == (1 << n) - 1)
	{
		if (atoi(num.c_str()) % k == 0)
			++answer;

		return;
	}

	
	for (int i = 0; i < n; ++i)
	{
		if ((visited & (1 << i)) == (1 << i))
			continue;

		func(i, visited | (1 << i), num + arr[i]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cin >> k;

	func(0, 0, "");





}

