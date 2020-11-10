#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct time
{
	int hour1;
	int min1;
	int hour2;
	int min2;
};
void readInput(struct time &car)
{
	cin >> car.hour1 >> car.min1 >> car.hour2 >> car.min2;
}
void check(struct time &car)
{
	if (car.hour1 > car.hour2)
	{
		car.hour2 += 24;
	}
}
int Time(struct time&car)
{
	return (car.hour2 * 3600 + car.min2 * 60) - (car.hour1 * 3600 + car.min1 * 60);
}

int main()
{
	struct time car1, car2, car3;

	readInput(car1);
	readInput(car2);
	readInput(car3);

	check(car1);
	check(car2);
	check(car3);

	vector<int>a;
	a.push_back(Time(car1));
	a.push_back(Time(car2));
	a.push_back(Time(car3));
	int max = a[0], min = a[0];
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] < min)min = a[i];
		if (a[i] > max)max = a[i];
	}
	string mn = to_string((min / 60) / 60) + ":";
	if (((min / 60) % 60)<10 && ((min / 60) % 60)>0)
	{
		mn += '0';
	}
	mn += to_string((min / 60) % 60);
	string mx = to_string((max / 60) / 60) + ":";
	if (((max / 60) % 60)<10 && ((max / 60) % 60)>0)
	{
		mx += '0';
	}
	mx += to_string((max / 60) % 60);

	if (mn.length() == 3 && mn[2] == '0')
	{
		mn += '0';
	}
	if (mn.length() == 4 && mn[2] == ':'&&mn[3] == '0')
	{
		mn += '0';
	}

	if (mx.length() == 3 && mx[2] == '0')
	{
		mx += '0';
	}
	if (mx.length() == 4 && mx[2] == ':'&&mx[3] == '0')
	{
		mn += '0';
	}


	cout << mn << endl;
	cout << mx << endl;

	return 0;
}
