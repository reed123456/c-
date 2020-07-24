#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int callStringDistance(string charA, string charB)
{
	int count = 0;
	int i, j;
	for (i = 0, j = 0; i < charA.size() && j < charB.size(); ++i, ++j)
	{
		if (charA[i] == charB[j])
		{
			continue;
		}
		else if (charA[i + 1] == charB[j])
		{
			i++;
			count++;
		}
		else if (charA[i] == charB[j + 1])
		{
			j++;
			count++;
		}
	}
	if (i < charA.size())
		return count + charA.size() - i;
	else
		return count + charB.size() - j;
}

int main()
{
	string str1, str2;
	//getline(cin, str1);
	//getline(cin, str2);
	str1 = "abdcdefg";
	str2 = "abcdef";

	cout << callStringDistance(str1, str2) << endl;
	system("pause"); 
	return 0;
}

/*
int getValue(vector<int> gifts, int n) {
	// write code here
	sort(gifts.begin(), gifts.end());
	int pre = gifts[0];
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (gifts[i] == pre)
		{
			count++;
			if (count > n / 2)
				return gifts[i];
		}
		else
		{
			pre = gifts[i];
			count = 1;
		}
	}
	return 0;
}

int main()
{
	vector<int> a = { 1, 2, 3, 2, 2, 5 };
	int n = a.size() - 1;
	cout << getValue(a, n) << endl;
	system("pause");
	return 0;
}

*/