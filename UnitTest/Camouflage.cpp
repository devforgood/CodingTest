
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

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(Camouflage)
    {
    public:



        int solution2(vector<vector<string>> clothes) {
            int answer = 0;
            unordered_map<string, vector<string>> map;
            for (auto c : clothes)
                map[c[1]].push_back(c[0]);

            set<string> combination;
            string str;
            string last_str;
            int cnt = 0;
            for (int i = 1; i <= map.size(); ++i)
            {
                for (auto m : map)
                {
                    for (auto v : m.second)
                    {
                        last_str = str;
                        str += v;
                        ++cnt;
                        if (cnt == i)
                        {
                            if (combination.find(str) == combination.end())
                            {
                                combination.insert(str);
                                cnt = 0;
                                str = "";
                            }
                            else
                            {
                                str = last_str;
                                --cnt;
                            }
                        }
                    }
                }

            }


            return combination.size();
        }


        int solution(vector<vector<string>> clothes) {
            int answer = 1;
            unordered_map<string, int> map;
            for (auto c : clothes)
            {
                if (map.find(c[1]) != map.end())
                {
                    map[c[1]] += 1;
                }
                else
                {
                    map[c[1]] = 2;
                }
            }

            for (auto m : map)
                answer *= m.second;


            return answer-1;
        }

        TEST_METHOD(TestMethod1)
        {

            // 예를 들어 머리부분 3개고, 눈부분 2개면요 -> ([머리] 입을 수 있는 경우 3가지 + 아무것도 안 입는 경우 1가지) * ([눈] 입을 수 있는 경우 2가지 + 아무것도 안 입는 경우 1가지) 이렇게 계산이 되는데, 
            // 문제에서 적어도 무언가는 하나는 써야 한다고 했으니 모든 부분에 아무것도 안 입는 경우 1가지를 제외하는 겁니다.
            vector<vector<string>> clothes = { {"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"} };

            Assert::AreEqual(5, solution(clothes));
        }



    };
}
