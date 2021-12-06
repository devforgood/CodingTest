#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int arr[1000001];

int find_parent(int a)
{
	if (arr[a] == a)
		return a;
	else
		return arr[a] = find_parent(arr[a]); // arr[a] 값 세팅 생략시 시간 초과된다.
}

void set_union(int a, int b)
{
	int pa = find_parent(a);
	int pb = find_parent(b);

	if (pa > pb)
		arr[pa] = pb;
	else if(pa < pb)
		arr[pb] = pa;

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; ++i)
		arr[i] = i;

	for (int i = 0; i < m; ++i)
	{
		int o, a, b;
		cin >> o >> a >> b;
		if (o == 0)
			set_union( a, b );
		else
		{
			if (find_parent(a) == find_parent(b))
				cout << "YES\n";
			else
				cout << "NO\n";

		}
	}

}

