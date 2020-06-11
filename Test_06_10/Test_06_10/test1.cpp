#include <iostream>
#include <string>
using namespace std;

int main()
{

	string name("Alice");
	string pres, veep, source, join;
	pres = name;
	veep = "hello summer.";
	source = 'X';
	join = name + source;

	string str1, str2;
	getline(cin, str1);     //read to end-of-line
	getline(cin, str2, '.');//read to peraid
	string who;
	cin >> who;

	string claim("The string class has many feature.");
	cout << claim << endl;
	string s1; // 构造空的string类对象s1
	string s2("hello bit"); // 用C格式字符串构造string类对象s2
	string s3(s2); // 拷贝构造s3
}

/*
string multiply(string num1, string num2) {
	string str = string(num1.size() + num2.size(), '0');
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	for (int i = 0, k = 0; i < num2.size(); ++i, k = i)
	{
		int sum = 0;
		int sign = 0;
		for (int j = 0; j < num1.size(); ++j, ++k)
		{
			sum = str[k] - '0' + (num2[i] - '0') * (num1[j] - '0') + sign;
			str[k] = (sum % 10) + '0';
			sign = sum / 10;
		}
		
		str[k] = sign + '0';
	}
	
	if (str.size() > 1 && str[str.size() - 1] == '0')
	{
		str.resize(str.size() - 1);
	}
	reverse(str.begin(), str.end());
	return str;
}

int main()
{
	string num1 = "0";
	string num2 = "0";
	cout << multiply(num1, num2) << endl;
	system("pause");
	return 0;
}
/*
int main()
{
	string str;
	while (getline(cin, str) && str.size() <= 20)
	{
		int exchange = 0;
		for (int i = 0; i < str.size() - 1; ++i)
		{
			for (int j = 0; j < str.size() - i - 1; j++)
			{
				if (str[i] - str[j] > 0)
				{
					exchange++;
					swap(str[i], str[j]);
				}
			}
			if (exchange == 0)
				break;
		}
		cout << str << endl;
	}
	return 0;
}
*/