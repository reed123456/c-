#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{

	int a = 10; 
	double b = 3.14; 
	cout << 'A' + b + a << endl;
	int year = 2019;
	int *p = &year;
	*p += 1;
	cout << year << endl;
	//printf("%s , %6.3s\n", "computer", "computer");
	system("pause");
	return 0;
}
/*
int main()
{
	//string str = "abcqwerabc";
	string str;
	getline(cin, str);
	string str1;
	for (int i = 0; i < str.size(); i++)
	{
		if (str1.find(str[i]) == string::npos)
		{
			str1 += str[i];
		}
	}
	cout << str1 << endl;
	system("pause");
	return 0;
}

/*
int main()
{
	vector<int> A{ 6, 1, 2, 3, 4, 5 };
	int x = 3;
	int left = 0;
	int right = A.size() - 1;
	int mid = 0;
	while (left <= right)
	{
		if (A[left] == x)
		{
			mid = left;
			break;
		}
		else if (A[right] == x)
		{
			mid = right;
			break;
		}
		mid = (left + right) / 2;
		if (A[mid] <= x)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}

	}
	cout << mid << endl;
	system("pause");
	return 0;
}

/*
int main()
{
	string str;
	getline(cin, str);
	string str1;
	for (int i = 0; i < str.size(); i++)
	{
		if (str1.find(str[i]) == string::npos)
		{
			str1 += str[i];
		}
	}
	cout << str1 << endl;
	system("pause");
	return 0;
}
/*
int main()
{
	int h = 4, w = 4;
	//cin >> h >> w;
	
	int count;
	int arr[5][5] = { 0, 0, 0, 0, 0,
		0, 1, 2, 2, 2,
		0, 2, 4, 4, 4,
		0, 2, 4, 5, 6,
		0, 2, 4, 6, 8 };
	int h1 = h / 4;
	int h2 = h % 4;
	int w1 = w / 4;
	int w2 = w % 4;
	int a1 = h1 * w1 * arr[4][4];
	int a2 = arr[h2][4] * w1;
	int a3 = arr[w2][4] * h1;
	int a4 = arr[h2][w2];
	count = a1 + a2 + a3 + a4;
	cout << count << "    ";

	//		for (int h = 0; h <= 7; h++)
	//		{
	//			for (int w = 0; w <= 7; w++)
	//			{
	//	}
	//	cout << endl;
	//}
	
	system("pause");
	return 0;
}

/*
int StrToInt(string str) {
	if (str.size() == 0)
	{
		return 0;
	}
	int ret = 0;
	int flag = 1;
	int i = 0;
	while (str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-')
	{
		flag = -1;
		++i;
	}
	else if (str[i] == '+')
	{
		++i;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			ret = ret * 10 + str[i] - '0';
			++i;
		}
		else
		{
			return 0;
		}
	}
	return ret * flag;
}

int main()
{
	string str = "1www1";
	int ret = StrToInt(str);
	cout << ret << endl;
	system("pause");
	return 0;
}



*/