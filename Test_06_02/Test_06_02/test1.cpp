#include <iostream>
using namespace std;

template <typename Type>
Type Max(Type a, Type b)
{
	cout << typeid(Type).name() << endl;
	return a > b ? a : b;
}

int main()
{
	cout << Max(10, 20) << endl;
	cout << Max('A', 'B') << endl;
	cout << Max(10.23, 20.78) << endl;
	cout << Max<int>(10, 20.78) << endl;
	system("pause");
	return 0;
}
///*
//class Test
//{
//public:
//	Test(int a = 0) : m_a(a)
//	{}
//	~Test()
//	{}
//private:
//	int m_a;
//};
//int main()
//{
//	int *p = new int;// ��̬����һ��int���͵Ŀռ�
//	/*int *p = new int(2); ��̬����һ��int���͵Ŀռ䲢��ֵ*/
//	delete p;
//
//	int *par = new int[10];// ��̬����10��int���͵Ŀռ�
//	/*int *par = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; ��̬����10��int���͵Ŀռ䲢��ֵ*/
//	delete []par;
//
//	Test* pt1 = new Test;// ���뵥��Test���͵Ķ���
//	delete pt1;
//	
//	Test* pt2 = new Test[10];// ����10��Test���͵Ķ���
//	delete[] pt2;
//}
//
//
//void *operator new(std::size_t); //use by new
//void *operator new[](std::size_t); //use by new[]
//
//void operator delete(void *); //use by delete
//void operator delete[](void *); //use by delete[]
//*/