#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Clone {
	int index;
	long long sum;
	int last;
};

int main()
{
	int n;
	cin >> n;
	Clone *arr = new Clone[n];
	int flag = 0;
	for (int i = 0; i <n; i++)
	{
		cin >> arr[i].index >> arr[i].last;
		arr[i].sum = 0;
		if (arr[i].index == 0)
		{
			if (arr[i].last > 0)
			{
				arr[i].sum += arr[i].last;
			}
		}
		else {
			if (arr[i].last > 0)
			{
				arr[i].sum += arr[arr[i].index - 1].sum;
				arr[i].sum += arr[i].last;
				flag = 0;
			}
			else {
				arr[i].sum += arr[arr[i].index - 1].sum;
				if (arr[i].sum>0) { arr[i].sum -= arr[arr[i].index - 1].last; }
				arr[i].last = arr[arr[i].index - 2 - flag].last;

				flag += 2;
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].sum>0) { sum += arr[i].sum; }
	}
	cout << sum << endl;
	delete[]arr;
	return 0;
}
