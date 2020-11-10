#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void reverse(unsigned int*arr, int size)
{
	int start = 0, end = size - 1;
	while (start<end)
	{
		unsigned int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
bool compare(unsigned int a, unsigned int b)
{
	if (a == 0)
	{
		return false;
	}
	if (b == 0)
	{
		return true;
	}
	unsigned int copyA = a;
	unsigned int copyB = b;
	int digitsA = 0, digitsB = 0;
	while (copyA)
	{
		copyA /= 10;
		digitsA++;
	}
	while (copyB)
	{
		copyB /= 10;
		digitsB++;
	}
	int size = digitsA + digitsB;
	unsigned int ar[100], br[100];
	unsigned int a1 = a, b1 = b;
	for (int i = 0; i<digitsA; i++)
	{
		ar[i] = a1 % 10;
		a1 /= 10;
	}
	for (int i = digitsA; i<size; i++)
	{
		ar[i] = b1 % 10;
		b1 /= 10;
	}
	reverse(ar, size);
	for (int i = 0; i<digitsB; i++)
	{
		br[i] = b % 10;
		b /= 10;
	}
	for (int i = digitsB; i<size; i++)
	{
		br[i] = a % 10;
		a /= 10;
	}
	reverse(br, size);
	unsigned int num1 = 0, num2 = 0;
	for (int i = 0; i<size; i++)
	{
		num1 = num1 + (unsigned int)(ar[i] * pow(10, size - i - 1));
	}
	for (int i = 0; i<size; i++)
	{
		num2 = num2 + (unsigned int)(br[i] * pow(10, size - i - 1));
	}

	return (num1 <= num2);
}
void merge(unsigned int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	unsigned int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (compare(L[i], R[j]))
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(unsigned int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


int main() {
	int n;
	cin >> n;
	unsigned int arr[n];
	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	mergeSort(arr, 0, n - 1);
	unsigned int zeros = 0;
	for (int i = 0; i<n; i++)
	{
		if (arr[i] == 0)
		{
			zeros++;
		}
	}
	if (zeros == n)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i<n; i++)
	{
		cout << arr[i];
	}


	return 0;
}

