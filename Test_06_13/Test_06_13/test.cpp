#include <iostream>
#include <string>
#include <vector>
using namespace std;

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