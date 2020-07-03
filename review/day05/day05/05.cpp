#include <iostream>
#include <vector>
using namespace std;

int continueMaxSum(vector<int> array1)
{
	int array[] = {2,3,2,1};
	int pre_num = array[0];
	int max = array[0];
	int sum = array[0];
	int flag = 0;
	for (int i = 1; i < array1.size(); i++)
	{
		if (array[i] < 0)
		{
			sum = sum > array[i] ? sum : array[i];
			max = max > sum ? max : sum;
			flag = 0;
		}
		if (array[i] == pre_num)
		{
			sum += array[i];
		}
		else if (flag > -1 && array[i] - pre_num == 1)
		{
			sum += array[i];
			flag = 1;
		}
		else if (flag < 1 && array[i] - pre_num == -1)
		{
			sum += array[i];
			flag = -1;
		}
		else
		{
			max = max > sum ? max : sum;
			sum = 0;
			flag = 0;
			if (i + 1 < array1.size() &&
				(array[i + 1] - array[i] == 1 || array[i + 1] - array[i] == -1))
			{
				pre_num = array[i];
				i--;			
			}
			else
			{
				if (i + 1 < array1.size())
					pre_num = array[i+1];
			}
		}

	}
	return max;
}
int main()
{
	/*
	int n;
	scanf("%d", &n);
	vector<int> iv;
	for (int i = 0; i < n; ++i)
	{
	int x = scanf("%d", &x);
	iv.push_back(x);
	}*/
	vector<int> iv{-1, 0, 1, 2, 1 };
	cout << continueMaxSum(iv) << endl;
	system("pause");
	return 0;
}