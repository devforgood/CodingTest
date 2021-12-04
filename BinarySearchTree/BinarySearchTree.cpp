#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int tree[1000002][2];


void insert(int root, int a)
{
	if ( root > a)
	{
		if (tree[root][0] == 0)
			tree[root][0] = a;
		else
			insert(tree[root][0], a);
	}
	else
	{
		if (tree[root][1] == 0)
			tree[root][1] = a;
		else
			insert(tree[root][1], a);
	}
}

void search(int root)
{
	if (tree[root][0] != 0)
		search(tree[root][0]);
	if (tree[root][1] != 0)
		search(tree[root][1]);

	cout << root << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, root;
	cin >> root;
	while (cin >> a) {
		if (a == EOF) break;
		insert(root, a);
	}

	search(root);

}

