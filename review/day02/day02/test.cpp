#include <iostream>
#include <string>
using namespace std;

void reverse_str(string &str)
{
	string target = " ";
	int pos = 0;
	int pre_pos = 0;
	int left = 0;
	int right = str.size() - 1;
	
	while (str[left] == ' ')
		left++;
	while (left < right)
	{
		char temp = str[left];
		str[left] = str[right];
		str[right] = temp;
		left++;
		right--;
	}
	while ((pos = str.find_first_of(target, pos)) != string::npos)
	{
		left = pre_pos;
		right = pos - 1;
		while (left < right)
		{
			char temp = str[left];
			str[left] = str[right];
			str[right] = temp;
			left++;
			right--;
		}
		pos = pos + 1;
		pre_pos = pos;
	}
	left = pre_pos;
	right = str.size() - 1;
	while (left < right)
	{
		char temp = str[left];
		str[left] = str[right];
		str[right] = temp;
		left++;
		right--;
	}
	
}
int main()
{
	string str = "il like beijing";
	cout << str << endl;
	//getline(cin, str);
	reverse_str(str);
	cout << str << endl;
	system("pause");
	return 0;
}

/*
void reverse_str(string &str)
{
	string target = " ";
	int pos = 0;
	int pre_pos = 0;
	auto it = str.begin();
	while ((pos = str.find_first_of(target, pos)) != string::npos)
	{
		reverse(it + pre_pos, it + pos);
		
		pos = pos + 1;	
		pre_pos = pos;
	}
	reverse(it + pre_pos, str.end());
}
int main()
{
	string str;
	getline(cin, str);
	reverse_str(str);
	cout << str << endl;
	system("pause");
	return 0;
}
/*
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> iv;
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		iv.push_back(x);
	}
	int count = 0;
	int num = iv[0];
	int flag = 0;
	for (int i = 0; i < n; ++i)
	{
		if (flag == 0 && iv[i] == num)
		{
			continue;
		}
		else if (flag < 1 && iv[i] < num)
		{
			flag = -1;
		}
		else if(flag > -1 && iv[i] > num)
		{
			flag = 1;
		}
		else
		{
			count++;
			flag = 0;
		}
		num = iv[i];
	}
	count++;
	cout << count << endl;

	system("pause");
	return 0;
}
*/