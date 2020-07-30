#include <iostream>
#include <string>
#include <vector>
using namespace std;

void BigInt::Add(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
	int i, flag = 0;
	for (i = 1; i < bt1.size() && i < bt1.size(); i++)
	{
		int sum = btl[i] - '0'  + bt2[i] - '0' + flag;
		bt.push_back((sum % 10) + '0');
		flag = sum / 10;
	}
	if (i < bt1.size())
	{
		for (; i < bt1.size(); i++)
		{
			int sum = btl[i] - '0' + flag;
			flag = sum / 10;
			bt.push_back((sum % 10) + '0');
		}
	}
	else
	{
		for (; i < bt2.size(); i++)
		{
			int sum = bt2[i] - '0' + flag;
			flag = sum / 10;
			bt.push_back((sum % 10) + '0');
		}
	}
	if (flag > 0)
	{
		bt.push_back(flag + '0');
	}
}


/*
int main()
{

}

/*
void oddInOddEvenInEven(vector<int>& arr, int len) {
	int i, j;
	for (i = 0, j = 1; i < len && j < len; )
	{
		if (arr[i] % 2 == 0)
		{
			i += 2;
			if (arr[j] % 2 == 1)
			{
				j += 2;
			}
		}
		else
		{
			if (arr[j] % 2 == 1)
			{
				j += 2;
			}
			else
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				j += 2;
				i += 2;
			}
		}
	}

}

int main()
{
	vector<int> a{ 1, 2, 3, 4, 5, 6};
	oddInOddEvenInEven(a, 5);
	for (auto &e : a)
		cout << e << " ";
	cout << endl;
	system("pause");
	return 0;
}
*/