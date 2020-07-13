#include <iostream>
using namespace std;

int main()
{
	int a = 8;
	int b = 9;

	if (a > b)
	{
		int tmp = b;
		b = a;
		a = tmp;
	}
	int n = (a - (a % 2)) * 2;
	while (b >= n)
	{
		b /= 2;
	}
	while (a != b)
	{
		a /= 2;
		b /= 2;
	}

	cout << a << endl;
	system("pause");
	return 0;
}


/*#include <iostream>
using namespace std;

int main()
{
	int num = 23;
	//cin >> n;
	int count = 0;
	int count1 = 0;
	while (num)
	{
		if (num & 1)
		{
			count1++;
		}
		else{
			
			count = count1 > count ? count1 : count;
			count1 = 0;
		}
		num >>= 1;
	}
	count = count1 > count ? count1 : count;
	cout << count1 << endl;
	system("pause");
	return 0;
}



/*
#include <iostream>
using namespace std;

int main()
{
	int a = 4;
	int b = 11;

	if (a > b)
	{
		int tmp = b;
		b = a;
		a = tmp;
	}
	int n = 0;
	int num = 1;
	while (num < a)
	{
		n++;
		num <<= 1;
	}
	int m = n;
	num /= 2;
	while (num < b)
	{
		m++;
		num <<= 1;
	}
	b >>= m - n;
	a >>= (a - b + 1) / 2;

	cout << a << endl;
	system("pause");
	return 0;
}
*/