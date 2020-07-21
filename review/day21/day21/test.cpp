#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;



char * fun()
{
	char p[] = "safs";
	char *a = p;
	return p;
}
int main()
{
	char *a;
	a = fun();
	printf(a);
}
/*
#include <iostream>
#include <string>
using namespace std;

bool match(const char* pattern, const char *str)
{
	//当前字符结束，返回true
	if (*pattern == '\0' && *str == '\0')
		return true;
	//两个字符串有一个先结束，则返回false
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?')
	{
		//遇到?号，匹配一个字符，跳过一个位置
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*')
	{
		// 遇到*号，匹配0个(str不挪动)，1个（两者都向前挪动一个字符）或多个(str向前挪动一个字符)
			return match(pattern + 1, str) || match(pattern + 1, str + 1) ||
			match(pattern, str + 1);
	}
	else if (*pattern == *str)
	{
		//如果当前字符相等，匹配下一个字符
		return match(pattern + 1, str + 1);
	}
	return false;
}

int main()
{
	string pattern, str;
	while (cin >> pattern >> str)
	{
		bool ret = match(pattern.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxSubstr(string str1, string str2)
{
	string strRet = "";
	if (str1.size() > str2.size())
	{
		string tmp = str1;
		str1 = str2;
		str2 = tmp;
	}
	for (int i = 0; i < str1.size(); ++i)
	{
		string substr = "";
		int n = str1.size() - i;
		do
		{
			substr = str1.substr(i, n--);
			if (substr.size() <= strRet.size())
				n = 0;
		} while (str2.find(substr) == string::npos && n != 0);

		if (n != 0)
		{
			strRet = strRet.size() >= substr.size() ? strRet : substr;
		}
	}
	return strRet.size();
}

int main()
{
	string str1, str2;
	//getline(cin, str1);
	//getline(cin, str2);
	str1 = "asdfas";
	str2 = "werasdfaswer";
	cout << maxSubstr(str1, str2) << endl;
	system("pause");
	return 0;
}


/*
int main()
{
	string str;
	while (getline(cin, str))
	{
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	system("pause");
	return 0;
}

*/