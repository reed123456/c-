#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

int main()
{
	string str1 = "They are students.";
	string str2 = "aeiou";
//	getline(cin, str1);     //read to end-of-line
//	getline(cin, str2);//read to peraid


	string::iterator it1 = str1.begin();
	string::iterator it2 = str2.begin();
	string::iterator tmp_it = str1.begin();
	while (it2 != str2.end())
	{
		int pos;
		while ((pos = str1.find_first_of(*it2, 0)) != string::npos)
		{
			str1.erase(it1 + pos);
		}
		it2++;
	}
	cout << str1 << endl;
	system("pause");
	return 0;
}

/*
int main()
{
	int n, x;
	scanf("%d", &n);
	list<int> il;
	for (int i = 0; i < 3 * n; ++i)
	{
		scanf("%d", &x);
		il.push_back(x);
	}
	int max = 0;
	il.sort();
	vector<int> iv (il.begin(), il.end());
	for (int i = n; i < 3 * n; i = i + 2)
	{
		max += iv[i];
	}
	cout << max << endl;
	system("pause");
	return 0;
}
*/