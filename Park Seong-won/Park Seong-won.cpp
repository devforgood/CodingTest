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
string str[16];
int arr[51];
int arr2[15];
long long dp[1 << 15][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> str[i];
	}
	cin >> k;

	dp[0][0] = 1;

	arr[0] = 1 % k;
	for (int i = 1; i < 51; ++i)
		arr[i] = (arr[i - 1] * 10) % k;

	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		for (int j = 0; j < str[i].length(); ++j)
		{
			a *= 10;
			a += str[i][j] - '0';
			a %= k;
		}
		arr2[i] = a;
	}


	for (int cur = 0; cur < (1 << n); ++cur)
	{
		for (int i = 0; i < n; ++i)
		{
			if ((cur & (1 << i)) == 0)
			{
				int next = cur | (1 << i);
				for (int j = 0; j < k; ++j)
				{
					int nextK = ((j * arr[str[i].length()]) % k + arr2[i]) % k;
					dp[next][nextK] += dp[cur][j];
				}
			}

		}
	}


	long long d = 1;
	long long nu = 0;

	for (int i = 1; i <= n; ++i)
		d *= i;
	nu = dp[(1 << n) - 1][0];

	long long b, s;
	b = max(nu, d);
	s = min(nu, d);

	while (s != 0)
	{
		long long r = b % s;
		b = s;
		s = r;
	}


	cout << nu / b << "/" << d / b;
}

