#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

typedef long long ll;


using namespace std;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	ll a = x1 * y2 + x2 * y3 + x3 * y1;
	ll b = y1 * x2 + y2 * x3 + y3 * x1;
	if (a - b < 0)
		return 1;
	else if (a - b > 0)
		return -1;

	return 0;
}

void intersection(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
	double x = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
	double y = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);
	double p = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

	if (p == 0)
	{
		pair<int, int> a, b, c, d;
		a = { x1, y1 };
		b = { x2, y2 };
		c = { x3, y3 };
		d = { x4, y4 };

		if (b == c && a <= c)
			cout << b.first << " " << b.second;
		else if (a == d && c <= a)
			cout << a.first << " " << a.second;


	}
	else
	{
		cout << x / p << " " << y / p;
	}

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout.precision(9);

	ll x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	ll abc = ccw(x1, y1, x2, y2, x3, y3);
	ll abd = ccw(x1, y1, x2, y2, x4, y4);
	ll cda = ccw(x3, y3, x4, y4, x1, y1);
	ll cdb = ccw(x3, y3, x4, y4, x2, y2);

	if (abc * abd <= 0 && cda * cdb <= 0)
	{
		// 두 선분이 평행인 경우
		if (abc * abd == 0 && cda * cdb == 0)
		{
			if (x1 == x3)
			{
				if (y1 > y2)
				{
					swap(x1, x2);
					swap(y1, y2);
				}

				if (y3 > y4)
				{
					swap(x3, x4);
					swap(y3, y4);
				}

				if (y1 <= y4 && y3 <= y2)
				{
					cout << 1 << '\n';
					intersection(x1, y1, x2, y2, x3, y3, x4, y4);
				}
				else
					cout << 0;

			}
			else
			{
				if (x1 > x2)
				{
					swap(x1, x2);
					swap(y1, y2);
				}

				if (x3 > x4)
				{
					swap(x3, x4);
					swap(y3, y4);
				}

				if (x1 <= x4 && x3 <= x2)
				{
					cout << 1 << '\n';
					intersection(x1, y1, x2, y2, x3, y3, x4, y4);
				}
				else
					cout << 0;
			}

		}
		else
		{
			cout << 1 << '\n';
			intersection(x1, y1, x2, y2, x3, y3, x4, y4);
		}
	}
	else
		cout << 0;


}
