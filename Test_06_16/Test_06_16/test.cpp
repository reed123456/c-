#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
	stack<int> s;
	for (size_t i = 0; i < tokens.size(); ++i)
	{
		string& str = tokens[i];
		// str为数字
		if (!("+" == str || "-" == str || "*" == str || "/" == str))
		{
			s.push(atoi(str.c_str()));
		}
		else
		{
			// str为操作符
			int right = s.top();
			s.pop();
			int left = s.top();
			s.pop();
			switch (str[0])
			{
			case '+':
				s.push(left + right);
				break;
			case '-':
				s.push(left - right);
				break;
			case '*':
				s.push(left * right);
				break;
			case '/':
				// 题目说明了不存在除数为0的情况
				s.push(left / right);
				break;
			}
		}
	}
	return s.top();
}


int main()
{
	vector<string> str = { "2", "1", "+", "3", "*" };
	int res = evalRPN(str);
	system("pause");
	return 0;
}

/*
bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	int flag = 0;
	vector<int> tmpV;
	vector<int> tmp_pushV = pushV;
	vector<int> tmp_popV = popV;
	reverse(tmp_popV.begin(), tmp_popV.end());
	while (!tmp_popV.empty())
	{
		if (!tmp_pushV.empty() && tmp_pushV.back() == tmp_popV.back())
		{
			tmp_pushV.pop_back();
			tmp_popV.pop_back();
		}
		else if (flag == 0 && !tmpV.empty() && tmpV.front() == tmp_popV.back())
		{
			tmp_popV.pop_back();
			while (!tmpV.empty())
			{
				if (tmpV.size() == 1)
				{
					tmpV.pop_back();
					break;
				}
				tmp_pushV.push_back(tmpV.back());
				tmpV.pop_back();
			}

			flag = 1;
		}
		else if (flag == 0 && !tmpV.empty() && tmpV.back() == tmp_popV.back())
		{
			tmpV.pop_back();
			tmp_popV.pop_back();
		}
		
		else if (flag == 0 && !tmp_pushV.empty())
		{
			tmpV.push_back(tmp_pushV.back());
			tmp_pushV.pop_back();
		}
		else
			return false;
	}
	return true;
}

int main()
{
	vector<int> pushV{ 1, 2, 3, 4, 5 };
	vector<int> popV{ 4,3,5,1,2};
	cout << IsPopOrder(pushV, popV) << endl;
	
	system("pause");
	return 0;
}
*/