#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

const int MAX = 1000001;
vector<int> tree[MAX];
int dp[MAX][2];


// 서로 인접하지 않는 정점들의 가중치의 최소값을 찾는 문제
void dfs(int currentNode, int parent)
{
	// 얼리아답터 가중치 초기화 
	dp[currentNode][0] = 1;

	for (auto Node : tree[currentNode])
	{
		if (Node != parent)
		{
			dfs(Node, currentNode);

			// 부모 노드가 얼리아답터일 경우 자식노드가 얼리 아답터일 경우와 아닐 경우중 더 작은 값을 고르다.
			dp[currentNode][0] += min(dp[Node][0], dp[Node][1]); 
			// 부모 노드가 얼리아답터가 아닌 경우 자식노드는 전부 얼리아답터 이어야 한다
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
	 

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(1, 0);

	cout << min(dp[1][0], dp[1][1]) << "\n";



}

