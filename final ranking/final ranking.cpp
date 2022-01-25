#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>

using namespace std;

const int MAX = 501;

int answer[MAX];
int inDegree[MAX];
bool arr[MAX][MAX];
int ranking[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;

		for (int i = 1; i <= n; ++i)
		{
			cin >> ranking[i];
			answer[i] = -1;
			inDegree[i] = 0;
			for (int j = 1; j <= n; ++j)
				arr[i][j] = false;
		}

		// 랭킹 리스트는 각 1등 ~ n등까지
		// 2등 ~ n등까지 ... 모두 설정
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				arr[ranking[i]][ranking[j]] = true;
				inDegree[ranking[j]]++;
			}
		}

		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			if (arr[a][b])
			{
				arr[a][b] = false;
				arr[b][a] = true;
				inDegree[b]--;
				inDegree[a]++;
			}
			else
			{
				arr[b][a] = false;
				arr[a][b] = true;
				inDegree[a]--;
				inDegree[b]++;
			}
		}



		queue<int> q;
		for (int i = 1; i <= n; ++i)
		{
			if (inDegree[i] == 0)
				q.push(i);
		}


		bool valid = true;
		for (int i = 1; i <= n; ++i)
		{
			if (q.empty())
			{
				cout << "IMPOSSIBLE" << "\n";
				valid = false;
				break;
			}

			if (q.size() > 1)
			{
				cout << "?" << "\n";
				valid = false;
				break;
			}

			int a = q.front();
			q.pop();
			answer[i] = a;
			inDegree[a]--;
			for (int j=1;j<=n;++j)
			{
				if (arr[a][j])
					inDegree[j]--;

				if (inDegree[j] == 0)
					q.push(j);
			}
		}

		if (valid)
		{
			for (int i = 1; i <= n; ++i)
				cout << answer[i] << " ";
			cout << "\n";
		}
	}
}