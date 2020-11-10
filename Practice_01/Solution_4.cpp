#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Pair {
	int a;
	int b;
	int dif;
	Pair& operator=(const Pair&other);
};
Pair &Pair:: operator=(const Pair&other)
{
	a = other.a;
	b = other.b;
	dif = other.dif;
	return*this;
}

void merge(Pair pairs[], int left, int middle, int right)
{
	int half1_size = middle - left + 1;
	int half2_size = right - middle;

	Pair first[half1_size], second[half2_size];
	for (int i = 0; i < half1_size; i++)
	{
		first[i] = pairs[left + i];
	}
	for (int j = 0; j < half2_size; j++)
	{
		second[j] = pairs[middle + j + 1];
	}

	int  i = 0;
	int  j = 0;
	int k = left;
	while (i < half1_size && j < half2_size)
	{
		if (first[i].dif <= second[j].dif)
		{
			pairs[k] = first[i++];
		}
		else
		{
			pairs[k] = second[j++];
		}
		k++;
	}
	while (i < half1_size)
	{
		pairs[k++] = first[i++];
	}

	while (j < half2_size)
	{
		pairs[k++] = second[j++];
	}
}
void mergeSort(Pair pairs[], int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		mergeSort(pairs, left, middle);
		mergeSort(pairs, middle + 1, right);

		merge(pairs, left, middle, right);
	}
}
int main()
{
	int arr[1001];
	int n = 3, k = 1;
	cin >> n >> k;
	Pair pairs[n*(n - 1) / 2];
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	int g = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			pairs[g].a = arr[i];
			pairs[g].b = arr[j];
			pairs[g].dif = abs(arr[i] - arr[j]);
			g++;
		}
	}
	mergeSort(pairs, 0, g - 1);
	if (pairs[k - 1].a > pairs[k - 1].b)
	{
		swap(pairs[k - 1].a, pairs[k - 1].b);
	}
	cout << pairs[k - 1].a << " " << pairs[k - 1].b << endl;

	return 0;
}
