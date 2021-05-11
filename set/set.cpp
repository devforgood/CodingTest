
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string op;
    int num;
    int set=0;
    cin >> n;
    while(n--)
    {
        cin >> op;

        if (op == "add")
        {
            cin >> num;
            set |= 1 << num;
        }
        else if (op == "remove")
        {
            cin >> num;
            set &= (~(1 << num));
        }
        else if (op == "check")
        {
            cin >> num;
            if ((set & (1 << num)) != 0)
            {
                cout << 1 << '\n'; // endl로 했을때 시간 초과로 실패가 발생한다. 미세한 시간차로 인해서 발생하는것으로 보인다.
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (op == "toggle")
        {
            cin >> num;
            set ^= 1 << num;
        }
        else if (op == "all")
        {
            set = (1<<21) -1;

        }
        else if (op == "empty")
        {
            set = 0;
        }
    }
    return 0;
}

