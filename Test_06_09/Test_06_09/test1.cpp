#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
	public:
		string reverseWords(string s) {
			string target = " ";
			auto begin = s.begin();
			int pre_pos = 0;
			int pos = 0;
			while ((pos = s.find_first_of(target, pos)) != string::npos)
			{
				reverse(begin+pre_pos, begin+pos);
				pre_pos = ++pos;
			}

			reverse(begin+pre_pos, s.end());

			return s;
		}
};
}

/*
class Solution {
public:
	bool isLetterOrNumber(char ch)
	{
		return (ch >= '0' && ch <= '9')
			|| (ch >= 'a' && ch <= 'z')
			|| (ch >= 'A' && ch <= 'Z');
	}
	bool isPalindrome(string s) {
		// 先小写字母转换成大写，再进行判断
		for (auto& ch : s)
		{
			if (ch >= 'a' && ch <= 'z')
				ch -= 32;
		}
		int begin = 0, end = s.size() - 1;
		while (begin < end)
		{
			while (begin < end && !isLetterOrNumber(s[begin]))
				++begin;
			while (begin < end && !isLetterOrNumber(s[end]))
				--end;
			if (s[begin] != s[end])
			{
				return false;
			}
			else
			{
				++begin;
				--end;
			}
		}
		return true;
	}
};

/*
class Solution {
public:
	void reverseString(vector<char>& s)
	{
		if (s.empty())
			return;

		int start = 0;
		int end = s.size() - 1;

		while (start < end)
		{
			swap(s[start], s[end]);
			start++;
			end--;
		}
	}
};

/*
class Solution {
public:
	int StrToInt(string str)
	{
		int len = str.size();
		int flag = 1;
		if (len == 0)
			return 0;

		const char *cstr = str.c_str();
		if (cstr == NULL)
			return 0;

		int i = 0;
		if (cstr[i] == '+')
		{
			i++;
			flag = 1;  
		}
		else if (cstr[i] == '-')
		{
			i++;
			flag = -1;  
		}
		long long num = 0;

		while (cstr[i] != '\0')
		{
			if (cstr[i] >= '0' && cstr[i] <= '9')
			{      
				num = num * 10 + (cstr[i] - '0'); 
				if ((flag>0 && num>0x7fffffff) || (flag<0 && num>0x80000000))
					return 0;
				i++;
			}else{
				return 0;
			}
		}
		if (flag < 0)
			num = num * -1;

		return (int)num;
	}
};

/*
class Solution
{
public:
	void MulItem(string &tmp, string &num1, char a)
	{
		int i = 0, sign = 0;
		int mul = 0;
		while (i < num1.size())
		{
			mul = (num1[i] - '0') * (a - '0') + sign;
			if (mul >= 10)
			{
				sign = mul / 10;
				mul %= 10;
			}
			else
				sign = 0;

			tmp.push_back(mul + '0');
			i++;
		}
		if (sign > 0)
			tmp.push_back(sign + '0');
	}

	//对应为相加，sign进位采用引用传递
	int AddItem(int a, int b, int &sign)
	{
		int add = a + b + sign;
		if (add >= 10)
		{
			sign = 1;
			add -= 10;
		}
		else
			sign = 0;
		return add;
	}

	//错位相加
	void MoveAdd(string &result, string &tmp, int k)
	{
		int i, j;
		i = k;
		j = 0;
		int sign = 0;

		while (i<result.size() && j<tmp.size())
		{
			result[i] = AddItem(result[i] - '0', tmp[j] - '0', sign) + '0';
			i++;
			j++;
		}

		while (i<result.size() && sign)
		{
			result[i] = AddItem(result[i] - '0', 0, sign) + '0';
			i++;
		}
		while (j < tmp.size())
		{
			int v = AddItem(0, tmp[j] - '0', sign);
			result.push_back(v + '0');
			j++;
		}
		if (sign)

			result.push_back(sign + '0');
	}

	string multiply(string num1, string num2)
	{
		//先翻转数据，方便进位处理
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		string tmp, result;
		for (int i = 0; i<num2.size(); ++i)
		{
			//使用num2的每一个数据乘以num1
			MulItem(tmp, num1, num2[i]);
			//将乘得的结果进行错位相加
			MoveAdd(result, tmp, i);
			tmp.clear();
		}

		while (result.size() != 1 && result.back() == '0')
			result.pop_back();

		//翻转数据，恢复数据
		reverse(result.begin(), result.end());
		return result;
	}
};


/*
string multiply(string num1, string num2) {
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int i = 0;
	int j = 0;
	int sign = 0;
	int sum;
	string res;

	while (i < num1.size() && j < num2.size())
	{
		sum = num1[i] - '0' + num2[j] - '0' + sign;
		res += (sum % 10) + '0';
		sign = sum / 10;
		i++;
		j++;
	}

	while (i < num1.size())
	{
		sum = num1[i] - '0' + sign;
		res += (sum % 10) + '0';
		sign = sum / 10;
		i++;
	}

	while (j < num2.size())
	{
		sum = num2[j] - '0' + sign;
		res += (sum % 10) + '0';
		sign = sum / 10;
		j++;
	}

	if (sign > 0)
		res += sign + '0';

	reverse(res.begin(), res.end());

	return res;
}

int main()
{
	string str1 = "2";
	string str2 = "3";
	
	int a = atoi(str1.c_str());
	int b = atoi(str2.c_str());

	int res = a * b;
	char str[100];
	sprintf(str, "%d", res);
	system("pause");
	return 0;
}



/*
int firstUniqChar(string s) {
	// 统计每个字符出现的次数
	int count[256] = { 0 };
	int size = s.size();
	for (int i = 0; i < size; ++i)
		count[s[i]] += 1;
	// 按照字符次序从前往后找只出现一次的字符
	for (int i = 0; i < size; ++i)
	if (1 == count[s[i]])
		return i;
	return -1;
}


int main()
{
	string str;
	getline(cin, str);
	if (firstUniqChar(str) != -1)
		cout << str[firstUniqChar(str)] << endl;
	else
		cout << -1 << endl;
	system("pause");
	return 0;
}
*/