#include <iostream>
#include <string>
#include <vector>
using namespace std;

int nthFaci(int n)
{
	unsigned int a = 1;
	unsigned int b = 1;
	unsigned int c = 2;
	while ((n -= 3) >= 0)
	{
		a = (b + c) % 1000000;
		b = (a + c) % 1000000;
		c = (a + b) % 1000000;
	}
	n += 3;
	if (n == 0)
		return a;
	if (n == 1)
		return b;
	if (n == 2)
		return c;
}

int main()
{
	vector<int> a;
	string str;
	getline(cin, str);
	string target = " ";
	int pre_pos = 0;
	int pos = 0;
	while ((pos = str.find_first_of(target, pos)) != string::npos)
	{
		a.push_back(stoi(str.substr(pre_pos, pos - pre_pos)));
		pre_pos = ++pos;
	}
	a.push_back(stoi(str.substr(pre_pos, str.size() - pre_pos)));

	for (int i = 0; i < a.size(); i++)
	{
		string str = to_string(nthFaci(a[i]));
		cout << str << endl;
		/*if (str.size() < 7)
			cout << str << endl;
		else
			cout << str.substr(str.size() - 6, 6) << endl;*/
	}
	
	system("pause");
	return 0;
}