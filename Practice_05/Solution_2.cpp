#include <iostream>
#include<vector>
#include <string>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int>ar;
	int x, max;
	long long sum;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "white")
		{
			cin >> x;
			ar.push_back(x);
		}
		else if (s == "green")
		{
			sum = 0;
			cin >> x;
			while (x)
			{
				sum += ar.back();
				ar.pop_back();
				x--;
			}
			ar.push_back(sum);
		}
		else if (s == "blue")
		{
			cin >> x;
			max = ar.back();
			while (x)
			{
				if (ar.back() > max)
				{
					max = ar.back();
				}
				ar.pop_back();
				x--;
			}
			ar.push_back(max);
		}
	}
	for (int i = 0; i < ar.size(); i++)
	{
		cout << ar[i] << ' ';
	}
	system("pause");
	return 0;
}