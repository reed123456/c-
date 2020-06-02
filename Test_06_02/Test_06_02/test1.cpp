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
//	int *p = new int;// 动态申请一个int类型的空间
//	/*int *p = new int(2); 动态申请一个int类型的空间并赋值*/
//	delete p;
//
//	int *par = new int[10];// 动态申请10个int类型的空间
//	/*int *par = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 动态申请10个int类型的空间并赋值*/
//	delete []par;
//
//	Test* pt1 = new Test;// 申请单个Test类型的对象
//	delete pt1;
//	
//	Test* pt2 = new Test[10];// 申请10个Test类型的对象
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