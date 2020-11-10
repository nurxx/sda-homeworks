#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[50000], R[50000];
	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}
	int i = 0, j = 0;
	int k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i++];
		}
		else
		{
			arr[k] = R[j++];
		}
		k++;
	}
	while (i < n1)
	{
		arr[k++] = L[i++];
	}
	while (j < n2)
	{
		arr[k++] = R[j++];
	}
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
int main()
{
	int arr[100001];
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	mergeSort(arr, 0, n - 1);
	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		if (sum <= k)
		{
			count++;
		}
	}
	cout << count << endl;

	return 0;
}


