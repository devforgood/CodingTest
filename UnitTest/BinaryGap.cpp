
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
    TEST_CLASS(BinaryGap)
    {
    public:
        int solution(int N) {
            // write your code in C++14 (g++ 6.2.0)

            string num;
            for (int i = 31; i >=0 ; --i)
            {
                if (N & (1 << i))
                {
                    num = num + '1';
                }
                else if(num.length() != 0)
                {
                    num = num + '0';
                }
            }

            int max = 0;
            int cnt = 0;
            for (int i = 0; i < num.length(); ++i)
            {
                if (num[i] == '0')
                    ++cnt;
                else
                {
                    if (max < cnt)
                        max = cnt;
                    
                    cnt = 0;
                }

            }

            return max;

        }



        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(0, solution(32));
            Assert::AreEqual(5, solution(1041));
        }
    };
}
