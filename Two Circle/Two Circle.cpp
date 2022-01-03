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
	cout.precision(3);

	// 부체꼴 넓이 - 삼각형 넓이
	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	// 반지름이 큰쪽이 1번 원
	if (r1 < r2)
	{
		swap(x1, x2);
		swap(y1, y2);
		swap(r1, r2);
	}

	double d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	if (d >= r1 + r2) // 원이 겹지치 않을때
		cout << "0.000";
	else if (d + r2 <= r1) // 작은원이 큰원 내부에 있을때
		cout << r2 * r2 * acos(-1);
	else
	{
		// 코사인 법칙
		double theta1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
		double theta2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));

		// 부채꼴 넓이 - 삼각형 넓이
		double area1 = (r1 * r1 * theta1) - (r1 * r1 * sin(2 * theta1)) / 2;
		double area2 = (r2 * r2 * theta2) - (r2 * r2 * sin(2 * theta2)) / 2;

		// 총 면적
		cout << area1 + area2;
	}
}

