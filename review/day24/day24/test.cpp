#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> a;
	a.resize(n);
	for (auto &e : a)
		e.resize(n);
	for (auto &e : a)
	{
		for (auto &x : e)
			cin >> x;
	}

	vector<pair<int, int>> b;
	goOut
	system("pause");
	return 0;
}
/*
int main()
{
	vector<vector<int>> a = { 
							{  1,  2,  3,  4,  5,  6 },
							{  7,  8,  9, 10, 11, 12 },
							{ 13, 14, 15, 16, 17, 18 },
							{ 19, 20, 21, 22, 23, 24 },
							{ 25, 26, 27, 28, 29, 30 },
							{ 31, 32, 33, 34, 35, 36 } };
	vector<vector<int>> b;
	b.resize(6);
	for (auto &e : b)
		e.resize(6);
	b[0][0] = a[0][0];
	for (int k = 1; k < 6; k++)
	{
		b[k][0] = b[k - 1][0] + a[k][0];
		b[0][k] = b[0][k - 1] + a[0][k];
		for (int i = k - 1, j = 1; j < k && i > 0; i--, j++)
		{
			b[i][j] = b[i - 1][j] > b[i][j - 1] ? b[i - 1][j] + a[i][j] : b[i][j - 1] + a[i][j];
		}
	}
	for (int k = 1; k < 6; k++)
	{
		for (int i = 5, j = k; j <= 5  && i >= k; i--, j++)
		{
			b[i][j] = b[i - 1][j] > b[i][j - 1] ? b[i - 1][j] + a[i][j] : b[i][j - 1] + a[i][j];
		}
	}
	for (auto &e : b)
	{
		for (auto &x : e)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
*/