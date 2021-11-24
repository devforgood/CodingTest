#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree[100001];
int answer[100001] = { 0, };
bool visited[100001] = { false, };

void dfs(int cur)
{
	visited[cur] = true;

	for (auto node : tree[cur])
	{
		if (visited[node])
			continue;

		answer[node] = cur;
		dfs(node);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n-1; ++i)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; ++i)
		cout << answer[i] << "\n";

}