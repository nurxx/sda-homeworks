#include <iostream>
#include <algorithm>
#include<cmath>
#include <vector>

using namespace std;

bool dry(long long arr[], int n, long long k, long long minutes)
{
	long long a = 0, times = 0;
	for (int i = 0; i < n; i++)
	{
		a = arr[i] - minutes;
		if (a >= 0)
		{
			if ((a % (k - 1) == 0))times += a / (k - 1);
			else
			{
				times += a / (k - 1) + 1;
			}
		}
	}

	return (times <= minutes);
}

long long minutes(long long a[], int n, long long k)
{
	long long start = 0;
	long long end = 999999999;
	long long result = 0;
	if (k == 1)
	{
		result = a[n - 1];
	}
	else {

		while (start <= end)
		{
			long long middle = (start + end) / 2;
			if (dry(a, n, k, middle))
			{
				result = middle;
				end = middle - 1;
			}
			else {
				start = middle + 1;
			}
		}

	}

	return result;
}
int main()
{
	unsigned long long k;
	int n;
	cin >> n >> k;

	long long *arr = new long long[n];
	for (int i = 0; i <n; i++)
	{
		cin >> arr[i];
	}
	std::sort(arr, arr + n);
	cout << minutes(arr, n, k) << endl;

	delete[]arr;
	return 0;
}



