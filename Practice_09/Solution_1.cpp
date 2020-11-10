#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long arr[n];
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	std::sort(arr, arr + n);
	int unique = 0;
	int j = 1;
	for (int i = 0; i<n; i++)
	{
		if (arr[i] != arr[j]) unique++;

		j++;

	}
	cout << unique;
	return 0;
}