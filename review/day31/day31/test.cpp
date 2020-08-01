#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> a;
	for (int i = 2; i < 100000; ++i)
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
		int count = 0;
		for (int i = 0; i < a.size(); ++i)
		{
			while (n % a[i] == 0)
			{
				n /= a[i];
				count++;
				if (n == 1)
					break;
			}
			if (n == 1)
				break;
		}
		cout << count << endl;
	}
	
	system("pause");
	return 0;
}

/*
int main()
{
	string str;
	string dst = "VWXYZABCDEFGHIJKLMNOPQRSTU";
	while (getline(cin, str))
	{
		for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = dst[str[i] - 'A'];
	}
	cout << str << endl;
	}
	
	system("pause");
	return 0;
}
*/