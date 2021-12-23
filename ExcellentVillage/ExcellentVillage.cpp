﻿#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

const int MAX = 100001;
vector<int> tree[MAX];
vector<int> path;
int dp[MAX][2];
int w[MAX]; // 가중치

// 서로 인접하지 않는 정점들의 가중치의 최댓값을 찾는 문제
void dfs(int currentNode, int parent)
{
	dp[currentNode][0] = 0;
	dp[currentNode][1] = w[currentNode];

	for (auto Node : tree[currentNode])
	{
		if (Node != parent)
		{
			dfs(Node, currentNode);

			dp[currentNode][0] += max(dp[Node][0], dp[Node][1]);
			dp[currentNode][1] += dp[Node][0];
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> w[i];

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(1, 0);

	cout << max(dp[1][0], dp[1][1]) << "\n";

}

