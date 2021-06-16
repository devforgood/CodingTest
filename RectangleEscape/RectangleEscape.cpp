#include <iostream>

using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int dist = x;
	if (dist > w - x)
		dist = w - x;

	if (dist > y)
		dist = y;

	if (dist > h - y)
		dist = h - y;
	

	cout << dist;
}

