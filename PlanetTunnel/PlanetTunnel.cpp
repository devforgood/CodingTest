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
int parent[100001];
vector<tuple<int, int, int>> pos;

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

int dist(int ax, int ay, int az, int bx, int by, int bz)
{
	return min({ abs(ax - bx), abs(ay - by), abs(az - bz) });
}


bool Visit[100001] = { false, };
vector<pair<int, int>> Node[100001];

void Solution2()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
		parent[i] = i;

	for (int i = 0; i < n; ++i)
	{
		double a, b, c;
		cin >> a >> b >> c;
		pos.push_back({ a, b, c });
	}

	// 프림 알고르즘
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int Dist = dist(get<0>(pos[i]), get<1>(pos[i]), get<2>(pos[i]), get<0>(pos[j]), get<1>(pos[j]), get<2>(pos[j]));

			Node[i].push_back(make_pair(j, Dist));
			Node[j].push_back(make_pair(i, Dist));
		}
	}

	priority_queue<pair<double, int>> PQ;
	for (int i = 0; i < Node[0].size(); i++)
	{
		int Next = Node[0][i].first;
		double Cost = Node[0][i].second;

		PQ.push(make_pair(-Cost, Next));
	}
	Visit[0] = true;

	int answer = 0;

	while (PQ.empty() == 0)
	{
		double Cost = -PQ.top().first;
		int Cur = PQ.top().second;
		PQ.pop();

		if (Visit[Cur] == false)
		{
			Visit[Cur] = true;
			answer = answer + Cost;

			for (int i = 0; i < Node[Cur].size(); i++)
			{
				int Next = Node[Cur][i].first;
				double nCost = Node[Cur][i].second;

				if (Visit[Next] == false) PQ.push(make_pair(-nCost, Next));
			}
		}
	}
	cout << answer << "\n";
}

void Solution()
{
	vector<pair<int, int>> x;
	vector<pair<int, int>> y;
	vector<pair<int, int>> z;


	cin >> n;

	for (int i = 0; i < n; ++i)
		parent[i] = i;

	for (int i = 0; i < n; ++i)
	{
		double a, b, c;
		cin >> a >> b >> c;
		x.push_back({ a, i });
		y.push_back({ b, i });
		z.push_back({ c, i });
	}

	std::sort(x.begin(), x.end());
	std::sort(y.begin(), y.end());
	std::sort(z.begin(), z.end());


	//쿠르스칼 알고리즘

	vector<pair<int, pair<int, int>>> edge;

	for (int i = 0; i < n-1; ++i)
	{
		edge.push_back({ x[i + 1].first - x[i].first, { x[i + 1].second,x[i].second } });
		edge.push_back({ y[i + 1].first - y[i].first, { y[i + 1].second,y[i].second } });
		edge.push_back({ z[i + 1].first - z[i].first, { z[i + 1].second,z[i].second } });
	}

	std::sort(edge.begin(), edge.end());


	int answer = 0;

	for (auto node : edge)
	{
		if (Find(node.second.first) != Find(node.second.second))
		{
			Union(node.second.first, node.second.second);
			answer += node.first;
		}
	}

	cout << answer << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);



	Solution();
}

