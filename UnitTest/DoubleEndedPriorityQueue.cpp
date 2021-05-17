
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


    TEST_CLASS(DoubleEndedPriorityQueue)
    {
    public:


        vector<int> solution(vector<string> operations) {
            vector<int> answer;
            // 정렬이된 자료 구조이고, 앞뒤 삭제가 가능한 자료구조
            set<int> queue;

            for (auto op : operations)
            {
                if (op[0] == 'I')
                {
                    queue.insert(atoi(&op.c_str()[2]));
                }
                else if (op == "D 1")
                {
                    if (queue.empty() == false)
                    {
                        queue.erase(--queue.end());
                    }
                }
                else
                {
                    if (queue.empty() == false)
                    {
                        queue.erase(queue.begin());
                    }
                }
            }

            if (queue.empty())
                return { 0, 0 };

            answer.push_back(*queue.rbegin());
            answer.push_back(*queue.begin());

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            auto result = solution({ "I 7","I 5","I -5","D -1" });
            Assert::AreEqual(7, result[0]);
            Assert::AreEqual(5, result[1]);

        }



    };
}
