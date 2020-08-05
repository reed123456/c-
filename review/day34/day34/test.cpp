#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	int from, to;
	//cin >> from >> to;
	from = 1;
	to = 80;
	vector<unsigned long long> a;
	a.resize(to + 1);
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i <= to; ++i)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	cout << accumulate(a.begin() + from, a.end(), 0) << endl;

	system("pause");
	return 0;
}

/*
int main()
{

	string str, target;
	str = "a3aa3a";
	target = "a3";
	//cin >> str >> target;
	int count = 0;
	for (int i = 0; i < str.size();)
	{
		int flag = 1;
		for (int j = 0; j < target.size(); ++j)
		{
			if (i + j >= str.size() || str[i + j] != target[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			i += target.size();
			count++;
		}
		else
			++i;
	}
	cout << count << endl;
	system("pause");
	return 0;
}
*/