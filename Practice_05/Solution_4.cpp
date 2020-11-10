#include <iostream>
#include <string>
#include <cstring>

using namespace std;
bool isMagic(string s)
{
	if (s.length() == 1)return true;
	long long int j = 1;
	for (long long int i = 0; i < s.length() - 1; i++)
	{

		if (s[i] == '0' &&s[j] != '2')
			return false;

		else if (s[i] == '1'&& s[j] != '3')
			return false;

		else if (s[i] == '2' && s[j] != '0'&& s[j] != '4')
			return false;

		else if (s[i] == '3'&& s[j] != '1'&&s[j] != '5')
			return false;

		else if (s[i] == '4'&& s[j] != '2'&& s[j] != '6')
			return false;

		else if (s[i] == '5'&& s[j] != '3'&& s[j] != '7')
			return false;

		else if (s[i] == '6'&& s[j] != '4'&& s[j] != '8')
			return false;

		else if (s[i] == '7'&& s[j] != '5'&& s[j] != '9')
			return false;

		else if (s[i] == '8'&& s[j] != '6')
			return false;

		else if (s[i] == '9'&& s[j] != '7')
			return false;

		j++;
	}
	return true;
}
int main()
{
	long long n;
	cin >> n;

	for (long long int i = 1; i <= n; i++)
	{
		string s = to_string(i);
		if (isMagic(s))
		{
			cout << i << ' ';
		}

	}
	return 0;
}
