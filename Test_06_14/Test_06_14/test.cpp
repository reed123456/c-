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
	// ʹ���������������list�е�Ԫ��
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";

	cout << endl;
	// ʹ�÷�������������ӡlist�е�Ԫ��
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}
/*
int main()
{
	std::list<int> l1; // ����յ�l1
	std::list<int> l2(4, 100); // l2�з�4��ֵΪ100��Ԫ��
	std::list<int> l3(l2.begin(), l2.end()); // ��l2��[begin(), end()������ҿ������乹��l3
	std::list<int> l4(l3); // ��l3��������l4
	// ������Ϊ���������乹��l5
	int array[] = { 16, 2, 77, 29 };
	std::list<int> l5(array, array + sizeof(array) / sizeof(int));
	// �õ�������ʽ��ӡl5�е�Ԫ��
	for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
		std::cout << *it << " ";
	std::cout << endl;
	// C++11��Χfor�ķ�ʽ����
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
	// ����ЧԪ�ظ������ӵ�100���������λ��ʹ��8��䣬�����ڼ�ײ������
	// v.resize(100, 8);
	// reserve�����þ��Ǹı����ݴ�С�����ı���ЧԪ�ظ����������ڼ���ܻ�����ײ������ı�
	// v.reserve(100);
	// ����Ԫ���ڼ䣬���ܻ��������ݣ�������ԭ�ռ䱻�ͷ�
	// v.insert(v.begin(), 0);
	// v.push_back(8);
	// ��vector���¸�ֵ�����ܻ�����ײ������ı�
	v.assign(100, 8);
	
	����ԭ�����ϲ��������п��ܻᵼ��vector���ݣ�Ҳ����˵vector�ײ�ԭ��ɿռ䱻�ͷŵ���
	���ڴ�ӡʱ��it��ʹ�õ����ͷ�֮��ľɿռ䣬�ڶ�it����������ʱ��ʵ�ʲ�������һ���Ѿ����ͷŵ�
	�ռ䣬�������������ʱ������
	�����ʽ�������ϲ������֮�������Ҫ����ͨ������������vector�е�Ԫ�أ�ֻ���it����
	��ֵ���ɡ�
	
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
	// ʹ��find����3����λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	// ɾ��posλ�õ����ݣ�����pos������ʧЧ��
	v.erase(pos);
	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����
	return 0;
}
/*
int main()
{
	vector<int> v1;//���յĵ���������
	vector<int> v2(4, 100);//
	std::vector<int> v3(v2.begin(), v2.end()); //ͨ������������
	std::vector<int> v4(v3); //����v3
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