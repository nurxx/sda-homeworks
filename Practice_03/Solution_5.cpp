#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Pairs {
	long long a;
	long long b;
	Pairs &operator=(const Pairs&other);

};
Pairs &Pairs :: operator=(const Pairs &other)
{
	a = other.a;
	b = other.b;
	return *this;
}
bool compare(Pairs p1, Pairs p2)
{
	return (p1.a >= p2.a && p1.b<p2.b);
}
void merge(Pairs arr[], long long start, long long middle, long long end)
{
	long long leftLength = middle - start + 1;
	long long rightLength = end - middle;

	Pairs* leftArr = new Pairs[leftLength];
	Pairs* rightArr = new Pairs[rightLength];

	for (long long i = 0; i < leftLength; i++)
	{
		leftArr[i] = arr[start + i];
	}
	for (long long j = 0; j < rightLength; j++)
	{
		rightArr[j] = arr[middle + 1 + j];
	}

	long long i = 0;
	long long j = 0;
	long long index = start;
	while (i < leftLength && j < rightLength)
	{
		if (compare(leftArr[i], rightArr[j]))
		{
			arr[index] = leftArr[i++];
		}
		else
		{
			arr[index] = rightArr[j++];
		}
		index++;
	}

	while (i < leftLength)
	{
		arr[index++] = leftArr[i++];
	}

	while (j < rightLength)
	{
		arr[index++] = rightArr[j++];
	}

	delete[] leftArr;
	delete[] rightArr;
}

void mergeSort(Pairs arr[], long long start, long long end)
{
	if (start < end)
	{
		long long  middle = (start + end) / 2;
		mergeSort(arr, start, middle);
		mergeSort(arr, middle + 1, end);

		merge(arr, start, middle, end);
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	Pairs pairs[n];
	long long a, b;
	for (int i = 0; i<n; i++)
	{
		cin >> a >> b;
		pairs[i].a = a;
		pairs[i].b = b;
	}
	mergeSort(pairs, 0, n - 1);
	long double sum = 0;
	for (int i = 0; i<k; i++)
	{
		sum += pairs[i].a;
	}
	cout << sum << endl;
	return 0;
}


