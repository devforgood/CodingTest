#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

const int MAX = 100001;
vector<int> connect[MAX];
vector<int> tree[MAX];
int dp[MAX];


void makeTree(int currentNode, int parent)
{
	for (auto Node : connect[currentNode])
	{
		if (Node != parent)
		{
			// add Node to currentNode’s child
			// set Node’s parent to currentNode
			tree[currentNode].push_back(Node);
			makeTree(Node, currentNode);
		}
	}
}

void countSubtreeNodes(int currentNode)
{
	if (dp[currentNode] != -1)
		return;

	dp[currentNode] = 1; // 자신도 자신을 루트로 하는 서브트리에 포함되므로 0이 아닌 1에서 시작한다.
	for (auto Node : tree[currentNode])
	{
		countSubtreeNodes(Node);
		dp[currentNode] += dp[Node];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, r, q;
	cin >> n >> r >> q;
	for (int i = 0; i < n-1; ++i)
	{
		int u, v;
		cin >> u >> v;
		connect[u].push_back(v);
		connect[v].push_back(u);
	}

	makeTree(r, -1);

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < q; ++i)
	{
		int a;
		cin >> a;
		countSubtreeNodes(a);
		cout << dp[a] << "\n";
	}
}

