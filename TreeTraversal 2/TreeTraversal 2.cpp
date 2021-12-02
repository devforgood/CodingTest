#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int inOrder[100001];
int postOrder[100001];
int inOrderIndex[100001];

// 분할 정복 사용
void preOrder(int inOrderStart, int inOrderEnd, int postOrderStart, int postOrderEnd)
{
	if (inOrderStart > inOrderEnd || postOrderStart > postOrderEnd)
		return;

	int rootInOrderIndex = inOrderIndex[postOrder[postOrderEnd]];
	int leftSize = rootInOrderIndex - inOrderStart;

	cout << postOrder[postOrderEnd] << " ";

	preOrder(inOrderStart, rootInOrderIndex - 1, postOrderStart, postOrderStart + leftSize-1);
	preOrder(rootInOrderIndex + 1, inOrderEnd, postOrderStart + leftSize, postOrderEnd - 1);

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> inOrder[i];
		inOrderIndex[inOrder[i]] = i;
	}

	for (int i = 1; i <= n; ++i)
		cin >> postOrder[i];

	preOrder(1, n, 1, n);
}