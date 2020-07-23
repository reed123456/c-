#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string str;
	//getline(cin, str);
	str = "asdfasdfo";
	int flag1 = 0;
	int buf[256] = { 0 };
	for (int i = 0; i < str.size(); ++i)
	{
		
		int flag = -1;
		char c = str[i];
		if (buf[str[i]] == 1)
		{
			continue;
		}
		for (int j = 0; j < str.size(); ++j)
		{
			if (j != i && c == str[j])
			{
				
				flag = 0;
				break;
			}
		}
		if (flag == -1)
		{
			cout << str[i] << endl;
			break;
		}
		buf[str[i]] = 1;
	}
	
	system("pause"); 
	return 0;
}

/*
int main()
{
	int ATK, n;
	while (cin >> n >> ATK)
	{
		vector<int> DEF;
		DEF.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> DEF[i];

		for (int i = 0; i < n; ++i)
		{
			if (ATK > DEF[i])
				ATK += DEF[i];
			else
			{
				int tmp1 = ATK;
				int tmp2 = DEF[i];
				while ((tmp1 %= tmp2) && (tmp2 %= tmp1));
				ATK += tmp1 + tmp2;
			}
		}
		cout << ATK << endl;
	}
	
	system("pause");
	return 0;
}

*/