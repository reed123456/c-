#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	int array[] = { 1, 2, 3, 4, 0, 5, 6, 7, 8, 9 };
	int n = sizeof(array) / sizeof(int);
	list<int> mylist(array, array + n);
	auto it = mylist.begin();
	while (it != mylist.end())
	{
		if (*it != 0)
			cout << *it << " ";
		else
			it = mylist.erase(it);
		++it;
	}
	system("pause");
	return 0;
}

/*
int main()
{
	int ar[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(ar) / sizeof(int);
	list<int> mylist(ar, ar + n);
	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);
	reverse(mylist.begin(), pos);
	reverse(pos, mylist.end());
	list<int>::const_reverse_iterator crit = mylist.crbegin();
	while (crit != mylist.crend())
	{
		cout << *crit << " ";
		++crit;
	}
	cout << endl;
}
/*
//删除重复项
﻿template<typename T>
void removeDuplicates(list<T> &aList)
{
	T curValue;
	list<T>::iterator cur, p;
	cur = aList.begin();
	while (cur != aList.end())
	{
		curValue = *cur;
		//空白行 1
		//p = ++cur;
		while (p != aList.end())
		{
			if (*p == curValue)
			{
				//空白行 2
				//aList.erase(p++);
			}
			else
			{
				p++;
			}
		}
	}
}
int main()
{

	system("pause");
	return 0;
}
/*
int main()
{
	string str1;
	string str2("adcxyz");
	string str3(10, '@');
	cout << "str1 = " << str1 << "   size = " << str1.size() << endl;
	cout << "str2 = " << str2 << "   size = " << str2.size() << endl;
	cout << "str3 = " << str3 << "   size = " << str3.size() << endl;
	system("pause");
	return 0;
}

/*
int fib(int n){
	int arr[45];
	int ret = 0;
	int a = 0;
	int b = 1;
	arr[0] = 0;
	arr[1] = 1;
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	while (n - 1 > 0)
	{
		ret = a + b;
		a = b;
		b = ret;
		
		n--;
		arr[45 - n + 1] = ret;
	}
	return ret;
}

int main()
{
	cout << "fib(45) = " << fib(45) << endl;
	system("pause");
	return 0;
}
*/