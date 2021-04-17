
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

        struct double_ended_priority_queue {
            set<int> s;

            int size()
            {
                return s.size();
            }


            bool isEmpty()
            {
                return (s.size() == 0);
            }

            void insert(int x)
            {
                s.insert(x);
            }


            int getMin()
            {
                return *(s.begin());
            }


            int getMax()
            {
                return *(s.rbegin());
            }

            void deleteMin()
            {
                if (s.size() == 0)
                    return;
                s.erase(s.begin());
            }

            void deleteMax()
            {
                if (s.size() == 0)
                    return;
                auto it = s.end();
                it--;
                s.erase(it);
            }
        };

        vector<int> solution(vector<string> operations) {
            vector<int> answer;
            double_ended_priority_queue queue;

            for (auto op : operations)
            {
                if (op[0] == 'I')
                {
                    queue.insert(atoi(&op.c_str()[2]));
                }
                else if (op == "D 1")
                {
                    queue.deleteMax();
                }
                else
                {
                    queue.deleteMin();
                }
            }

            if (queue.isEmpty())
                return { 0, 0 };

            answer.push_back(queue.getMax());
            answer.push_back(queue.getMin());

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
