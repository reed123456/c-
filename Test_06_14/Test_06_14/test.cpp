#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

void main()
{
	stack<char> S;
	char x, y;
	x = 'n'; 
	y = 'g';
	S.push(x); 
	S.push('i'); 
	S.push(y);
	S.pop(); 
	S.push('r'); 
	S.push('t'); 
	S.push(x);
	S.pop(); 
	S.push('s');

	while (!S.empty())
	{
		x = S.top();
		S.pop();
		cout << x;
	}
	cout << y;
	system("pause");
}
/*

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	// 使用正向迭代器正向list中的元素
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";

	cout << endl;
	// 使用反向迭代器逆向打印list中的元素
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}
/*
int main()
{
	std::list<int> l1; // 构造空的l1
	std::list<int> l2(4, 100); // l2中放4个值为100的元素
	std::list<int> l3(l2.begin(), l2.end()); // 用l2的[begin(), end()）左闭右开的区间构造l3
	std::list<int> l4(l3); // 用l3拷贝构造l4
	// 以数组为迭代器区间构造l5
	int array[] = { 16, 2, 77, 29 };
	std::list<int> l5(array, array + sizeof(array) / sizeof(int));
	// 用迭代器方式打印l5中的元素
	for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
		std::cout << *it << " ";
	std::cout << endl;
	// C++11范围for的方式遍历
	for (auto& e : l5)
		std::cout << e << " ";
	std::cout << endl;
	return 0;
}
/*
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6 };
	auto it = v.begin();
	// 将有效元素个数增加到100个，多出的位置使用8填充，操作期间底层会扩容
	// v.resize(100, 8);
	// reserve的作用就是改变扩容大小但不改变有效元素个数，操作期间可能会引起底层容量改变
	// v.reserve(100);
	// 插入元素期间，可能会引起扩容，而导致原空间被释放
	// v.insert(v.begin(), 0);
	// v.push_back(8);
	// 给vector重新赋值，可能会引起底层容量改变
	v.assign(100, 8);
	
	出错原因：以上操作，都有可能会导致vector扩容，也就是说vector底层原理旧空间被释放掉，
	而在打印时，it还使用的是释放之间的旧空间，在对it迭代器操作时，实际操作的是一块已经被释放的
	空间，而引起代码运行时崩溃。
	解决方式：在以上操作完成之后，如果想要继续通过迭代器操作vector中的元素，只需给it重新
	赋值即可。
	
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}

/*
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// 使用find查找3所在位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	// 删除pos位置的数据，导致pos迭代器失效。
	v.erase(pos);
	cout << *pos << endl; // 此处会导致非法访问
	return 0;
}
/*
int main()
{
	vector<int> v1;//创空的的整形向量
	vector<int> v2(4, 100);//
	std::vector<int> v3(v2.begin(), v2.end()); //通过迭代器构造
	std::vector<int> v4(v3); //拷贝v3
}
/*
int main(void)
{
	vector<int>array;
	array.push_back(100);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(500);
	vector<int>::iterator itor;

	for (itor = array.begin(); itor != array.end(); itor++)
	{
		if (*itor == 300)
		{
			itor = array.erase(itor);
		}
	}

	for (itor = array.begin(); itor != array.end(); itor++)
	{
		cout << *itor << " ";
	}
	system("pause");
	return 0;
}
*/
/*
int main()
{
	vector<int> nums{ 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5 };
	vector<int>::iterator pre_it = nums.begin();
	vector<int>::iterator it = nums.begin();
	it++;
	while (it != nums.end())
	{
		if (*pre_it == *it)
		{
			it = nums.erase(it);
		}
		else
		{
			pre_it = it;
			it++;
		}
		
	}
	for (auto & e : nums)
		cout << e << " ";

	cout << endl;
	system("pause");
	return 0;
}
/*
int main()
{
	int numRows = 10;
	vector<vector<int>> YHar(numRows);
	for (int i = 0; i < numRows; ++i)
	{
		YHar[i].push_back(1);
		for (int j = 1; j < i && i > 1; j++)
		{
			YHar[i].push_back(YHar[i - 1][j - 1] + YHar[i - 1][j]);
		}
		YHar[i].push_back(1);
	}
	YHar[0].pop_back();
	for (auto e : YHar)
	{
		for (auto a : e)
		{
			cout << a << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
*/