
#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{

    TEST_CLASS(StockPrice)
    {
    public:


        vector<int> solution2(vector<int> prices) {
            vector<int> answer;
            stack<int> st;
            stack<int> st2;
            st.push(prices[0]);

            for(int i=0;i<prices.size();++i)
                answer.push_back(0);

            for (int i = 1; i < prices.size(); ++i)
            {
                int cnt = 1;


                if (prices[i] < st.top())
                {
                    st2 = st;

                    while (prices[i] < st2.top())
                    {
                        if (i - cnt < 0)
                            break;

                        if (answer[i - cnt] == 0)
                            answer[i - cnt] = cnt;
                        ++cnt;

                        st2.pop();
                    }
                }

				st.push(prices[i]); 
            }

            int j = prices.size() - 1;
            for (int i = 0; i < prices.size(); ++i, --j)
            {
                if (answer[i] == 0)
                {
                    answer[i] = j;
                }
            }
            

            return answer;
        }

        vector<int> solution3(vector<int> v) {
            vector<int> ans;
            for (int i = 0; i < v.size() - 1; i++) {
                int idx = -1;
                int k = v[i];
                for (int j = i + 1; j < v.size(); j++) {
                    if (k > v[j]) {
                        idx = j;
                        break;
                    }
                }
                if (idx == -1) ans.push_back(v.size() - 1 - i);
                else ans.push_back(idx - i);
            }
            ans.push_back(0);
            return ans;
        }

        vector<int> solution(vector<int> prices) {
            vector<int> answer(prices.size());
            stack<int> s;
            int size = prices.size();
            for (int i = 0; i < size; i++) {
                // ������ �񿴴��� üũ
                // ���ÿ� �ֽİ����� �ƴ� �ε����� �ִ´�.
                // ���� ����� ���� �ֿ켱�̹Ƿ� ����� ���ÿ� ���� �ٽ� ���� �ʿ䰡 ����.
                // ������� 1�ʵ� �϶��̸� ���� � ���� ���� 1�ʺ��� ũ�� �����̴�.
                while (!s.empty() && prices[s.top()] > prices[i]) {
                    answer[s.top()] = i - s.top();
                    s.pop();
                }
                s.push(i);
            }
            while (!s.empty()) {
                answer[s.top()] = size - s.top() - 1;
                s.pop();
            }
            return answer;
        }


        TEST_METHOD(TestMethod1)
        {
             vector<int> prices = { 1, 2, 3, 2, 3, 1 };

            vector<int> result = solution(prices);
            Assert::AreEqual(5, result[0]);
            Assert::AreEqual(4, result[1]);
            Assert::AreEqual(1, result[2]);
            Assert::AreEqual(2, result[3]);
            Assert::AreEqual(1, result[4]);
            Assert::AreEqual(0, result[5]);
        }



    };
}
