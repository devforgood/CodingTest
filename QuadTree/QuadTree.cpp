//#include <iostream>
//#include <stack>
//#include <string>
//#include <algorithm>
//#include <memory.h>
//#include <limits.h>
//
//using namespace std;
//
//int n = 0;
//char arr[128][128] = { 0, };
//
//string func(int start_x, int start_y, int size)
//{
//	if (size == 0)
//		return string() + arr[start_x][start_y];
//
//	string values[4];
//	values[0] = func(start_x, start_y, size / 2);
//	values[1] = func(start_x, start_y + size, size / 2);
//	values[2] = func(start_x + size, start_y, size / 2);
//	values[3] = func(start_x + size, start_y + size, size / 2);
//
//	string str;
//	if (values[0] == values[1] && values[0] == values[2] && values[0] == values[3])
//	{
//		return values[0];
//	}
//	else
//	{
//		str += "(";
//		for (int i = 0; i < 4; ++i)
//		{
//			str += values[i];
//		}
//		str += ")";
//	}
//
//	return str;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> arr[i];
//	}
//
//
//	auto answer = func(0, 0, n / 2);
//
//	cout << answer << "\n";
//
//
//
//}

#define _CRT_SECURE_NO_WARNINGS


#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int a[64][64];
int n;

void solve(int size, int x, int y) {
	if (size == 1) {
		printf("%d", a[y][x]);
		return;
	}

	bool same = true;
	for (int i = y; i < y + size; i++) {
		if (!same) break;
		for (int j = x; j < x + size; j++) {
			if (a[y][x] != a[i][j]) {
				same = false;
				break;
			}
		}
	}

	if (same) {
		printf("%d", a[y][x]);
		return;
	}
	int ns = size / 2;

	printf("(");
	solve(ns, x, y);
	solve(ns, x + ns, y);
	solve(ns, x, y + ns);
	solve(ns, x + ns, y + ns);
	printf(")");
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	solve(n, 0, 0);
	printf("\n");
	return 0;
}