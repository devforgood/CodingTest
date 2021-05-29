#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	string str;
	cin >> str;

	vector<string> croatia_alphabets = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	int cnt = 0;
	bool find = false;
	for (int i = 0; i < str.length();)
	{
		find = false;
		for (int j = 0; j < croatia_alphabets.size(); ++j)
		{
			string & croatia_alphabet = croatia_alphabets[j];
			if (str.substr(i, croatia_alphabet.size()) == croatia_alphabet)
			{
				i += croatia_alphabet.length();
				find = true;
				break;
			}
		}
		if (find == false)
		{
			++i;
		}
		++cnt;
	}

	cout << cnt;
}