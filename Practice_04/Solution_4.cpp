#include <iostream>
#include <cmath>
#include<algorithm>
#include<string>
#include <cstring>
#include <list>

using namespace std;

int main()
{
	list<long long>l;
	int n;
	cin >> n;
	long long num;
	for (int i = 0; i < n; i++)
	{
		string command;
		cin >> command;
		if (command == "add")
		{
			cin >> num;
			l.push_back(num);
		}
		else if (command == "gun")
		{
			l.pop_back();
		}
		else if (command == "milen")
		{
			for (int i = l.size() / 2; i<l.size(); i++)
			{
				l.push_front(l.back());
				l.pop_back();
			}
		}
		command = "\0";
	}

	cout << l.size() << endl;
	while (!l.empty())
	{
		cout << l.front() << ' ';
		l.pop_front();
	}
	return 0;
}
