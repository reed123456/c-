#include <iostream>
using namespace std;

int main() {
	int n = 0;
	//scanf����ֵΪ��ȷ�������ݵı�����������һ��������û�гɹ���ȡ����ʱ����ʱ����-1
	while (scanf("%d", &n) != -1) {
		if (n == 0) {
			break;
		}
		int count = 0;
		while (n > 1) {
			count += 1;
			//ÿ��ȡ1/3,�����������3�����������
			//ʣ��1�����ֳ� 1/3 ��1/3 ��1 + (1/3) ������1/3������ƽ���ˣ�
			//ʣ��2�����ֳ� 1/3 ��1 + (1/3) �� 1 + (1/3)������1 + (1/3)������ƽ����
			//������ĿҪ������ʱ�䣬�����������Ĵ��������ȡÿ��ʣ������ֵ 1 + (1/3)
			n = n / 3 + (n % 3 > 0);
		}
		printf("%d\n", count);
	}
	return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	vector<int> a;
	while (cin >> n && n != 0)
	{
		int count = 0;
		int sum = 1;
		while (sum < n)
		{
			count++;
			sum *= 3;
		}
		a.push_back(count);
	}
	for (auto &e : a)
		cout << e << endl;
	system("pause");
	return 0;
}

/*
bool isSum(vector<int> arr, int n, int pos)//�ݹ�
{
	for (int i = pos; i < arr.size(); ++i)
	{
		if (arr[i] == n)
			return true;
	}
	for (int i = pos; i < arr.size() - 1; ++i)
	{
		if (isSum(arr, n - arr[i], i+1))
			return true;
	}

	return false;
}

int getFirstUnFormedNum(vector<int> arr, int len) {
	sort(arr.begin(), arr.end());
	int Min = arr[0];
	int Max = accumulate(arr.begin(), arr.end(), 0);

	for (int i = Min + 1; i <= Max; ++i)
	{
		if (isSum(arr, i, 0) == false)
			return i;
	}
	return Max + 1;
}

int main()
{
	vector<int> a{ 3, 2, 5 };
	int sz = a.size() - 1;
	int min = getFirstUnFormedNum(a, sz);
	cout << min << endl;
	system("pause");
	return 0;
}
*/