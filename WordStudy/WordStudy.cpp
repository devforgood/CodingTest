#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string str;
    cin >> str;

    map<char, int> dic;

    int max = 0;
    char alphabet;
    int cnt;
    bool single = false;
    for (int i = 0; i < str.length(); ++i)
    {
        cnt = ++dic[toupper(str[i])];

        if (cnt > max)
        {
            single = true;
            alphabet = toupper(str[i]);
            max = cnt;
        }
        else if (cnt == max)
        {
            single = false;
        }
    }
    if (single == false)
        cout << "?";
    else
        cout << alphabet;

}