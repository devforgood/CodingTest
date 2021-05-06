// BreakEvenPoint.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{

	int a, b, c, x;
	scanf("%d %d %d", &a, &b, &c);
	if (c == b)
	{
		printf("%d", -1);
		return 0;
	}

	x = a / (c - b);
	if (a + x * b >= c * x)
		++x;

	if (x <= 0)
		x = -1;

	printf("%d", x);

	return 0;

}

