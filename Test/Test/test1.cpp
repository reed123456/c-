#include <iostream>
using namespace std;

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	Time(const Time &t)
	{
		hours = t.hours;
		minutes = t.minutes;
	}
	~Time();
	Time& operator=(const Time & t) 
	{
		if (this != &t)
		{
			hours = t.hours;
			minutes = t.minutes;
		}
		return *this;
	}
	Time operator+(const Time & t) const;
	Time operator-(const Time & t) const;

	Time* operator&()
	{
		return this;
	}
	const Time* operator&()const
	{
		return this;
	}
};

int main()
{
	cout << "Hello World." << endl;
	system("pause");
	return 0;
}