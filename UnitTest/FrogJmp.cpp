
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
    TEST_CLASS(FrogJmp)
    {
    public:
        int solution(int X, int Y, int D) {
           
            int answer = ((Y - X) / D);
            if ((Y - X) % D > 0)
                ++answer;
            return answer;
        }





        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(3, solution(10, 85, 30));
        }
    };
}
