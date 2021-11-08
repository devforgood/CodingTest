#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, s;
	int arr[100000] = { 0, };
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];


	int start = 0;
	int end = 0;
	int minCount = 9e8;
	int sum = 0;

	while (start <= end)
	{
		if (sum >= s)
		{
			minCount = min(minCount, end - start);
			sum -= arr[start++];
		}
		else if (end == n)
			break; // end 인덱스가 마지막 일지라도 sum이 조건을 만족하면 하나씩 줄여가면 최소 값을 찾아봐야 한다.
		else
			sum += arr[end++];

	}

	if (minCount == 9e8)
		cout << "0\n";
	else
		cout << minCount << "\n";

}