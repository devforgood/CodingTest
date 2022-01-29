#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>

using namespace std;

vector<int> tree[10001];
int end1;
int end2;
int n;
int parent_node_count[10001];
int answer;

int dfs(int cur)
{
	int cnt = 0;
	int ret_value = cur;
	for (auto node : tree[cur])
	{
		int ret = dfs(node);
		if (ret == end1 || ret == end2)
		{
			ret_value = ret;
			++cnt;
		}
	}

	if (cur == end1 || cur == end2)
	{
		ret_value = cur;
		++cnt;
	}

	if (cnt >= 2)
	{
		answer = cur;
	}

	return ret_value;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i <= n; ++i)
		{
			tree[i].clear();
			parent_node_count[i] = 0;
		}

		for (int i = 0; i < n - 1; ++i)
		{
			int a, b;
			cin >> a >> b;
			tree[a].push_back(b);
			parent_node_count[b]++;
		}

		cin >> end1 >> end2;


		int root = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (parent_node_count[i] == 0)
			{
				root = i;
				break;
			}
		}

		dfs(root);
		cout << answer << "\n";
	}



}