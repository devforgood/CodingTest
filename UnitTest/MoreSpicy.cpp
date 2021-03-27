
#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(MoreSpicy)
    {
    public:


        int solution(vector<int> scoville, int K) {
            int answer = -1;

            priority_queue<int, vector<int>, greater<int>> queue;
            for (vector<int>::const_iterator itr = scoville.begin(); itr != scoville.end(); ++itr)
                queue.push(*itr);

            
            int a;
            int b;
            int c;
            for(int i=0;i<1000000;++i)
            {


                a = queue.top();
                if (a >= K)
                    return i;

                if (queue.size() <= 1)
                    return -1;

                queue.pop();

                b = queue.top();
                queue.pop();

                c = a + (b * 2);
                queue.push(c);
            }




            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> numbers = { 1, 2, 3, 9, 10, 12 };
            Assert::AreEqual(2, solution(numbers, 7));
        }

        TEST_METHOD(TestMethod2)
        {
            vector<int> numbers = { 1, 2, 3};
            Assert::AreEqual(2, solution(numbers, 12));
        }

    };
}
