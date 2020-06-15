#include <iostream>
#include <queue>
#include <stack>
#include <functional>
using namespace std;

int main()
{
	
	// 将数组中的元素先放入优先级队列中
	priority_queue<int> p(nums.begin(), nums.end());
	// 将优先级队列中前k-1个元素删除掉
	for (int i = 0; i < k - 1; ++i)
	{
		p.pop();
	}
	system("pause");
	return 0;
}

/*
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};

template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1 & _d1;
	const T2 & _d2;
};

int main()
{
	Data<double, int> d1; // 调用特化的int版本  "Data<T1, int>"
	Data<int, double> d2; // 调用基础的模板  "Data<T1, T2>"
	Data<int *, int*> d3; // 调用特化的指针版本
	Data<int&, int&> d4(1, 2);//"Data<T1&, T2&>"
	system("pause");
	return 0;

}

/*
template<typename Type>
Type Max(const Type &a, const Type &b)
{
	cout << "This is Max<Type>" << endl;
	return a > b ? a : b;
}

template<>
int Max<int>(const int &a, const int &b)

{
	cout << "This is Max<int>" << endl;
	return a > b ? a : b;
}

template<>
char Max<char>(const char &a, const char &b)
{
	cout << "This is Max<char>" << endl;
	return a > b ? a : b;
}

int Max(const int &a, const int &b)
{
	cout << "This is Max" << endl;
	return a > b ? a : b;
}

int main()
{
	Max(10, 20);//10max
	Max(12.34, 23.45);//,type.
	Max('A', 'B');//char
	Max<int>(20, 30);//int
	system("pause");
	return 0;
}

/*
int main()
{
	priority_queue<int> a;

	priority_queue<int, vector<int>, greater<int> > c;
	priority_queue<string> b;

	for (int i = 0; i < 5; i++)
	{
		a.push(i);
		c.push(i);
	}

	while (!a.empty())
	{
		cout << a.top() << ' ';
		a.pop();
	}
	cout << endl;

	while (!c.empty())
	{
		cout << c.top() << ' ';
		c.pop();
	}
	cout << endl;

	b.push("abc");
	b.push("abcd");
	b.push("cbd");

	while (!b.empty())
	{
		cout << b.top() << ' ';
		b.pop();
	}
	cout << endl;
	system("pause");
	return 0;
}

/*
int mian()
{	
	//                1
	//	     2               3
	//	4        5       6        7
	queue.push(tree.root)

		while (true)
			node = queue.pop()
			output(node.value)//输出节点对应数字
			if (null == node)
				break
			for (child_node in node.children)
				queue.push(child_node)

	system("pause");
	return 0;
}
*/