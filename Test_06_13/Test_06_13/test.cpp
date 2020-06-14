#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> nums{ 1, 1, 2 };
	auto it = nums.begin();
	vector<int>::iterator pre_it = it;

	while (it != nums.end())
	{
		if (pre_it == it)
		{
			pre_it = it;
			++it;
		}
		else if (*pre_it == *it)
			it = it.
	}

	system("pause");
	return 0;
}

/*
int main()
{
	vector<int> nums{1,2,1,3,2,5};
	//int flag = 0;
	int k = 0;
	int a;
	int b;
	int c;
	vector<int> ar(2);
	for (int i = 0; i < nums.size(); ++i)
	{
		int flag = 0;
		for (int j = 0; j < nums.size(); ++j)
		{
			if ((a = nums[i]) == (b = nums[j]) && i != j)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			c = nums[i];
			ar[k++] = c;
		}
		if (k == 2)
			break;
	}

	system("pause");
	return 0;
}
/*
int main()
{
	string digits = { "5678" };
	//digits.empty();
	string alph[][4] = { "a", "b", "c", "",//2
						"d", "e", "f", "",//3
						"g", "h", "i", "",//4
						"j", "k", "l", "",//5
						"m", "n", "o", "",//6
						"p", "q", "r", "s",//7
						"t", "u", "v", "",//8
						"w", "x", "y", "z" };//9
	int sz = 1;
	for (int i = 0; i < digits.size(); ++i)
	{
		if (digits[i]- '0' == 7 || digits[i] - '0' == 9)
			sz *= 4;
		else
			sz *= 3;
	}
	vector<string>  str(sz);
	int feet = sz;
	int k = 0;
	int flag;

	
	for (int i = 0; i < digits.size(); i++)
	{
		if (digits[i] - '0'== 7 || digits[i] - '0' == 9)
		{
			feet = feet / 4;
			flag = 4;
		}
		else
		{
			feet = feet / 3;
			flag = 3;
		}

		for (int j = 0; j < str.size(); ++j)
		{
			k = j / feet % flag;
			str[j].append(alph[digits[i] - '2'][k]);
		}
		
	}
	
	for (const auto &e : str)
		cout << e << ", ";

	cout << endl;
	system("pause");
	return 0;
}

/*
{ "a", "b", "c",
"d", "e", "f",
"g", "h", "i",
"j", "k", "l",
"m", "n", "o",
"p", "q", "r","s",
"t", "u", "v",
"w", "x", "y", "z" };
*/