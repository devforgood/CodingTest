#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int tree[100001][2];

void dfs(int cur)
{
	cout << (char)(cur + 'A');

	if (tree[cur][0] != -1)
		dfs(tree[cur][0]);

	if(tree[cur][1] != -1)
		dfs(tree[cur][1]);
}
void dfs2(int cur)
{

	if (tree[cur][0] != -1)
		dfs2(tree[cur][0]);

	cout << (char)(cur + 'A');

	if (tree[cur][1] != -1)
		dfs2(tree[cur][1]);
}
void dfs3(int cur)
{

	if (tree[cur][0] != -1)
		dfs3(tree[cur][0]);

	if (tree[cur][1] != -1)
		dfs3(tree[cur][1]);

	cout << (char)(cur + 'A');

}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(tree, -1, sizeof(tree));


	int n;
	cin >> n;
	char a, b, c;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b >> c;

		if(b != '.')
			tree[a-'A'][0] = b - 'A';
		if (c != '.')
			tree[a - 'A'][1] = c - 'A';
	}


	dfs(0);
	cout << "\n";

	dfs2(0);
	cout << "\n";

	dfs3(0);
}