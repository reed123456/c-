#include <iostream>
#include <vector>
using namespace std;

#include<iostream>
#include<algorithm>
using namespace std;
//�ж�����
bool isPrime(int num)
{
	int tmp = sqrt(num);
	//ֻ�����������������ܱ�������ߵ�����������һ�����ܱ������ұߵ�������
	for (int i = 2; i <= tmp; i++)
	{
		if (num %i == 0)
			return false;
	}
	return true;
}
int main()
{
	int num;
	int half;
	int i;
	while (cin >> num)
	{
		half = num / 2;
		//���м���������
		for (i = half; i > 0; i--)
		{
			if (isPrime(i) && isPrime(num - i))
				break;
		}
		cout << i << endl << num - i << endl;
	}
	return 0;
}

/*
int main()
{
	vector<int> primeList;
	int n = 103;
	//cin >> n;

	for (int i = 0; i < n; i++)
	{
		int j = 0;;
		for (j = 2; j <= i / 2 ; j++)
		{
			if (i % j == 0)
				break;
		}
		if (j > i / 2)
			primeList.push_back(i);
	}
	int ar[2] = { 0, n };
	int sz = primeList.size();
	for (int i = 0; i < sz; ++i)
	{
		for (int j = 0; j < sz; ++j)
		{
			if (primeList[j] >= n)
			{
				sz = j;
				break;
			}
			if (primeList[i] + primeList[j] == n)
			{
				if ((primeList[j] - primeList[i]) < (ar[1] - ar[0]))
				{
					ar[0] = primeList[i];
					ar[1] = primeList[j];
				}
				sz = j;
				break;
			}
			
		}
	}
	cout << ar[0] << endl;
	cout << ar[1] << endl;
	system("pause");
	return 0;
}
/*
int main()
{
	int n = 1024;
	int m = 19;
	int j = 2;
	int i = 6;
	int k = i - j + 2;
	while (k < 32)
	{
		m &= ~(1 << k);
		k++;
	}
	k = j;
	int tmp = 0;
	while (k <= i)
	{
		tmp = (tmp << 1) + 1;
		k++;
	}
	n &= ~(tmp << j);
	n |= m << j;
	cout << n << endl;
	system("pause");
	return 0;
}
*/