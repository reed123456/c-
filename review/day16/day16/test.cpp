#include <stdbool.h>
using namespace std;
#include <stdio.h>

void main(void)
{
	char buff[256];
	short s[] = { 0, 1, 0, 1 };
	bool b[] = { false, true, false, true };
	sprintf(buff, "%c",b, 40);
	printf("%s", b);
	//system("pause");
}

/*
string maxPoker(string poker1, string poker2)
{
	//有大小王，大小王最大
	if ((poker1[0] == 'r' && poker1[poker1.size() - 1] == 'R') ||
		(poker2[0] == 'r' && poker2[poker2.size() - 1] == 'R'))
		return string("joker JOKER");

	//除过大小王后炸弹最大
	if (poker1.size() == 7 || poker2.size() == 7)
	{
		if (poker1.size() == 7 && poker2.size() == 7)
		{
			if (poker1[0] > poker2[0])
				return poker1;
			return poker2;
		}
		if (poker1.size() == 7)
			return poker1;
		return poker2;
	}
	//牌类型相同，第一张大者大
	if (poker1.size() == poker2.size())
	{
		if (poker1[0] > poker2[0])
		{
			if (poker1[0] == 'r')
				return string("joker");
			if (poker1[0] == 'R')
				return string("JOKER");
			return poker1;
		}
			
		if (poker2[0] == 'r')
			return string("joker");
		if (poker2[0] == 'R')
			return string("JOKER");
		return poker2;
	}
	
	//其他情况
	return string("ERROR");
}

int main()
{
	string str;
	string poker1, poker2;
	getline(cin, str);
	int pos = str.find('-');
	poker1 = str.substr(0, pos);
	poker2 = str.substr(pos + 1, str.size() - 1);
	if (poker1 == "joker")
		poker1 = "r";
	if (poker1 == "JOKER")
		poker1 = "R";
	if (poker1 == "joker JOKER")
		poker1 = "r R";

	if (poker2 == "joker")
		poker2 = "r";
	if (poker2 == "JOKER")
		poker2 = "R";
	if (poker2 == "joker JOKER")
		poker2 = "r R";
	cout << maxPoker(poker1, poker2) << endl;
	system("pause");
	return 0;
}



/*#include <iostream>
#include <string>
using namespace std;

string maxPoker(string poker1, string poker2)
{
	//有大小王，大小王最大
	if ((poker1[0] == 'j' && poker1[poker1.size() - 1] == 'R') || 
		(poker2[0] == 'j' && poker2[poker2.size() - 1] == 'R'))
		return string("joker JOKER");
	//牌类型相同，第一张大者大
	if (poker1.size() == poker2.size() && poker1[0] != 'j' || poker)
	{
		if (poker1[0] > poker2[0])
			return poker1;
		return poker2;
	}
	//排类型不同，除过大小王后炸弹最大
	if (poker1.size() == 7 || poker2.size() == 7)
	{
		if (poker1.size() == 7)
			return poker1;
		return poker2;
	}
	//单张与任意类型比较
	if (poker1.size() == 1 || poker2.size() == 1)
	{
		if (poker1.size() == 1 && poker2[poker2.size() - 1] > poker1[0])
			return poker2;
		if (poker2.size() == 1 && poker1[poker2.size() - 1] > poker2[0])
			return poker2;
		return string("ERROR");
	}
	//对子与三张比较
	if (poker1.size() * poker2.size() == 6)
	{
		if (poker1.size() == 2 && poker2[0] > poker1[0])
			return poker2;
		if (poker2.size() == 2 && poker1[0] > poker2[0])
			return poker2;
		return string("ERROR");
	}
	//其他情况
	return string("ERROR");
}

int main()
{
	string str;
	string poker1, poker2;
	getline(cin, str);
	int pos = str.find('-');
	poker1 = str.substr(0, pos);
	poker2 = str.substr(pos + 1, str.size() - 1);
	if (poker1 == "joker")
		poker1 = "r";
	if (poker1 == "JOKER")
		poker1 = "R";
	if (poker1 == "joker JOKER")
		poker1 = "r R";

	if (poker2 == "joker")
		poker2 = "r";
	if (poker2 == "JOKER")
		poker2 = "R";
	if (poker2 == "joker JOKER")
		poker2 = "r R";
	cout << maxPoker(poker1, poker2) << endl;
	system("pause");
	return 0;
}

/*
int count(int n)
{
	int count = 0;
	for (int i = 2; i <= n; ++i)
	{
		int sum = 1;
		for (int j = 2; j <= sqrt(i); ++j)
		{
			if (i % j == 0)
			{
				if (i /j != j)
					sum += i / j + j;
				else
					sum += j;
			}	
			if (sum > i)
				break;
		}
		if (sum == i)
			count++;
	}
	return count;
}

int main()
{
	int n = 1000;
	//cin >> n;
	cout << count(n) << endl;
	system("pause");
	return 0;
}

*/