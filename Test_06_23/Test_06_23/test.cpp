#include <iostream>
using namespace std;

// �������Ĵ��������������¸���
// 1.��������һ��������Deriveȥ�̳�Base
// 2.Derive����дFunc1
// 3.Base������һ���麯��Func2��һ����ͨ����Func3
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};

int main()
{
	Base b;
	Derive d;
	return 0;
}



/*
class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
private:
	int _b = 1;
};
int main()
{
	Base b;
	cout << sizeof(b) << endl;
	return 0;
}

/*
class Person 
{
public:
	virtual void BuyTicket() 
	{ 
		cout << "��Ʊ-ȫ��" << endl;
	}
};
class Student : public Person 
{
public:
	virtual void BuyTicket() 
	{ 
		cout << "��Ʊ-���" << endl; 
	}
};
void Func(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person ps;
	Func(ps);

	Student st;
	Func(st);

	return 0;
}
int main()
{

	system("pause");
	return 0;
}
*/