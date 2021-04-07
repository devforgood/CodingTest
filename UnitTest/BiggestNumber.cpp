
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


    TEST_CLASS(BiggestNumber)
    {
    public:

        struct cmp {
            bool operator()(string a, string b) 
            {
                //string a_tmp = a;
                //string b_tmp = b;

                //int length;

                //if (a.length() > b.length())
                //{
                //    length = a.length();
                //    b_tmp += a_tmp;
                //}
                //else if (a.length() < b.length())
                //{
                //    length = b.length();
                //    a_tmp += b_tmp;
                //}
                //else
                //{
                //    length = a.length();
                //}

                //for (int i = 0; i < length; ++i)
                //{
                //    if (a_tmp[i] == b_tmp[i])
                //    {
                //        continue;
                //    }
                //    return a_tmp[i] > b_tmp[i];
                //}

                // 최소 길이 비교후 같을 경우 두개의 최대 길이로 비교
                return a+b > b+a;
            }
        };

        string solution(vector<int> numbers) {
            string answer = "";
            vector<string> num;
            for (int i = 0; i < numbers.size(); ++i)
                num.push_back(to_string(numbers[i]));

            sort(num.begin(), num.end(), cmp());

            for (int i = 0; i < num.size(); ++i)
                answer += num[i];

            if (answer[0] == '0')
                return "0";

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> numbers = { 3, 30, 34, 5, 9 };

            Assert::AreEqual(string("9534330"), solution(numbers));

        }



    };
}
