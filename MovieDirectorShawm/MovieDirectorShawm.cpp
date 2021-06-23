#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;



int main()
{
	int n;

	cin >> n;

	int i = 666;
	while(true)
	{
		if (std::to_string(i).find("666") != std::string::npos)
			--n;

		if (n == 0)
		{
			cout << i;
			break;
		}
		++i;
	}
}

