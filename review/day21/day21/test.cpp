#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool fun(int n){
	int sum = 0;
	for (int i = 1; n>sum; i = i + 2)
		sum = sum + i;
	return (n == sum);
}

int main()
{
	cout << fun(484) << endl;
	system("pause");
	return 0;
}

/*
int main()
{
	string str, sRet;
	str = "3 3 1 1 2 3 4 5 6 3 2 1 2 3 4 5 6 2 2 1 1 1 1";
						"1 4 2 5 3 6 1 5 4 3 2 6 1 1 1 1";
	//getline(cin, str);
	for (int i = str.size() - 1, j = i / 2; j > 0; i -= 2, j -= 2)
	{
		sRet += str[i];
		sRet += str[j];
	}
	cout << str << endl;
	cout << sRet << endl;
	system("pause");
	return 0;
}

/*
vector<int> show(int n, string str)
{
	int top, end, cur;
	vector<int> a;
	a.resize(5);
	if (n <= 4)
	{
		for (int i = 0; i < n; ++i)
			a[i] = i + 1;
		cur = 1;
		for (int j = 0; j < str.size(); ++j)
		{
			if (str[j] = 'U')
			{
				if ((cur--) == 0)
					cur = n;
			}
			else
			{
				if ((cur++) == n)
					cur = 1;
			}
		}
		a[4] = cur;
		return a;
	}
	
	cur = top = 1;
	end = 4;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'U')
		{
			if (cur == top)
			{
				if (top != 1)
				{
					cur--;
					top--;
					end--;
				}
				else
				{
					cur = end = n;
					top = n - 3;
				}
			}
			else
			{
				cur--;
			}
		}
		else if (str[i] == 'D')
		{
			if (cur == end)
			{
				if (end != n)
				{
					cur++;
					top++;
					end++;
				}
				else
				{
					cur = top = 1;
					end = top + 3;
				}
			}
			else
			{
				cur++;
			}
		}
	}
	for (int i = 0; i < 4; i++)
		a[i] = top + i;
	a[4] = cur;
	return a;
}

int main()
{
	int n;
	string str;
	n = 10;
	str = "UUUU";
	//cin >> n >> str;
	vector<int> vRet = show(n, str);
	for (int i = 0; i < 4; i++)
	{
		if (vRet[i] == 0)
			break;
		if (i != 0)
			cout << " ";
		cout << vRet[i];
	}
	cout << endl << vRet[4] << endl;
	system("pause");
	return 0;
}
/*
int main()
{
	string str, sRet;
	str = "3 3 1 1 2 3 4 5 6 3 2 1 2 3 4 5 6 2 2 1 1 1 1";
	//getline(cin, str);
	for (int i = str.size() - 1, j = i / 2; j > 0; i -= 2, j -= 2)
	{
		sRet += str[i];
		sRet += str[j];
	}
	cout << str << endl;
	cout << sRet << endl;
	system("pause");
	return 0;
}


/*
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