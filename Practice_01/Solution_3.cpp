#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;


int main() {

	char a[1001];
	char b[1001];
	string result;
	cin >> a;
	cin >> b;
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 1; i<strlen(a); i++)
		{
			if (a[i]<a[i - 1])
			{
				flag = true;
				char temp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = temp;
			}
		}
	}
	bool flag1 = true;
	while (flag1)
	{
		flag1 = false;
		for (int i = 1; i<strlen(b); i++)
		{
			if (b[i]<b[i - 1])
			{
				flag1 = true;
				char temp = b[i];
				b[i] = b[i - 1];
				b[i - 1] = temp;
			}
		}
	}
	int index = 0;
	for (int i = 0; i<strlen(a); i++)
	{
		for (int j = index; j<strlen(b); j++)
		{
			if (a[i] == b[j])
			{
				result += a[i];
				index = j + 1; break;
			}
		}
	}
	cout << result << endl;

	return 0;
}

