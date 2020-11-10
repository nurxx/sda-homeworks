#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int half1_size = m - l + 1;
	int half2_size = r - m;
	int first[half1_size], second[half2_size];

	for (i = 0; i < half1_size; i++)
	{
		first[i] = arr[l + i];
	}
	for (j = 0; j < half2_size; j++)
	{
		second[j] = arr[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = l;
	while (i < half1_size && j < half2_size)
	{
		if (first[i] >= second[j])
		{
			arr[k] = first[i++];
		}
		else
		{
			arr[k] = second[j++];
		}
		k++;
	}

	while (i < half1_size)
	{
		arr[k++] = first[i++];
	}
	while (j < half2_size)
	{
		arr[k++] = second[j++];
	}
}
void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int m = left + (right - left) / 2;
		mergeSort(arr, left, m);
		mergeSort(arr, m + 1, right);

		merge(arr, left, m, right);
	}
}
int main() {
	int n = 0, k = 0;
	cin >> n >> k;
	int arr[100001];
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	mergeSort(arr, 0, n - 1);
	for (int i = k - 1; i<n; i += k)
	{
		arr[i] = 0;
	}
	int sum = 0;
	for (int i = 0; i<n; i++)sum += arr[i];

	cout << sum << endl;
	return 0;
}
