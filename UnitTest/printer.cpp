
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
    TEST_CLASS(Printer)
    {
    public:
        int solution(vector<int> priorities, int location) {
            int answer = 0;
            queue<pair<int, int>> queue;
            priority_queue<int> pq;
            for (int i = 0; i < priorities.size(); ++i)
            {
                queue.push({ priorities[i], i });
                pq.push(priorities[i]);
            }

            while (true)
            {
                auto v = queue.front();
                if (pq.top() == v.first)
                {
                    ++answer;
                    if (v.second == location)
                    {
                        return answer;
                    }

                    pq.pop();
                    queue.pop();
                }
                else
                {
                    queue.pop();
                    queue.push(v);
                }
            }
            
            return answer;
        }


        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(1, solution({ 2, 1, 3, 2 }, 2));
            Assert::AreEqual(5, solution({ 1, 1, 9, 1, 1, 1 }, 0));
        }
    };
}
