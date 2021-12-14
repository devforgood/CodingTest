#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

int n;
int parent[10001];

int Find(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	parent[b] = a;
}

double dist(double ax, double ay, double bx, double by)
{
	return sqrt((ax - bx)*(ax - bx) + (ay - by)*(ay - by));
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//쿠르스칼 알고리즘
	cin >> n;
	vector<pair<double, double>> pos;
	vector<pair<double, pair<int, int>>> edge;

	for (int i = 0; i < n; ++i)
		parent[i] = i;

	for (int i = 0; i < n; ++i)
	{
		double a, b;
		cin >> a >> b;
		pos.push_back({ a, b });
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			edge.push_back({ dist(pos[i].first, pos[i].second, pos[j].first, pos[j].second), {i, j} });
		}
	}

	sort(edge.begin(), edge.end());


	double answer = 0.0;

	for (auto node : edge)
	{
		if (Find(node.second.first) != Find(node.second.second))
		{
			Union(node.second.first, node.second.second);
			answer += node.first;
		}
	}

	cout << answer;
}

