#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Pair {
	int meters;
	int changeMoney;
	Pair &operator=(const Pair&other);
};
Pair &Pair::operator=(const Pair&other)
{
	meters = other.meters;
	changeMoney = other.changeMoney;

	return *this;
}
bool compare(Pair p1, Pair p2)
{
	return (p1.meters <= p2.meters && p1.changeMoney<p2.changeMoney) || (p1.meters >= p2.meters &&p1.changeMoney<p2.changeMoney);
}

int main() {
	int n;
	cin >> n;
	Pair pairs[n];
	for (int i = 0; i<n; i++)
	{

		cin >> pairs[i].meters;
	}
	for (int i = 0; i<n; i++)
	{
		cin >> pairs[i].changeMoney;
	}
	std::sort(pairs, pairs + n, compare);

	long long sum = 0;
	for (int i = 0; i<n; i++)
	{
		sum += abs(pairs[i].meters - pairs[n - 1].meters)*pairs[i].changeMoney;
	}
	cout << sum << endl;
	return 0;
}


