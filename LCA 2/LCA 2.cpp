#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <memory.h>

using namespace std;

const int MAX = 18; // 2^17

vector<int> tree[100001];
int n;
int parent[100001][MAX];
int depth[100001];

void make_parent(int par, int cur, int dep)
{
	if (tree[cur].size() == 0)
		return;

	parent[cur][0] = par;
	depth[cur] = dep;

	for (auto node : tree[cur])
	{
		if (node != par)
		{
			make_parent(cur, node, dep + 1);
		}
	}
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	make_parent(0, 1, 0);

	for (int j = 1; j <= MAX-1; ++j)
	{
		for (int i = 2; i <= n; ++i)
		{
			if (parent[i][j - 1] != 0)
				parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}



	int m;
	cin >> m;
	while (m--)
	{
		cin >> a >> b;

		if (depth[a] != depth[b])
		{
			if (depth[a] < depth[b])
				swap(a, b);
		}

		// 높이 맞추기
		int diff = depth[a] - depth[b];
		for (int i = 0; diff > 0; ++i)
		{
			if (diff % 2 == 1)
				a = parent[a][i];
			diff = diff >> 1;
		}

		if (a != b)
		{
			for (int i = MAX-1; i >= 0; --i)
			{
				if (parent[a][i] != 0 && parent[a][i] != parent[b][i])
				{
					a = parent[a][i];
					b = parent[b][i];
				}
			}
			a = parent[a][0];
		}

		cout << a << "\n";
	}
}