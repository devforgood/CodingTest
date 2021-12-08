#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

map<string, string> arr;
map<string, int> cnt;

string Find(string a)
{
	if (arr[a] == a)
		return a;
	else
		return arr[a] = Find(arr[a]); // arr[a] 값 세팅 생략시 시간 초과된다.
}

int Union(string a, string b)
{
	string pa = Find(a);
	string pb = Find(b);

	int ret = cnt[pa];
	if (pa > pb)
	{
		arr[pa] = pb;
		ret  = cnt[pb] = cnt[pb] + cnt[pa];
		
	}
	else if (pa < pb)
	{
		arr[pb] = pa;
		ret = cnt[pa] = cnt[pb] + cnt[pa];
	}
	return ret;
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
		int f;
		cin >> f;
		for (int i = 0; i < f; ++i)
		{
			string a, b;
			cin >> a >> b;
			if (arr.find(a) == arr.end())
			{
				arr[a] = a;
				cnt[a] = 1;
			}
			if (arr.find(b) == arr.end())
			{
				arr[b] = b;
				cnt[b] = 1;
			}
			int answer = Union(a, b);

			cout << answer << "\n";

		}
		arr.clear();
		cnt.clear();
	}


}

