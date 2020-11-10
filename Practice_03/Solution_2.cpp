#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binary_search_first_occurrence(long long arr[], unsigned int n, long long x)
{
	int start = 0, end = n - 1;
	int result = -1;
	while (start <= end)
	{
		int middle = (start + end) / 2;
		if (x == arr[middle])
		{
			result = middle + 1;
			end = middle - 1;
		}
		if (x<arr[middle])
		{
			end = middle - 1;
		}
		if (x>arr[middle])
		{
			start = middle + 1;
		}
	}
	return result;
}
int binary_search_last_occurrence(long long arr[], unsigned int n, long long x)
{
	int start = 0, end = n - 1;
	int result = -1;
	while (start <= end)
	{
		int middle = (start + end) / 2;
		if (x == arr[middle])
		{
			result = middle + 1;
			start = middle + 1;
		}
		if (x<arr[middle])
		{
			end = middle - 1;
		}
		if (x>arr[middle])
		{
			start = middle + 1;
		}
	}
	return result;
}
int main()
{

	unsigned int q;
	unsigned int n;

	cin >> n;
	long long *arr = new long long[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> q;
	long long *temp = new long long[q];
	for (int i = 0; i<q; i++)
	{
		cin >> temp[i];
	}
	unsigned int j = 0;
	while (q)
	{
		cout << binary_search_first_occurrence(arr, n, temp[j]) << ' '
			<< binary_search_last_occurrence(arr, n, temp[j]) << endl;
		j++;
		q--;
	}
	delete[]arr;
	delete[]temp;

	return 0;

}

