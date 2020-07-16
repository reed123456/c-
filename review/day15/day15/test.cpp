#include <vector>
#include <iostream>
using namespace std;

int findMinimum(int n, vector<int> left, vector<int> right) {
	// write code here
	int countL = 0, countR = 0;
	int sumL0 = 0, sumR0 = 0;
	int maxL = 0, maxR = 0;
	for (int i = 0; i < n; ++i)
	{
		countL += left[i];
		maxL = maxL > left[i] ? maxL : left[i];
		if (left[i] == 0)
		{
			sumL0 += right[i];
		}

		countR += right[i];
		maxR = maxR > right[i] ? maxR : right[i];
		if (right[i] == 0 && left[i] != 0)
		if (right[i] == 0)
		{
			sumR0 += left[i];
		}
	}
	int count1 = countR - maxR + 1 + sumR0 + 1;
	int count2 = countL - maxL + 1 + sumL0 + 1;

	if (count1 > count2)
		return count2;
	else
		return count1;
}

int main()
{
	vector<int> left{ 0, 7, 2, 1, 6 };
	vector<int> right{ 1, 5, 0, 0, 6 };
	int n = 5;
	int count = findMinimum(n, left, right);
	cout << count << endl;
	system("pause");
	return 0;
}

/*
int findNumberOf1(int num)
{
	int flag = 0;
	if (num < 0)
		flag = 1;
	int count1 = 0;
	while (num)
	{
		count1++;
		num &= num - 1;
	}
	return count1 + flag;
}
int main()
{
	int n;
	int count1 = 0;
	cin >> n;

	cout << findNumberOf1(n) << endl;
	system("pause");
	return 0;
}
*/