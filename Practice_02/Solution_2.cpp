#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<cstring>
using namespace std;
void countingSort(int *arr, string str)
{
	for (int i = 0; i<str.length(); i++)
	{
		arr[str[i] - 97]++;
	}

}
int maxRepeating(int*arr)
{
	int maxRepeating = arr[0];
	for (int i = 1; i<25; i++)
	{
		if (arr[i]>maxRepeating) {
			maxRepeating = arr[i];
		}
	}
	return maxRepeating;
}
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string str;
	cin >> str;
	int arr[25] = { 0 };

	countingSort(arr, str);
	int maxRepeat = maxRepeating(arr);
	if (str.length() - maxRepeat >= maxRepeat - 1)
	{
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	return 0;
}

