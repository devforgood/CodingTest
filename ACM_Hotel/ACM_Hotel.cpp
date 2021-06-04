#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		int h, n;
		string w;
		cin >> h >> w >> n;

		int height = n % h;
		int num = n / h;
		if (height == 0)
			height = h;
		else
			++num;


		cout << height * 100 + num << endl;
	}
}