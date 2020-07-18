#include <iostream>
#include <string>
using namespace std;

string isSamelike(string str1, string str2)
{
	if (str1.size() == 0 || str2.size() == 0)
		return string("false");
	for (int i = 0, j = 0; i < str1.size() && j < str2.size(); ++i, ++j)
	{
		if (str1[i] == str2[j] || str1[i] == '?')
 			continue;
		else if (str1[i] == '*')
		{
			if (i + 1 == str1.size())
				return string("true");
			++i;
			while (str1[i] != str2[j])
			{
				j++;
				if (j == str2.size())
					return string("false");
			}
		}
		else
			return string("false");
	}
}

int main()
{
	string str1, str2;
	str1 = "t?t*.d*";
	str2 = "txt12.xls";
	//getline(cin, str1);
	//getline(cin, str2);
	cout << isSamelike(str1, str2) << endl;
	system("pause");
	return 0;
}

/*
int countRubbit(int n)
{
	if (n == 1 || n == 2)
		return 1;
	int a = 1;
	int b = 1;
	int count;
	while (n-- > 2)
	{
		count = a + b;
		a = b;
		b = count;
	}
	return count;
}

int main()
{
	int n;
	while (cin >> n)
		cout << countRubbit(n) << endl;
	system("pause");
}
*/