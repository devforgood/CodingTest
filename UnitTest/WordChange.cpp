
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



    TEST_CLASS(WordChange)
    {
    public:

        int solution(string begin, string target, vector<string> words) 
        {
            int answer = 0;
            vector<bool> visited(words.size(), false);
            queue<pair<string,int>> queue;
            queue.push(make_pair(begin, 0));


            while (queue.empty() == false)
            {
                string word = queue.front().first;
                int depth = queue.front().second;
                queue.pop();
                if (word == target)
                    return depth;

                for (int i = 0; i < words.size(); ++i)
                {
                    if (visited[i])
                        continue;

                    int cnt = 0;
                    for (int j = 0; j < words[i].length(); ++j)
                    {
                        if (word[j] != words[i][j])
                            ++cnt;
                        if (cnt > 1)
                            break;
                    }

                    if (cnt == 1)
                    {
                        visited[i] = true;
                        queue.push(make_pair(words[i], depth+1));

                    }
                }
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(4, solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }));
            Assert::AreEqual(0, solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" }));



        }



    };
}
