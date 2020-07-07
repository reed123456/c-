#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
	int a[] = { 1, 2, 3, 4 };
	int *b = a;
	*b += 2;
	*(b + 2) = 2;
	b++;
	printf("%d, %d\n", *b, *(b + 2));
	system("pause");
	return 0;
}

/*
int main()
{
	vector<string> iv = { "i", "love", "leetcode", "i", "love", "coding" };
	map<string, int> mp;
	for (const auto &e : iv)
	{
		mp[e]++;
	}
	sort(mp.begin(), mp.end(),
		[](const pair<string, int>& a,
		const pair<string, int>&b)->bool
	{
		if (a.second == b.second)return a.first < b.first;
		else return a.second < b.second;

	});
	for (const auto &e : mp)
	{
		cout << e.first << " : " << e.second << endl;
	}
	system("pause");
	return 0;
}

int main()
{
	vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
	int k = words.size();
	if (words.empty() || k == 0)return{};
	map<string, int> record_1;//单词->该单词出现的个数
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
		cout << "“" << e <<"”,";
	}
	system("pause");
	return 0;
}
/*
int main()
{
	vector<string> iv = { "i", "love", "leetcode", "i", "love", "coding" };
	map<string, int> mp;
	for (const auto &e : iv)
	{
		mp[e]++;
	}
	sort(mp.begin(), mp.end(), 
		[](const pair<string, int>& a,
		const pair<string, int>&b)->bool
		{
				if (a.second == b.second)return a.first < b.first;
				else return a.second < b.second;

		});
	for (const auto &e : mp)
	{
		cout << e.first << " : " << e.second << endl;
	}
	system("pause");
	return 0;
}


/*
#include <iostream>
using namespace std;

int main()
{
	int N = 3;
	//cin >> N;
	int Fib = 0;
	int a = 0;
	int b = 1;
	int min = 0;
	while (b < N)
	{
		Fib = a + b;
		a = Fib + b;
		b = Fib + a;
		if (Fib >= N)
		{
			min = (N - (a - Fib)) < (Fib - N) ? (N - (a - Fib)) : (Fib - N);
			break;
		}
		if (a >= N)
		{

			min = (N - Fib) < (a - N) ? (N - Fib) : (a - N);
			break;
		}
		if (b >= N)
		{
			min = (Fib - a) < (b - Fib) ? (Fib - a) : (b - Fib);
			break;
		}
	}

	cout << min << endl;
	system("pause");
	return 0;
}

/*
#include <iostream>
using namespace std;

int main()
{
	int N = 60000;
	//cin >> N;
	int Fib = 0;
	int a = 0;
	int b = 1;
	
	while (b < N)
	{
		Fib = a + b;
		a = Fib + b;
		b = Fib + a;
	}
	int feet = (N - Fib) > 0 ? (N - Fib) : (Fib - N);
	int pre = (a - Fib) > 0 ? (a - Fib) : 0;
	int pre_feet = N - pre;
	int feeta = (feet - a) > 0 ? (feet - a) : (a - feet);
	int feetb = b - feet;

	feet = feet < a ? feet : a;
	feet = feet < b ? feet : b;
	feet = feet < pre_feet ? feet : pre_feet;

	cout << feet << endl;
	system("pause");
	return 0;
}

/*
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool chkParenthesis(string A, int n) {
	// write code here
	if (A.empty())
		return true;
	stack<char> is;
	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] != '(' && A[i] != ')')
			return false;

		if (A[i] == '(')
			is.push('(');
		else if (!is.empty() && A[i] == ')')
			is.pop();
		else
			return false;
	}
	return true;
}

int main()
{
	string str = "(()())";
	cout << chkParenthesis(str, str.size()) << endl;
	system("pause");
	return 0;
}

*/