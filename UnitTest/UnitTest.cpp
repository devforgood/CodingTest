#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

        int solution(int bridge_length, int weight, vector<int> truck_weights) {
            int answer = 0;

            queue<int> bridge;
            int bridge_weight = 0;
            int i = 0;
            for (int j = 0; j < bridge_length; ++j)
                bridge.push(0);


            do
            {


                ++answer;


                bridge_weight -= bridge.front();
                bridge.pop();

                if (i >= truck_weights.size())
                {
                }
                else if (bridge_weight + truck_weights[i] <= weight)
                {
                    bridge.push(truck_weights[i]);

                    bridge_weight += truck_weights[i];
                    ++i;

                }
                else
                {
                    bridge.push(0);
                }


            } while (bridge.size() != 0);


            return answer;
        }
		
		TEST_METHOD(TestMethod1)
		{
            vector<int> v;
            v.push_back(7);
            v.push_back(4);
            v.push_back(5);
            v.push_back(6);


            Assert::AreEqual(8, solution(2, 10, v));
		}

        TEST_METHOD(TestMethod2)
        {
            vector<int> v;
            v.push_back(10);



            Assert::AreEqual(101, solution(100, 100, v));
        }
	};
}
