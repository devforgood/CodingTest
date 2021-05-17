
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



    TEST_CLASS(TravelPath)
    {
    public:

        map<pair<string, string>, int> visited;
        map<string, set<string>> nodes;
        vector<string> answer;

        string dfs(string node)
        {
            int ticket_count = 0;
            for (auto v : visited)
                ticket_count += v.second;
            if (ticket_count == 0)
                return node;

            for (auto next_node : nodes[node])
            {
                if(visited[make_pair(node, next_node)] == 0)
                    continue;

                visited[make_pair(node, next_node)] -= 1;

                string ret = dfs(next_node);
                if (ret != "")
                {
                    answer.insert(answer.begin(), ret);
                    return node;
                }
                else
                {
                    visited[make_pair(node, next_node)] += 1;
                }

            }
            return "";
        }

        vector<string> solution(vector<vector<string>> tickets) {

            for (int i = 0; i < tickets.size(); ++i)
            {
                nodes[tickets[i][0]].insert(tickets[i][1]);
                visited[make_pair(tickets[i][0], tickets[i][1])] += 1;
            }

         
            dfs("ICN");
            answer.insert(answer.begin(), "ICN");


            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(true, solution({ {"ICN", "AAA"}, {"ICN", "AAA"}, {"ICN", "AAA"}, {"AAA", "ICN"}, {"AAA", "ICN"} }) == vector<string>({ "ICN", "AAA", "ICN", "AAA", "ICN", "AAA" }));
            nodes.clear();
            answer.clear();
            visited.clear();
            Assert::AreEqual(true, solution({{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}} ) == vector<string>({"ICN", "JFK", "HND", "IAD"}));
            nodes.clear();
            answer.clear();
            visited.clear();
            Assert::AreEqual(true, solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}} ) == vector<string>({"ICN", "ATL", "ICN", "SFO", "ATL", "SFO"}));



        }



    };
}
