#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned int days(unsigned int cookies)
{

	unsigned int days = 0;
	if (cookies == 0)
	{
		return 0;
	}
	days += (unsigned int)log2(cookies);
	days++;

	return days;
}
int main() {
	vector<unsigned int>a;
	unsigned int t;
	unsigned int n;
	cin >> t;
	for (unsigned int i = 0; i<t; i++)
	{
		cin >> n;
		a.push_back(n);
	}
	for (unsigned int i = 0; i<t; i++)
	{
		cout << days(a[i]) << endl;
	}
	return 0;
}

