
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

            // ���� ��� �Ӹ��κ� 3����, ���κ� 2����� -> ([�Ӹ�] ���� �� �ִ� ��� 3���� + �ƹ��͵� �� �Դ� ��� 1����) * ([��] ���� �� �ִ� ��� 2���� + �ƹ��͵� �� �Դ� ��� 1����) �̷��� ����� �Ǵµ�, 
            // �������� ��� ���𰡴� �ϳ��� ��� �Ѵٰ� ������ ��� �κп� �ƹ��͵� �� �Դ� ��� 1������ �����ϴ� �̴ϴ�.
            vector<vector<string>> clothes = { {"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"} };

            Assert::AreEqual(5, solution(clothes));
        }



    };
}
