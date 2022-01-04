#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout.precision(9);

	int x, y, d, t;
	cin >> x >> y >> d >> t;

	double dist = sqrt(x * x + y * y);


	double answer = dist;

	int jump_count = dist / d;
	dist -= jump_count * d;

	if (jump_count == 0)
	{
		// 점프후 더 멀리간 거리 되돌아오기
		answer = min(answer, (double)t + ((double)d - dist));

		// 점프후 다시 점프로 되돌아오기
		answer = min(answer, (double)t * 2.0);
	}
	else
	{
		// 점프 가능 횟수 만큼 점프 후 남은 거리 걸어가기
		answer = min(answer, (double)jump_count * t + dist);

		// 점프 가능 횟수 만큼 점프 후 점프로 뒤돌아오기
		answer = min(answer, (double)(jump_count + 1) * t);
	}

	cout << answer;
}

