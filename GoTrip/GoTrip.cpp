#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int arr[1000001];

int Find(int a)
{
	if (arr[a] == a)
		return a;
	else
		return arr[a] = Find(arr[a]); // arr[a] 값 세팅 생략시 시간 초과된다.
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	if (pa > pb)
		arr[pa] = pb;
	else if (pa < pb)
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

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int a;
			cin >> a;
			if (a == 1)
			{
				Union(i, j);
			}
		}
	}

	int diff = false;
	int last_value = -1;
	for (int i = 0; i < m; ++i)
	{
		int a;
		cin >> a;
		int v = Find(a);
		if (last_value < 0)
			last_value = v;
		else if (last_value != v)
		{
			diff = true;
		}
	}


	if (diff==false)
		cout << "YES\n";
	else
		cout << "NO\n";


}

