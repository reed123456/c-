#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int w, h, res = 0;
	cin >> w >> h;
	vector<vector<int>> a;
	a.resize(w);
	for (auto& e : a)
		e.resize(h, 1);
	for (int i = 0; i<w; i++)
	{
		for (int j = 0; j<h; j++)
		{
			if (a[i][j] == 1)
			{
				res++;
				// 标记不能放蛋糕的位置
				if ((i + 2)<w)
					a[i + 2][j] = 0;
				if ((j + 2)<h)
					a[i][j + 2] = 0;
			}
		}
	}
	cout << res;
	return 0;
}
/*
#include <iostream>
#include<vector>
using namespace std;

#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int m = 0123, n = 123;
	printf("%o %o\n", m, n);
	return 0;
}
/*
int main()
{
	int size;
	cin >> size;
	vector<int> nums(size);
	for (size_t i = 0; i < size; ++i)
		cin >> nums[i];
	int result = nums[0];
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		// 计算到num[i]的子数组的最大和
		sum2 = sum1 >= 0 ? sum1 + nums[i] : nums[i];
		if (sum2 > result)
			result = sum2;
		if (sum2 < 0)
			sum2 = 0;
		sum1 = sum2;
	}
	cout << result << endl;
	return 0;
}
/*
#include<iostream>
#include<string>
using namespace std;
// 判断是否是回文
bool IsCircleText(const string& s)
{
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
			return false;
		++begin;
		--end;
	}
	return true;
}
int main()
{
	std::string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	size_t count = 0;
	for (size_t i = 0; i <= str1.size(); ++i)
	{
		// 将字符串2插入到字符串1的每个位置，再判断是否是回文
		string str = str1;
		str.insert(i, str2);
		if (IsCircleText(str))
			++count;
	}
	cout << count << endl;
	return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;

#include<iostream>
using namespace std;
class B0//基类BO声明
{
public://外部接口
	virtual void display()//虚成员函数
	{
		cout << "B0::display0" << endl;
	}
};
class B1 :public B0//公有派生
{
public:
	void display() { cout << "B1::display0" << endl; }
};
class D1 : public B1//公有派生
{
public:
	void display(){ cout << "D1::display0" << endl; }
};
void fun(B0 &ptr)//普通函数
{
	ptr.display();
}
int main()//主函数
{
	B0 b0;//声明基类对象和指针
	B1 b1;//声明派生类对象
	D1 d1;//声明派生类对象
	fun(b0);//调用基类B0函数成员
	fun(b1);//调用派生类B1函数成员
	fun(d1);//调用派生类D1函数成员

	system("pause");
}

/*
void main(){
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
	system("pause");
}
/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 1, m = 2;
	//cin >> n >> m;
	int nsum = 0;
	vector<int> a;
	a.resize(n + 1);
	for (int i = 0; i <= n; i++)
	{
		a[i] = 1;
	}
	for (int j = 0; j < m; j++)
	{
		a[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			int tmp = a[i];
			a[i] += a[i - 1];
		}
	}
	cout << a[n] << endl;
	system("pause");
}


/*#include <iostream>
using namespace std;

int main()
{
	int sum;
	int a = -6;
	int b = 12;
	int c = a & b;
	int d = a | b;
	while (c)
	{
		int tmp;
		d &= ~c;
		tmp = d;
		d |= (c<<1);
		c = (c<<1) & tmp;
	}
	cout << d << endl;
	system("pause");
	return 0;
}

*/