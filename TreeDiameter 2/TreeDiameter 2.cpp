#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > tree[100001];
bool visited[100001] = { false, };
int answer = 0;
int maxNode = 0;

void dfs(int cur, int cost)
{
	if (answer < cost)
	{
		answer = cost;
		maxNode = cur;
	}

	visited[cur] = true;

	for (auto node : tree[cur])
	{
		if (visited[node.first])
			continue;

		dfs(node.first, cost + node.second);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n-1; ++i)
	{
		cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
	}

	// 임의 정점에서 가장 거기가 먼 노드를 찾고
	// 다시 가장 먼노드를 시작으로 찾으면 트리의 가장 긴 노드간 길이를 찾을 수 있다.
	dfs(1, 0);

	memset(visited, 0, sizeof(visited));
	answer = 0;
	dfs(maxNode, 0);

	cout << answer << "\n";
}