#include <iostream>
using namespace std;

class Base
{
public:
	void fun()
	{
		cout << "Base::fun()" << endl;
	}
	void fun(int)
	{
		cout << "Base::fun(int)" << endl;
	}
};

class D : public Base
{
public:
	
};

int main()
{
	D d;
	d.fun(1);
	system("pause");
	return 0;
}
/*
int main()
{
	double d = 12.34;
	int a = static_cast<int>(d);
	cout << a << endl;
	system("pause");
	return 0;
}

class A {
public:
	~A() {
		cout << "~A()";
	}
};
class B {
public:
	virtual ~B() {
		cout << "~B()";
	}
};
class C : public A, public B {
public:
	~C() {
		cout << "~C()";
	}
};
int main() {
	C * c = new C;
	B * b1 = dynamic_cast<B *>(c);
	A * a2 = dynamic_cast<A *>(b1);
	delete a2;
}
*/