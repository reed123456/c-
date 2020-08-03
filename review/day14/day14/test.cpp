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
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> a;
	int n;
	int count1 = 0;
	int count = 0, sum = 0, mul = 1;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] == 1)
			count1++;
		sum += a[i];
		mul *= a[i];
	}
	
	sort(a.begin(), a.end());
	for (int i = n - 1; i >= 0; --i)
	{
		if (mul / sum >= 1);
	}
	system("pause");
	return 0;
}

/*
#include <iostream>
using namespace std;

int getOutDay(int year, int month, int day)
{
	int moth[] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int nDay = 0;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		int tmp = moth[2];
		moth[2] = moth[0];
		moth[0] = tmp;
	}
	if (month < 1 || month > 12 || day < 1 || day > moth[month])
		return -1;
	for (int i = 1; i < month; i++)
	{
		nDay += moth[i];
	}
	nDay += day;
	return nDay;
}
int main()
{
	int year, month, day;
	cin >> year >> month >> day;
	cout << getOutDay(year, month, day) << endl;
	system("pause");
	return 0;
}
*/