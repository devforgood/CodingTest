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

	return -1;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	ll abc = ccw(x1, y1, x2, y2, x3, y3);
	ll abd = ccw(x1, y1, x2, y2, x4, y4);
	ll cda = ccw(x3, y3, x4, y4, x1, y1);
	ll cdb = ccw(x3, y3, x4, y4, x2, y2);

	if (abc * abd <= 0 && cda * cdb <= 0)
		cout << 1;
	else
		cout << 0;


}
