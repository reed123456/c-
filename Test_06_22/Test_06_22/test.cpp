#include <iostream>
using namespace std;

class A
{
public:
	A() :m_iVal(0){ test(); }
	virtual void func() { std::cout << m_iVal << " "; }
	void test(){ func(); }
public:
	int m_iVal;
};

class B : public A
{
public:
	B(){ test(); }
	virtual void func()
	{
		++m_iVal;
		std::cout << m_iVal << " ";
	}
};

int main(int argc, char* argv[])
{
	A*p = new B;
	p->test();
	return 0;
}

/*
class B { public: int b; };
class C1 : public B { public: int c1; };
class C2 : public B { public: int c2; };
class D : public C1, public C2 { public: int d; };

/*
class Base1{ public: int _b1; };
class Base2 { public: int _b2; };
class Derive : public Base1, public Base2
{
public: int _d;
};

int main(){
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;
	return 0;
}
/*
class A
{
public:
	A() { cout << "A::A()" << endl; }
	~A() { cout << "A::~A()" << endl; }
	int a;
};

class B : public A
{
public:
	B() { cout << "B::B()" << endl; }
	~B() { cout << "B::~B()" << endl; }
	int b;
};

void main()
{
	B b;
}
/*
class A
{
public:
	void f(){ cout << "A::f()" << endl; }
	int a;
};

class B : public A
{
public:
	void f(int a){ cout << "B::f()" << endl; }
	int a;
};

int main()
{
	B b;
	b.f();
	system("pause");
	return 0;
}
*/