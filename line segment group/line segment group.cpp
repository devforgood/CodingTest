#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int parent[3001];

struct line
{
	ll x1;
	ll y1;
	ll x2;
	ll y2;
};

int Find(int a)
{
	if (parent[a] == a)
		return a;
	else
		return parent[a] = Find(parent[a]); // arr[a] 값 세팅 생략시 시간 초과된다.
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	if (pa > pb)
	{
		parent[pa] = pb;

	}
	else if (pa < pb)
	{
		parent[pb] = pa;
	}
}


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

int intersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
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
					return 1;
				else
					return 0;

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
					return 1;
				else
					return 0;
			}

		}
		else
		{
			return 1;
		}
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		parent[i] = i;
	}

	vector<line> lines;
	for (int i = 0; i < n; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		lines.push_back({ a, b, c, d });
	}


	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (intersect(lines[i].x1, lines[i].y1, lines[i].x2, lines[i].y2, lines[j].x1, lines[j].y1, lines[j].x2, lines[j].y2) == 1)
			{
				Union(i, j);
			}
		}
	}

	int group_count = 0;
	int max_count = 0;
	int arr[3001] = { 0, };
	for (int i = 0; i < n; ++i)
	{
		if (parent[i] == i) 
			++group_count;
		arr[Find(i)]++;
		if (arr[Find(i)] > max_count) 
			max_count = arr[Find(i)];
	}

	cout << group_count << "\n" << max_count;

}

