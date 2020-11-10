#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long merge(int arr[], int temp[], int low, int mid, int  high)
{
	int k = low, i = low, j = mid + 1;
	long long inversionCount = 0;
	while (i <= mid&&j <= high)
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			inversionCount += (mid - i + 1);
		}
	}
	while (i <= mid)
	{
		temp[k++] = arr[i++];
	}
	for (int i = low; i <= high; i++)
	{
		arr[i] = temp[i];
	}
	return inversionCount;
}
long long sort(int arr[], int temp[], int low, int high)
{
	if (high == low)
	{
		return 0;
	}
	int mid = (low + ((high - low) >> 1));
	long long inversionCount = 0;

	inversionCount += sort(arr, temp, low, mid);
	inversionCount += sort(arr, temp, mid + 1, high);

	inversionCount += merge(arr, temp, low, mid, high);

	return inversionCount;

}

int main()
{
	int arr[500001];
	int orders;
	cin >> orders;
	int n;
	int count = 0;
	int milimeters[1000001] = { 0 };
	int temp[1000001] = { 0 };
	while (orders)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> milimeters[i];
		}
		for (int i = 0; i<n; i++)
		{
			temp[i] = milimeters[i];
		}
		cout << sort(milimeters, temp, 0, n - 1) << endl;
		milimeters[n] = { 0 };
		temp[n] = { 0 };
		orders--;
	}


	return 0;
}

