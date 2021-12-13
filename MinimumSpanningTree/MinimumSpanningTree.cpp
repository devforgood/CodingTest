#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
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



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//쿠르스칼 알고리즘
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> tree;

	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		tree.push_back({ c, {a, b} });
	}

	sort(tree.begin(), tree.end());


	int answer = 0;

	for (auto node : tree)
	{
		if (Find(node.second.first) != Find(node.second.second))
		{
			Union(node.second.first, node.second.second);
			answer += node.first;
		}
	}

	cout << answer;
}

