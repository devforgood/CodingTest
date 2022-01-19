#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>

#define MAX_CHAR 26

using namespace std;

class TrieNode
{
private:
	TrieNode* children[MAX_CHAR];
	bool is_finish;
public:
	TrieNode()
	{
		is_finish = false;

		for (int i = 0; i < MAX_CHAR; ++i)
			children[i] = nullptr;
	}

	void insert(string s, int index)
	{
		if (s.length() > index)
		{
			if (children[s.at(index) -'a'] == nullptr)
				children[s.at(index) - 'a'] = new TrieNode();

			children[s.at(index) - 'a']->insert(s, index + 1);
		}
		else
		{
			is_finish = true;
		}
	}

	bool search(string s, int index)
	{
		if (s.length() <= index)
		{
			if (is_finish == false)
				return false;

			return true;
		}

		if (children[s.at(index) - 'a'] != nullptr)
			return (children[s.at(index) - 'a'])->search(s, index +1);

		return false;
	}
};




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	TrieNode root;
	for (int i = 0; i < n;++i)
	{
		string s;
		cin >> s;

		root.insert(s, 0);
	}

	int answer = 0;
	for (int i = 0; i < m; ++i)
	{
		string s;
		cin >> s;

		if (root.search(s, 0) == true)
			++answer;
	}

	cout << answer;
}