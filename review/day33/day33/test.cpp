#include <cstdio>
#include <cmath>
#include <iostream>
//闰年判断函数
inline int leap_year(int year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
//足年天数
inline int profit_of_year(int year)
{
	return 2 * 31 + 1 * 28 + 1 * 31 + 2 * 30 + 1 * 31 + 2 * 30 + 
		1 * 31 + 2 * 31 + 2 * 30 + 2 * 31 + 1 * 30 + 2 * 31 +
		leap_year(year);
}
//判断这个月份是不是质数月
inline bool prime(int n)
{
	return n == 2 || n == 3 || n == 5 || n == 7 || n == 11;
}
//求出一个日子是这一年的第几天
int profit_of_this_year(int year, int month, int day)
{
	if (!prime(month))
	{
		day *= 2;
	}
	while (--month)
	{
		switch (month)
		{
		case 1:
		case 8:
		case 10:
		case 12:
			day += 62;
			break;
		case 3:
		case 5:
		case 7:
			day += 31;
			break;
		case 4:
		case 6:
		case 9:
			day += 60;
			break;
		case 11:
			day += 30;
			break;
		case 2:
			day += 28 + leap_year(year);
			break;
		default:;
		}
	}
	return day;
}
int main()
{
	int year1, month1, day1, year2, month2, day2;
	int count_profit = 0;
	while (std::cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		count_profit = 0;
		count_profit += profit_of_year(year1) - profit_of_this_year(year1, month1, day1 - 1);
		
		count_profit += profit_of_this_year(year2, month2, day2);
		if (year1 == year2) 
		{
			count_profit -= profit_of_year(year1);
		}
		for (int i = year1 + 1; i < year2; i++) 
		{
			count_profit += profit_of_year(i);
		}
		std::cout << count_profit << std::endl;
	}
	return 0;
}


/*
#include <iostream>
#include <cstdio>
int main()
{
	int fib[100001];
	fib[0] = 1;
	fib[1] = 1;
	//提前计算斐波那契数列，只保留后6位
	for (int i = 2; i <= 100000; ++i)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] = fib[i] % 1000000; //由于是相加，所以只要后六位不影响下一个数的结果
	}
	//这里利用了OJ平台计时从开始读取数据的trick，这个技巧可以用在很多题目里
	int n;
	while (std::cin >> n)
	{
		if (n < 29)
		{
			//斐波那契数列小于6位
			printf("%d\n", fib[n]);
		}
		else
		{
			printf("%06d\n", fib[n]);
		}
	}
	return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int nthFaci(int n)
{
	unsigned int a = 1;
	unsigned int b = 1;
	unsigned int c = 2;
	while ((n -= 3) >= 0)
	{
		a = (b + c) % 1000000;
		b = (a + c) % 1000000;
		c = (a + b) % 1000000;
	}
	n += 3;
	if (n == 0)
		return a;
	if (n == 1)
		return b;
	if (n == 2)
		return c;
}

int main()
{
	vector<int> a;
	string str;
	getline(cin, str);
	string target = " ";
	int pre_pos = 0;
	int pos = 0;
	while ((pos = str.find_first_of(target, pos)) != string::npos)
	{
		a.push_back(stoi(str.substr(pre_pos, pos - pre_pos)));
		pre_pos = ++pos;
	}
	a.push_back(stoi(str.substr(pre_pos, str.size() - pre_pos)));

	for (int i = 0; i < a.size(); i++)
	{
		string str = to_string(nthFaci(a[i]));
		cout << str << endl;
		/*if (str.size() < 7)
			cout << str << endl;
		else
			cout << str.substr(str.size() - 6, 6) << endl;
	}
	
	system("pause");
	return 0;
}
*/