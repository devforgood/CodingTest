#include <iostream>
#include <vector>
using namespace std;

const int MAX = 8 + 1;

int N, M;
int arr[MAX];
bool visited[MAX];

void func(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	vector<int> v;
	for (int i = 1; i <= N; i++)
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			func(cnt + 1);
			v.push_back(i);
			//visited[i] = false;
		}

	// permutation과 combination의 차이는 스택 리턴 이후 바로 초기화 되는 것과 루프로 돌고 한번에 초기화하는 것에 차이이다.
	for(int i=0;i< v.size();++i)
		visited[v[i]] = false;
}

void func2(int num, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = num; i <= N; i++)
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			func2(i+1, cnt + 1);
			visited[i] = false;
		}
}

int main(void)
{
	cin >> N >> M;

	func2(1, 0);
	return 0;
}
