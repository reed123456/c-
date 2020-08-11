#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	// �Ҹ�������ǰ4����С��Ԫ��, Ԫ�����մ洢��v1��ǰ4��λ��
	vector<int> v1{ 4, 1, 8, 0, 5, 9, 3, 7, 2, 6 };
	partial_sort(v1.begin(), v1.begin() + 4, v1.end());
	for (auto &e : v1)
		cout << e << " ";
	cout << endl;
	// �Ҹ�������ǰ4������Ԫ��, Ԫ�����մ洢��v1��ǰ4��λ��
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
	// ��map�в���Ԫ�صķ�ʽ��
	// ����ֵ��<"peach","����">����map�У���pairֱ���������ֵ��
	m.insert(pair<string, string>("peach", "����"));
	// ����ֵ��<"peach","����">����map�У���make_pair�����������ֵ��
	m.insert(make_pair("banan", "�㽶"));
	// ��<"apple", "">����map�У�����ɹ�������value�����ã�����ƻ������ֵ�������ý����
	m["apple"] = "ƻ��";
	// key������ʱ���쳣
	//m.at("waterme") = "ˮ����";
	cout << m.size() << endl;
	// �õ�����ȥ����map�е�Ԫ�أ����Եõ�һ������key���������
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;
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
	// ������array�е�Ԫ�ع���set
	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	set<int> s(array, array + sizeof(array) / sizeof(array[0]));
	cout << s.size() << endl;
	// �����ӡset�е�Ԫ�أ��Ӵ�ӡ����п��Կ�����set��ȥ��
	for (auto& e : s)
		cout << e << " ";
	cout << endl;
	// ʹ�õ����������ӡset�е�Ԫ��
	for (auto it = s.rbegin(); it != s.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	// set��ֵΪ3��Ԫ�س����˼���
	cout << s.count(3) << endl;
	system("pause");
}
*/ 