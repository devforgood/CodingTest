
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h> 
#include <algorithm>

int main(void)
{
	int arr[3];
	while (true)
	{
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;

		std::sort(arr, arr + 3);

		if(arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
			printf("right\n");
		else
			printf("wrong\n");
	}
}

