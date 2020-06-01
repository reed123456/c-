#include <iostream>
using namespace std;


class Date
{
	friend ostream& operator<<(ostream &os,const Date &t);
public:
	Date(int year = 0, int month = 0, int day = 0)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}

	Date& operator-(int day)
	{
		int month[13] = { -29, -31, -28, -31, -30, -31, -30, -31, -31, -30, -31, -30, -31 };
		m_day += day;
		if (((m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0)))
		{
			int tmp = month[0];
			month[0] = month[2];
			month[2] = tmp;
		}
		while (month[(m_month - 1 + 12) % 13] > m_day )
		{
			m_day -= month[m_month];
			m_month--;
			if (m_month < 1)
			{
				--m_year;
				m_month = 12;

				if (((m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0)))
				{
					int tmp = month[0];
					month[0] = month[2];
					month[2] = tmp;
				}
			}
		}

		if (--m_month == 0)
		{
			m_month = 12;
			m_year--;
		}
		m_day -= month[m_month];

		return *this;
	}

	Date& operator+(int day)
	{
		m_day += day;
		if (m_day  <= 0)
			return (*this) - day;
		int month[13] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		
		if (((m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0)))
		{
			int tmp = month[0];
			month[0] = month[2];
			month[2] = tmp;
		}
		while (m_day > month[m_month])
		{
			m_day -= month[m_month];
			m_month++;
			if (m_month > 12)
			{
				++m_year;
				m_month = 1;

				if (((m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0)))
				{
					int tmp = month[0];
					month[0] = month[2];
					month[2] = tmp;
				}
			}
		}

		return *this;
	}
private:
	int m_year;
	int m_month;
	int m_day;
};

ostream& operator<<(ostream &os,const Date &t)
{
	os << t.m_year << "-";
	if (t.m_month < 10)
		os << "0" << t.m_month;
	else
		os << t.m_month;
		
	if (t.m_day < 10)
		os << "-" << "0" << t.m_day << endl;
	else
		os << "-" << t.m_day << endl;
	return os;
}

int main()
{
	int key, year, month, day, d, i = 0;
	cin >> key;
	Date *D = new Date[key];
	while (key > 0)
	{
		cin >> year >> month >> day >> d;
		Date tmp(year, month, day);
		D[i++] = tmp + d;
		key--;
	}
	for (int j = 0; j < i; ++j)
	{
		cout << D[j] << endl;
	}
	system("pause");
	delete []D;
	return 0;
}
/*
class A
{
public:
	A(int a)
		:_a1(a)
		, _a2(_a1)
	{}
	void Print()
	{
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a2;
	int _a1;
};

int main()
{
	A aa(1);
	aa.Print();
	return 0;
}
*/