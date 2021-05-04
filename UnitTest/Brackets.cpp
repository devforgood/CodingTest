
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
    TEST_CLASS(Brackets)
    {
    public:


        int solution(string& S) {

            stack<char> stack;
            map<char, char> map;
            map[')'] = '(';
            map[']'] = '[';
            map['}'] = '{';

            for (auto c : S)
            {
                auto itr = map.find(c);
                if (itr != map.end())
                {
                    if (stack.top() != itr->second)
                    {
                        return 0;
                    }
                    stack.pop();
                }
                else
                {
                    stack.push(c);
                }
            }

            if (stack.empty() == false)
                return 0;

            return 1;
        }






        TEST_METHOD(TestMethod1)
        {

            Assert::AreEqual(1, solution(string("{[()()]}")));
        }
    };
}
