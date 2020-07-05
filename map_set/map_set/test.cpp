#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
using namespace std;

void main()
{
	map<string, string> m;

	// 将键值对<"peach","桃子">插入map中，用pair直接来构造键值对
	m.insert(pair<string, string>("peach", "桃子"));
	// 将键值对<"peach","桃子">插入map中，用make_pair函数来构造键值对
	m.insert(make_pair("banan", "香蕉"));
	// 借用operator[]向map中插入元素
	m["apple"] = "苹果";

	cout << m.size() << endl;
	// 用迭代器去遍历map中的元素，可以得到一个按照key排序的序列
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;

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
	set<int> is = { 4, 8, 9, 5, 0, 2, 5, 5, 5, 5, 5, 1, 5, 5, 5, 7 };
	cout << "is size = " << is.size() << endl;
	multiset<int> multi_is = { 4, 8, 9, 5, 0, 2, 5, 5, 5, 5, 5, 1, 5, 5, 5, 7 };
	cout << "multi_is size = " << multi_is.size() << endl;
	system("pause");
}

/*
void main()
{
	map<int, string> ismap =
		{ { 1, "Student" }, { 3, "Teacher" }, { 4, "Bit" }, { 2, "Friend" },
		{ 1, "Stu" }, { 3, "Teacher" }, { 4, "Bit" }, { 2, "Friend" } };
	cout << "ismap :\n";
	for (auto &e : ismap)
		cout << e.first << " : " << e.second << endl;
	multimap<int, string> multi_ismap =
		{ { 1, "Student" }, { 3, "Teacher" }, { 4, "Bit" }, { 2, "Friend" },
		{ 1, "Stu" }, { 3, "Teacher" }, { 4, "Bit" }, { 2, "Friend" } };
	cout << "multi_ismap :\n";
	for (auto &e : multi_ismap)
		cout << e.first << " : " << e.second << endl;
	system("pause");
}
/*

/*
void main()
{
	map<int, string> ismap = { { 1, "Student" }, { 3, "Teacher" },
								{ 4, "Bit" }, { 2, "Friend" } };
	ismap[5] = "Alice";
	for (auto &e : ismap)
		cout << e.first << " : " << e.second << endl;

	system("pause");
}

/*
void main()
{
	int ar[] = { 4, 8, 9, 0, 2, 5, 1, 7 };
	int n = sizeof(ar) / sizeof(ar[0]);
	set<int> is;

	set<int> is_1(ar, ar + n);
	for (auto &e : is_1)
		cout << e << " ";
	cout << endl;
	vector<int> iv = { 4, 8, 9, 0, 2, 5, 1, 7 };
	set<int> is_2(iv.begin(), iv.end());
	for (auto &e : is_2)
		cout << e << " ";
	cout << endl;
	set<int> is_3 = is_2; //拷贝构造函数
	for (auto &e : is_3)
		cout << e << " ";
	cout << endl;
	system("pause");
}

/*
void main()
{
	set<int, greater<int>> is = { 4, 8, 9, 0, 2, 5, 1, 7 };
	
	auto it = is.begin();

	is.insert(10);

	while (it != is.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	system("pause");
}

/*
void main()
{
	vector<int> iv = { 4, 8, 9, 0, 2, 5, 1, 7 };
	set<int> is;
	for (int e : iv)
		is.insert(e);

	for (auto &e : is)
		cout << e << " ";
	cout << endl;
	system("pause");
}

/*
void main()
{
	pair<int, string> isv = { 1, "abc" }; //int_string value
	cout << isv.first << " : " << isv.second << endl;
	system("pause");
}
*/