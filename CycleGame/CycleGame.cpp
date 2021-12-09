#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int arr[500001];

int Find(int a)
{
	if (arr[a] == a)
		return a;
	else
		return arr[a] = Find(arr[a]); // arr[a] 값 세팅 생략시 시간 초과된다.
}

bool Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	if (pa > pb)
		arr[pa] = pb;
	else if (pa < pb)
		arr[pb] = pa;
	else
		return true;

	return false;
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

	int answer = 0;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		if (Union(a, b))
		{
			answer = i + 1;
			break;
		}
	}

	cout << answer;
}

