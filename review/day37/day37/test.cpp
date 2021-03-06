#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <functional>
using namespace std;


int main()
{
	int n;
	while (std::cin >> n) //接收数字
	{
		std::cin.get(); //处理回车
		std::string name;
		for (int i = 0; i < n; i++) //名字分别处理
		{
			bool quote = false;
			getline(cin, name);
			if (name.find(',') != std::string::npos ||
				name.find(' ') != std::string::npos) //找到逗号或者空格，就要加双引号
			{
				quote = true;
			}
			if (quote)
			{
				putchar('\"'); //putchar效率更高
			}
			std::cout << name;
			if (quote)
			{
				putchar('\"');
			}
			if (i == n - 1) //如果已经是最后一个字符串，那就补回车，否则加逗号和空格
			{
				putchar('\n');
			}
			else
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	return 0;
}

/*
int main()
{
	// 找该区间中前4个最小的元素, 元素最终存储在v1的前4个位置
	vector<int> v1{ 4, 1, 8, 0, 5, 9, 3, 7, 2, 6 };
	partial_sort(v1.begin(), v1.begin() + 4, v1.end());
	for (auto &e : v1)
		cout << e << " ";
	cout << endl;
	// 找该区间中前4个最大的元素, 元素最终存储在v1的前4个位置
	vector<int> v2{ 4, 1, 8, 0, 5, 9, 3, 7, 2, 6 };
	partial_sort(v2.begin(), v2.begin() + 4, v2.end(), greater<int>());
	for (auto &e : v2)
		cout << e << " ";
	cout << endl;
	system("pause");
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct S1
{
	char c1;//1 + 3
	int i;//4
	int arr[10];
	char c2;//1 + 3
};


int main()
{
	cout << sizeof(struct S1) << endl;
	//cout << sizeof(struct S2) << endl;
	system("pause");
	return 0;
}

/*
#include <string>
#include <map>
void main()
{
	map<string, string> m;
	// 向map中插入元素的方式：
	// 将键值对<"peach","桃子">插入map中，用pair直接来构造键值对
	m.insert(pair<string, string>("peach", "桃子"));
	// 将键值对<"peach","桃子">插入map中，用make_pair函数来构造键值对
	m.insert(make_pair("banan", "香蕉"));
	// 将<"apple", "">插入map中，插入成功，返回value的引用，将“苹果”赋值给该引用结果，
	m["apple"] = "苹果";
	// key不存在时抛异常
	//m.at("waterme") = "水蜜桃";
	cout << m.size() << endl;
	// 用迭代器去遍历map中的元素，可以得到一个按照key排序的序列
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;
	// map中的键值对key一定是唯一的，如果key存在将插入失败
	auto ret = m.insert(make_pair("peach", "桃色"));
	if (ret.second)
		cout << "<peach, 桃色>不在map中, 已经插入" << endl;
	else
		cout << "键值为peach的元素已经存在：" << ret.first->first << "--->" <<
		ret.first->second << " 插入失败" << endl;
	// 删除key为"apple"的元素
	m.erase("apple");
	if (1 == m.count("apple"))
		cout << "apple还在" << endl;
	else
		cout << "apple被吃了" << endl;
	system("pause");
}

/*
void main()
{
	// 用数组array中的元素构造set
	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	set<int> s(array, array + sizeof(array) / sizeof(array[0]));
	cout << s.size() << endl;
	// 正向打印set中的元素，从打印结果中可以看出：set可去重
	for (auto& e : s)
		cout << e << " ";
	cout << endl;
	// 使用迭代器逆向打印set中的元素
	for (auto it = s.rbegin(); it != s.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	// set中值为3的元素出现了几次
	cout << s.count(3) << endl;
	system("pause");
}
*/ 