#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdio>
using namespace std;

// 根据 年-月-日 通过蔡勒公式计算当前星期几
// 1: 星期一 ... 7: 星期日
int day_of_week(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		year -= 1;
	}
	int century = year / 100;
	year %= 100;
	int week = year + (year / 4) + (century / 4) - 2 * century + 26 * (month + 1) / 10 + day -1;
	week = (week % 7 + 7) % 7;
	if (week == 0)
	{
		week = 7;
	}
	return week;
}
int day_of_demand(int year, int month, int count, int d_of_week)
{
	int week = day_of_week(year, month, 1); //求出1号星期数
	// 1 + 7(n - 1) + (所求星期数 + 7 - 1号星期数) % 7
	int day = 1 + (count - 1) * 7 + (7 + d_of_week - week) % 7;
	return day;
}
// 元旦
void new_year_day(int year)
{
	printf("%d-01-01\n", year);
}
// 马丁·路德·金纪念日（1月的第三个星期一）
void martin_luther_king_day(int year)
{
	printf("%d-01-%02d\n", year, day_of_demand(year, 1, 3, 1));
}
// 总统日（2月的第三个星期一）
void president_day(int year)
{
	printf("%d-02-%02d\n", year, day_of_demand(year, 2, 3, 1));
}
// 阵亡将士纪念日（5月的最后一个星期一）
void memorial_day(int year)
{
	// 从 6 月往前数
	int week = day_of_week(year, 6, 1);
	// 星期一的话，从 31 号往前数 6 天，否则，数 week - 2 天
	int day = 31 - ((week == 1) ? 6 : (week - 2));
	printf("%d-05-%02d\n", year, day);
}
// 国庆
void independence_day(int year)
{
	printf("%d-07-04\n", year);
}
// 劳动节（9月的第一个星期一）
void labor_day(int year)
{
	printf("%d-09-%02d\n", year, day_of_demand(year, 9, 1, 1));
}
// 感恩节（11月的第四个星期四）
void thanks_giving_day(int year)
{
	printf("%d-11-%02d\n", year, day_of_demand(year, 11, 4, 4));
}
// 圣诞节
void christmas(int year)
{
	printf("%d-12-25\n", year);
}
// 美国节日
void holiday_of_usa(int year)
{
	new_year_day(year);
	martin_luther_king_day(year);
	president_day(year);
	memorial_day(year);
	independence_day(year);
	labor_day(year);
	thanks_giving_day(year);
	christmas(year);
}
int main()
{
	int year;
	while (std::cin >> year)
	{
		holiday_of_usa(year);
		putchar('\n');
	}
}


/*
int main()
{
	int n;
	string pre_order, post_order;
	cin >> n >> pre_order >> post_order;

}

void oper(long a, long b, long c, long d)
{
	long k1 = a / b;
	a -= k1;
	long k2 = c / d;
	c -= k2;
	long k = k1 + k2;
	vector<string> v;
	v.resize(4);
	string tmp1;
	string tmp2;

	tmp1 += to_string(k1) + " ";
	if (a != 0)
		tmp1 += to_string(a) + "/" + to_string(b);
	else
		tmp1 = "";

	tmp1 += to_string(k1) + " ";
	if (a != 0)
		tmp2 += to_string(a) + "/" + to_string(b);
	else
		tmp2 = "";

	long k, e, f;
	
	//add 
	{
		v[0] += tmp1 + " + " + tmp2 + " = ";
		k = k1 + k2;



	}
	//difference
	{
		v[1] += tmp1 + " - " + tmp2 + " = ";
		k = k1 - k2;

	}
	//product
	{
		v[2] += tmp1 + " * " + tmp2 + " = ";
		k = k1 * k2;
		v[2] += " " + to_string(k);
		if (a * c != 0)
		{
			e = a * c;
			f = b * d;
			long E = e;
			long F = f;
			while ((E %= F) && (F %= E));
			e /= E + F;
			f /= E + F;
			v[2] += " " + to_string(E) + "/" + to_string(f);
		}

	}
	//quotient
	{
		v[3] += tmp1 + " / " + tmp2 + " = ";
		k = k1 / k2;

	}
}

int main()
{
	string str1, str2;
	//cin >> str1 >> str2;
	str1 = "5/3";
	str2 = "0/6";
	long a = stoi(str1);
	long b = stoi(str1.substr(str1.find('/') + 1));
	long c = stoi(str2);
	long d = stoi(str2.substr(str2.find('/') + 1));
	oper(a, b, c, d);
	system("pause");
	return 0;
}
/*
Joe, Kewell, Leon
Joe
"Letendre, Bruce", Joe, "Quan, William"
William

int main()
{
	string str, str2;
	while (getline(cin, str) && getline(cin, str2))
	{
		vector<string> a;
		int pre_pos = 0;
		int pos = 0;
		string target1, target2;
		target1 += '"';
		target2 += ',';
		while (1)
		{
			if (str[pos] == target1[0])
			{
				pre_pos = ++pos;
				if ((pos = str.find_first_of(target1, pos)) != string::npos)
				{
					a.push_back(str.substr(pre_pos, pos - pre_pos));
					pos += 2;
					pre_pos = pos;
				}
				if (pos >= str.size())
					break;
			}
			else
			{
				if ((pos = str.find_first_of(target2, pos)) != string::npos)
				{
					a.push_back(str.substr(pre_pos, pos - pre_pos));
					pre_pos = ++pos;
				}
				else
					break;
			}
		}
		if (pre_pos < str.size())
		{
				a.push_back(str.substr(pre_pos, str.size() - pre_pos));
		}
		int flag = 0;
		for (int i = 0; i < a.size(); ++i)
		{
			if (str2.size() == a[i].size() && str2 == a[i])
				flag == 1;
		}
		if (flag == 1)
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	
	system("pause");
	return 0;
}
/*
int main()
{
	string str;
	getline(cin, str);
	vector<double> a;
	int n = stoi(str);
	for (int i = 0; i < str.size(); i++)
	{
		if (i == 0 || str[i - 1] == ' ')
		{
			string substr = str.substr(i);
			a.push_back(stoi(substr));
		}
	}

	
	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] == 1)
			cout << "0.00%" << endl;
		else if (a[i] == 2)
			cout << "50.00%" << endl;
		else
		{
			double p = 50;
			int k = 3;
			while (k <= a[i])
			{
				p = (a[i] - 1) / a[i] * p;
				k++;
			}
			string s = to_string(p);
			if (s.size() != 5)
				s.resize(5);
			s += "%";
			cout << s << endl;
		}
	}

	system("pause");
	return 0;
}

*/