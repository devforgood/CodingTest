
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
    TEST_CLASS(MaxNonoverlappingSegments)
    {
    public:


        int solution(vector<int>& A, vector<int>& B) 
        { 
            if (A.size() < 1) 
                return 0; 
            int answer = 1; 
            int end = B[0]; 
            for (int i = 1; i < A.size(); ++i) 
            { 
                if (A[i] > end)
                { 
                    ++answer;
                    end = B[i];
                }
            } return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> A(5);
            vector<int> B(5);

            A[0] = 1;
            A[1] = 3;
            A[2] = 7;
            A[3] = 9;
            A[4] = 9;
            B[0] = 5;
			B[1] = 6;
			B[2] = 8;
			B[3] = 9;
			B[4] = 10;

            Assert::AreEqual(3, solution(A, B));
        }
    };
}
