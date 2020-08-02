#include<iostream>
using namespace std;
int pathNum(int n, int m)
{
	if (n > 1 && m > 1)
		//b������ݹ�
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1)))
		// a�������ֹ����
		return n + m;
	else
		//����Ϊ0ʱ�� ·��Ϊ0
		return 0;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << pathNum(n, m) << endl;
	}
	return 0;
}

/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<string> v;
	v.resize(n);
	for (auto& str : v)
		cin >> str;
	bool lenSym = true, lexSym = true;
	// ����Ҫע���i=1��ʼ������ǰ��Ƚϣ��Ƚϳ���
	for (size_t i = 1; i < v.size(); ++i)
	{
		if (v[i - 1].size() >= v[i].size())
		{
			lenSym = false;
			break;
		}
	}
	//�Ƚ�ASCII��
	for (size_t i = 1; i < v.size(); ++i)
	{
		if (v[i - 1] >= v[i])
		{
			lexSym = false;
			break;
		}
	}
	if (lenSym&& lexSym)
		cout << "both" << endl;
	else if (!lenSym && lexSym)
		cout << "lexicographically" << endl;
	else if (lenSym && !lexSym)
		cout << "lengths" << endl;
	else if (!lenSym&&!lexSym)
		cout << "none" << endl;
	return 0;
}

/*
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flag = false;
	// ����Ǹ�������ת�������������һ��
	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}
	// �����ƻ���ɶ�Ӧ���ַ���ӵ�s
	while (m)
	{
		s += table[m%n];
		m /= n;
	}
	if (flag)
		s += '-';
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}




/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	int flag1 = 0;
	int flag2 = 0;
	string str1, str2;
	cin >> n;
	cin.get();
	getline(cin, str1);
	while (--n)
	{
		getline(cin, str2);
		if (str1.size() > str2.size())
		{
			flag1 = 1;
		}
		if (str1 > str2)
		{
			flag2 = 1;
		}
		str1 = str2;
	}
	if (flag1 == 0 && flag2 == 0)
	{
		cout << "both" << endl;
	}
	else if (flag1 == 1 && flag2 == 0)
	{
		cout << "lexicographically" << endl;
	}
	else if (flag1 == 0 && flag2 == 1)
	{
		cout << "length" << endl;
	}
	else
	{
		cout << "none" << endl;
	}
	system("pause");
	return 0;
}
/*
#include <iostream>
using namespace std;

int main()
{
int A = 2, B = 6;
//cin >> A >> B;
int a = A;
int b = B;
while ((A %= B) && (B %= A));

cout << (a * b) / (A + B) << endl;
system("pause");
return 0;
}


int main()
{
	vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
	int k = words.size();
	if (words.empty() || k == 0)return{};
	map<string, int> record_1;//����->�õ��ʳ��ֵĸ���
	vector<string> result;
	for (const auto& word : words){
		record_1[word]++;
	}

	vector<pair<string, int>> record_2(record_1.begin(), record_1.end());
	sort(record_2.begin(), record_2.end(),
		[](const pair<string, int>& a, const pair<string, int>& b)
	{
		if (a.second == b.second)return a.first<b.first;
		else return a.second>b.second;
	}
	);
	for (const auto& r : record_2)
	{
		if (k-- == 0)break;
		result.push_back(r.first);
	}

	for (const auto &e : result)
	{
		cout << "��" << e << "��,";
	}
	system("pause");
	return 0;
}
*/