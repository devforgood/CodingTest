
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
    TEST_CLASS(MaxProductOfTree)
    {
    public:
        int solution2(vector<int>& A) 
        {
            // 복잡도 증가로 인해 실패
            int answer = INT_MIN;
            for (int i = 0; i < A.size()-2; ++i)
            {
                for (int j = i+1; j < A.size()-1; ++j)
                {
                    for (int k = j + 1; k < A.size(); ++k)
                    {
                        int v = A[i] * A[j] * A[k];
                        if (answer < v)
                            answer = v;
                    }
                }
            }
            return answer;
        }

        int solution(vector<int>& A)
        {
            sort(A.begin(), A.end());

            int answer = A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3];

            if (A[0] <= 0 && A[1] <= 0 && A[A.size() - 1] >= 0)
            {
                if (answer < (A[0] * A[1] * A[A.size() - 1]))
                    answer = A[0] * A[1] * A[A.size() - 1];
            }
            return answer;
        }





        TEST_METHOD(TestMethod1)
        {
            vector<int> A(6);
            A[0] = -3;
            A[1] = 1;
            A[2] = 2;
            A[3] = -2;
            A[4] = 5;
            A[5] = 6;
            Assert::AreEqual(60, solution(A));
        }
    };
}
