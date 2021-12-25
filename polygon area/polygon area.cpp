#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

double ccw(double x1, double x2, double x3, double y1, double y2, double y3) {
	return ((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1)) ;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout.precision(1);


	int n;
	cin >> n;
	vector<pair<double, double>> a;
	for (int i = 0; i < n; ++i)
	{
		double x, y;
		cin >> x >> y;
		a.push_back({ x, y });
	}

	double answer = 0;
	for (int i = 1; i < n; ++i)
	{
		answer += ccw(a[0].first, a[i - 1].first, a[i].first, a[0].second, a[i - 1].second, a[i].second);
	}


	cout << abs(answer)/2;
}
