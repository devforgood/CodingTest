#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;

struct node
{
	string name;
	list<node*> child;

	node(string val)
	{
		name = val;
	}

	node * insert(node * n)
	{
		for (auto i = child.begin(); i != child.end(); ++i)
		{
			if ((*i)->name > n->name)
			{
				child.insert(i, n);
				return n;
			}
			else if ((*i)->name == n->name)
				return (*i);
		}
		child.insert(child.end(), n);
		return n;
	}
};

void print(node* p, string depth)
{
	cout << depth << p->name << '\n';

	for (auto i : p->child)
	{
		print(i, depth+"--");
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n, k;
	string feed;
	cin >> n;

	node head("");
	for (int i = 0; i < n; ++i)
	{
		cin >> k;

		cin >> feed;
		auto p = new node(feed);
		p = head.insert(p);

		for (int j = 1; j < k; ++j)
		{
			cin >> feed;
			auto p2 = new node(feed);
			p2 = p->insert(p2);
			p = p2;
		}
	}


	for (auto i : head.child)
		print(i, "");
	



}