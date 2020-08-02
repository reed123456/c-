#include <iostream>
#include <string>
#include <vector>
using namespace std;

void swap(double a, double b)
{
	double tmp = a;
	a = b;
	b = a;
}

bool is2To24(double a, double b)
{
	if (a + b == 24 || a - b == 24 || b - a == 24 || a * b == 24 
		|| (b != 0 && a / b == 24)  || (a != 0 && b / a == 24))
		return true;
	return false;
}

bool is3To24(double a, double b, double c)
{
	for (int i = 0; i < 3; ++i)
	{
		if (is2To24(a + b, c) || is2To24(a - b, c) || is2To24(b - a, c) || is2To24(a * b, c)||
			(b != 0 && is2To24(a / b, c)) || (a != 0 && is2To24(b / a, c)))
			return true;
		if (i == 0)
			swap(a, b);
		if (i == 1)
			swap(a, c);
	}
	return false;
}

bool isTo24(int a, int b, int c, int d)
{
	for (int i = 0; i < 5; ++i)
	{
		if (is3To24(a + b, c, d) || is3To24(a + c, b, d) || is3To24(a + d, b, c) ||
			is3To24(a - b, c, d) || is3To24(a - c, b, d) || is3To24(a - d, b, c) ||
			is3To24(b - a, c, d) || is3To24(c - a, b, d) || is3To24(d - a, b, c) ||
			is3To24(a * b, c, d) || is3To24(a * c, b, d) || is3To24(a * d, b, c) ||
			(a != 0 && (is3To24(b / a, c, d) || is3To24(c / a, b, d) || is3To24(d / a, b, c)))||
			(b != 0 && is3To24(a / b, c, d)) || (c != 0 && is3To24(a / c, b, d)) || 
			(d != 0 && is3To24(a / d, b, c)))
			return true;
		if (i == 2)
			swap(a, d);
		else if (i == 3)
			swap(a, c);
		else
			swap(b, c);
	}
	return false;

}

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (isTo24(a, b, c, d) == 1)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	system("pause");
	return 0;
}

/*
int main()
{
	vector<int> a;
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int sum = a[0];
	int max = a[0];
	for (int i = 1; i < a.size(); ++i)
	{
		if (sum < 0)
			sum = 0;
		sum += a[i];
		max = max > sum ? max : sum;
	}
	cout << max << endl;
	system("pause");
	return 0;
}

/*
int main()
{
	string str1, str2;
	str1 = "They are students.";
	str2 = "aeiou";
	//getline(cin, str1);
	//getline(cin, str2);
	int buf[256] = { 0 };
	for (int i = 0; i < str2.size(); ++i)
	{
		buf[str2[i]] = 1;
	}
	int i = 0, j = 0;
	while (i < str1.size())
	{
		if (buf[str1[i]] == 1)
		{
			i++;
		}
		else
		{
			str1[j] = str1[i];
			i++;
			j++;
		}
	}
	str1.resize(j);
	cout << str1 << endl;
	system("pause");
	return 0;
}

/*
int main()
{
	int n;
	while (std::cin >> n) {
		if (n == 0) break;
		long total = pow(5, n) - 4;
		long left = pow(4, n) + n - 4;
		std::cout << total << " " << left << std::endl;
	}
	return 0;
}
/*
#include <iostream>
using namespace std;
int main(){
	double n, r;
	while (cin >> n >> r){
		//周长：2*r*3.1415
		//身长：n
		if (n > (2 * r*3.1415))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//基姆拉尔森计算公式算法
//算法如下：
//基姆拉尔森计算公式
//W = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) mod 7
//在公式中d表示日期中的日数，m表示月份数，y表示年数。
//注意：在公式中有个与其他公式不同的地方：
//把一月和二月看成是上一年的十三月和十四月，例：如果是2004 - 1 - 10则换算成：2003 - 13 - 10来代入公式计算。
int getDayOfWeek(int year, int month, int day)
{
	int y = year;
	int m = month;
	if (month == 1 || month == 2)
	{
		y = year - 1;
		m = month + 12;
	}
	int w = (day + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7 + 1;
	int week = w;
	return week;
}

int main()
{
	int year;
	cin >> year;
	vector<string> a(8);
	for (auto &e : a)
	{
		e += to_string(year);
	}
	a[0] += "-01-01";
	a[1] += "-01-";
	a[2] += "-02-";
	a[3] += "-05-";
	a[4] += "-07-04";
	a[5] += "-09-";
	a[6] += "-11-";
	a[7] += "12-25";
	for (int i = 0; i <= 29; ++i)
	{
		if (getDayOfWeek(year, 2, i) == 1)
		{
			a[1] += to_string(i + 14);
			break;
		}
	}
	for (int i = 0; i <= 31; ++i)
	{
		if (getDayOfWeek(year, 3, i) == 1)
		{
			a[2] += to_string(i + 7 + 7);
			break;
		}
	}
	for (int i = 31; i > 0; --i)
	{
		if (getDayOfWeek(year, 5, i) == 1)
		{
			a[3] += to_string(i);
			break;
		}
	}
	for (int i = 1; i < 30; ++i)
	{
		if (getDayOfWeek(year, 9, i) == 1)
		{
			a[5] += to_string(i);
			break;
		}
	}
	for (int i = 1; i < 30; ++i)
	{
		if (getDayOfWeek(year, 9, i) == 4)
		{
			a[6] += to_string(i+21);
			break;
		}
	}
	for (auto &e : a)
		cout << e << endl;
	system("pause");
}
/*
int main()
{
	vector<int> a;
	for (int i = 2; i < 1000000; ++i)
	{
		int flag = 1;
		for (int j = 2; j <= sqrt(i); ++j)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			a.push_back(i);
	}
	int n;
	while (cin >> n)
	{
		vector<int> b;
		b.push_back(n);
		for (int i = 0; i < a.size(); ++i)
		{
			while (n % a[i] == 0)
			{
				n /= a[i];
				b.push_back(a[i]);
				if (n == 1)
					break;
			}
			if (n == 1)
				break;
		}
		cout << b[0] << " = " << b[1];
		for (int i = 2; i < b.size(); ++i)
		{
			cout << " * " << b[i];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}*/