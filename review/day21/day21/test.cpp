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
	//��ǰ�ַ�����������true
	if (*pattern == '\0' && *str == '\0')
		return true;
	//�����ַ�����һ���Ƚ������򷵻�false
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?')
	{
		//����?�ţ�ƥ��һ���ַ�������һ��λ��
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*')
	{
		// ����*�ţ�ƥ��0��(str��Ų��)��1�������߶���ǰŲ��һ���ַ�������(str��ǰŲ��һ���ַ�)
			return match(pattern + 1, str) || match(pattern + 1, str + 1) ||
			match(pattern, str + 1);
	}
	else if (*pattern == *str)
	{
		//�����ǰ�ַ���ȣ�ƥ����һ���ַ�
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