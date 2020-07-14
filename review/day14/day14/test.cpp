#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> a;
	int n;
	int count1 = 0;
	int count = 0, sum = 0, mul = 1;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] == 1)
			count1++;
		sum += a[i];
		mul *= a[i];
	}
	
	sort(a.begin(), a.end());
	for (int i = n - 1; i >= 0; --i)
	{
		if (mul / sum >= 1)
	}
	system("pause");
	return 0;
}

/*
#include <iostream>
using namespace std;

int getOutDay(int year, int month, int day)
{
	int moth[] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int nDay = 0;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		int tmp = moth[2];
		moth[2] = moth[0];
		moth[0] = tmp;
	}
	if (month < 1 || month > 12 || day < 1 || day > moth[month])
		return -1;
	for (int i = 1; i < month; i++)
	{
		nDay += moth[i];
	}
	nDay += day;
	return nDay;
}
int main()
{
	int year, month, day;
	cin >> year >> month >> day;
	cout << getOutDay(year, month, day) << endl;
	system("pause");
	return 0;
}
*/