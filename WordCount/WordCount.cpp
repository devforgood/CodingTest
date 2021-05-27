#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

int main()
{
    string str;

    getline(cin, str);

    int cnt = 0;

    if (str.empty() == false)
    {
        bool blank = true;
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == ' ' && blank == false)
            {
                ++cnt;
                blank = true;
            }
            else
            {
                blank = false;
            }
        }

        if (str[str.length()-1] != ' ')
            ++cnt;
    }

	cout << cnt;


}