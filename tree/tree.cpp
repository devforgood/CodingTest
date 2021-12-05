#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree[501];
bool visited[501];
bool visited2[501];
int n, m;


int countVertex(int cur)
{
	int cnt = 1;
	visited[cur] = true;

	for (auto node : tree[cur])
	{
		if (visited[node] == true)
			continue;

		cnt += countVertex(node);
	}
	return cnt;
}

int countEdge(int cur)
{
	int cnt = tree[cur].size();
	visited2[cur] = true;

	for (auto node : tree[cur])
	{
		if (visited2[node] == true)
			continue;
		cnt += countEdge(node);
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int c = 1;
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		int a, b;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}

		int answer = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (visited[i] == false)
			{
				if (countVertex(i) - 1 == countEdge(i) / 2)
					++answer;
			}
		}

		memset(visited, 0, sizeof(visited));
		memset(visited2, 0, sizeof(visited2));
		for (int i = 1; i <= n; ++i)
			tree[i].clear();

		cout << "Case "<< c++ << ": ";
		if (answer == 0)
			cout << "No trees.\n";
		else if (answer == 1)
			cout << "There is one tree.\n";
		else
			cout << "A forest of " << answer << " trees.\n";
	}
}

