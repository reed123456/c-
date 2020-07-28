#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int len, r;
	string str[3];
	for (int i = 0; i < 3; ++i)
	{
		cin >> len >> r;
		int pi = 3.14;
		if (len > 2 * pi * r)
			str[i] = "No";
		else
			str[i] = "Yes";
	}
	
	for (auto &e : str)
		cout << e << endl;
	system("pause");
	return 0;
}

/*
int jumpFloorII(int number) {
	vector<int> a;
	a.resize(number);
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i < number; i++)
	{
		for (int j = 0; j < i; j++)
		{
			a[i] += a[j];
		}
		a[i]++;
	}
	return a[a.size() - 1];
}

int main()
{
	int n; 
	//while (cin >> n)
	n = 6;
		cout << jumpFloorII(n) << endl;
	system("pause");
	return 0;
}
*/