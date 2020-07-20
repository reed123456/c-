#include<iostream>
#include<algorithm>
using namespace std;
/*
getLuckyPacket:从当前位置开始搜索符合要求的组合，一直搜索到最后一个位置结束
x[]: 袋子中的所有球
n:  球的总数
pos: 当前搜索的位置
sum: 到目前位置的累加和
multi: 到目前位置的累积值
*/
int getLuckyPacket(int x[], int n, int pos, int sum, int multi)
{
	int count = 0;
	//循环，搜索以位置i开始所有可能的组合
	for (int i = pos; i<n; i++)
	{
		sum += x[i];
		multi *= x[i];
		if (sum > multi)
		{
			//找到符合要求的组合，加1，继续累加后续的值，看是否有符合要求的集合
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1)
		{
			//如何不符合要求，且当前元素值为1，则继续向后搜索
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else
		{
			//如何sum大于multi,则后面就没有符合要求的组合了
			break;
		}
		//要搜索下一个位置之前，首先恢复sum和multi
		sum -= x[i];
		multi /= x[i];
		//数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过
		while (i < n - 1 && x[i] == x[i + 1])
		{
			i++;
		}
	}
	return count;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int x[n];
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x, x + n);
		//从第一个位置开始搜索
		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	}
	return 0;
}


/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char str[] = "glad to test something";
	char *p = str;
	p++;
	int *p1 = reinterpret_cast<int *>(p);
	p1++;
	p = reinterpret_cast<char *>(p1);
	printf("result is %s\n", p);
	/*char dog[] = "wang\0miao";
	cout << "sizeof(dog) = " << sizeof(dog) << endl;
	cout << "strlen(dog) = " << strlen(dog) << endl;*/
 	system("pause");
	return 0;
}

/*
string isSamelike(string str1, string str2)
{
	if (str1.size() == 0 || str2.size() == 0)
		return string("false");
	for (int i = 0, j = 0; i < str1.size() && j < str2.size(); ++i, ++j)
	{
		if (str1[i] == str2[j] || str1[i] == '?')
 			continue;
		else if (str1[i] == '*')
		{
			if (i + 1 == str1.size())
				return string("true");
			++i;
			while (str1[i] != str2[j])
			{
				j++;
				if (j == str2.size())
					return string("false");
			}
		}
		else
			return string("false");
	}
}

int main()
{
	string str1, str2;
	str1 = "t?t*.d*";
	str2 = "txt12.xls";
	//getline(cin, str1);
	//getline(cin, str2);
	cout << isSamelike(str1, str2) << endl;
	system("pause");
	return 0;
}

/*
int countRubbit(int n)
{
	if (n == 1 || n == 2)
		return 1;
	int a = 1;
	int b = 1;
	int count;
	while (n-- > 2)
	{
		count = a + b;
		a = b;
		b = count;
	}
	return count;
}

int main()
{
	int n;
	while (cin >> n)
		cout << countRubbit(n) << endl;
	system("pause");
}
*/