#include <iostream>
#include <stack>
#include <string>

using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;

    stack<int> st;
    int num;
    for (int i = 0; i < n; ++i)
    {
		cin >> num;
        if (num == 0)
            st.pop();
        else
		    st.push(num);
    }


    int sum = 0;
    while (st.empty()==false)
    {
        sum += st.top();
        st.pop();
    }

    cout << sum << "\n";
}
