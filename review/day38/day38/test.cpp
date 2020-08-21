#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		set<string> s;
		while (n--)
		{
			int flag = 1;
			string str;
			getline(cin, str);
			if (s.size() == 0)
				s.insert(str);
			else
			{
				for (auto &e : s)
				{
					if (e == str.substr(0, e.size()))
					{
						s.erase(e);
						s.insert(str);
						flag = 0;
						break;
					}
					if (str == e.substr(0, str.size()))
					{
						flag = 0;
						break;
					}
				}
				if (flag == 1)
					s.insert(str);
			}
		}

		for (auto &e : s)
			cout<< "mkdir - p " << e << endl;
		cout << endl;
	}
	
	system("pause");
	return 0;
}

/*
int main()
{
	set<string> s;
	int n;
	string str1, str2, str3;
	getline(cin, str1);
	getline(cin, str2);
	getline(cin, str3);
	if (str1.size() > str2.size())
		swap(str1, str2);
	if (str1.size() < str3.size())
	{
		if (str2.size() > str3.size())
			swap(str1, str2);
	}
	else
	{
		swap(str1, str2);
		swap(str1, str3);
	}
	if (str1 == str2.substr(0, str1.size()) && str2 == str3.substr(0, str2.size()))
		s.insert("mkdir - p" + str3);
	else if (str1 == str2.substr(0, str1.size()) || str1 == str2.substr(0, str1.size()))
	{
		s.insert("mkdir - p " + str2);
		s.insert("mkdir - p " + str3);
	}
	else if (str2 == str3.substr(0, str1.size()))
	{
		s.insert("mkdir - p " + str1);
		s.insert("mkdir - p " + str3);
	}
	else
	{
		s.insert("mkdir - p " + str1);
		s.insert("mkdir - p " + str2);
		s.insert("mkdir - p " + str3);
	}
	for (auto &e : s)
		cout << e << endl;
	cout << endl;
	system("pause");
	return 0;
}

/*
3
/ a
/ a / b
/ a / b / c
3
/ usr / local / bin
/ usr / bin
/ usr / local / share / bin
/*
int main()
{
	int arr[26] = { 0 };
	int max_sz = 0, cur_sz = 0, free_sz = 0;
	int n;
	cin >> n;
	while (n--)
	{
		char ch;
		string str;
		cin >> ch >> str;
		if (str == "connect")
		{
			arr[ch - 'A']++;
			if (free_sz != 0)
				free_sz--;
			cur_sz++;
		}
		else if (str == "disconnect")
		{
			if (arr[ch - 'A'] >= 0)
			{
				arr[ch - 'A']--;
				cur_sz--;
				free_sz++;
			}
		}
		max_sz = max_sz > cur_sz ? max_sz : cur_sz;
	}
	cout << max_sz << endl;
	system("pause");
	return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
	set<char> s;
	int max_sz = 0, cur_sz = 0;
	int n;
	
	cin >> n;
	while (n--)
	{
		char ch;
		string str;
		cin >> ch >> str;
		if (str[0] == 'd')
		{
			s.erase(ch);
			cur_sz--;
		}
		else
		{
			s.insert(ch);
			cur_sz++;
		}
		max_sz = max_sz > cur_sz ? max_sz : cur_sz;
	}
	cout << max_sz << endl;
	system("pause");
	return 0;
}

*/