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

	// ����ֵ��<"peach","����">����map�У���pairֱ���������ֵ��
	m.insert(pair<string, string>("peach", "����"));
	// ����ֵ��<"peach","����">����map�У���make_pair�����������ֵ��
	m.insert(make_pair("banan", "�㽶"));
	// ����operator[]��map�в���Ԫ��
	m["apple"] = "ƻ��";

	cout << m.size() << endl;
	// �õ�����ȥ����map�е�Ԫ�أ����Եõ�һ������key���������
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;

	// map�еļ�ֵ��keyһ����Ψһ�ģ����key���ڽ�����ʧ��
	auto ret = m.insert(make_pair("peach", "��ɫ"));
	if (ret.second)
		cout << "<peach, ��ɫ>����map��, �Ѿ�����" << endl;
	else
		cout << "��ֵΪpeach��Ԫ���Ѿ����ڣ�" << ret.first->first << "--->" <<
		ret.first->second << " ����ʧ��" << endl;
	// ɾ��keyΪ"apple"��Ԫ��
	m.erase("apple");
	if (1 == m.count("apple"))
		cout << "apple����" << endl;
	else
		cout << "apple������" << endl;
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
	set<int> is_3 = is_2; //�������캯��
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