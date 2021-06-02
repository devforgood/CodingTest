#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	long long n;
	cin >> n;

	int numerator = 1;
	int denominator = 1;

	bool is_denominator = true;
	for (int i = 1; i < n; ++i)
	{
		if (is_denominator)
		{
			if (denominator==1)
			{
				++numerator;
				is_denominator = false;
			}
			else
			{
				++numerator;
				--denominator;
			}
		}
		else
		{
			if (numerator == 1)
			{
				++denominator;
				is_denominator = true;
			}
			else
			{
				--numerator;
				++denominator;
			}
		}
	}

	cout << denominator << "/" << numerator;
}