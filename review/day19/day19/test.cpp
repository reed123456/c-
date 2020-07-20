#include <iostream>
using namespace std;

int main()
{
	double a = 30.3435312;
	printf("A %-30.4e|\n", a);
	printf("B %4.30e|\n", a);
	printf("C %-30.4f|\n", a);
	printf("D %-4.30f|\n", a);

	system("pause");
	return 0;
}
/*
class A {
public:
	~A() {
		cout << "~A()";
	}
};
class B{
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
	delete (C *)a2;
	system("pause");
}
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class A{
public:
	A(){ p(); }
	virtual void p(){ printf("A"); }
	virtual ~A(){ p(); }
};
class B :public A{
public:
	B(){ p(); }
	void p(){ printf("B"); }
	~B(){ p(); }
};
int main(int, char**){
	A* a = new B();
	delete a;
}

/*
int main()
{
	char *p = "abc";
	char *q = "abc123";
	*q = *p;
	while (*p = *q)
		printf("%c %c", *p, *q);
	system("pause");
}

/*
struct Test
{
	Test(int) {}
	Test() {}
	void fun() {}
};
void main(void)
{
	Test a(1);
	a.fun();
	Test b();
	//b.fun();
}

/*
#include <iostream>
using namespace std;
int main(void)
{
	const int a = 10;
	int * p = (int *)(&a);
	*p = 20;
	cout << "a = " << a << ", *p = " << *p << endl;
	system("pause");
	return 0;
}

/*
class A
{
public:
	void FuncA()
	{
		printf("FuncA called\n");
	}
	virtual void FuncB()
	{
		printf("FuncB called\n");
	}
};
class B : public A
{
public:
	void FuncA()
	{
		A::FuncA();
		printf("FuncAB called\n");
	}
	virtual void FuncB()
	{
		printf("FuncBB called\n");
	}
};
int main()
{
	B b;
	A *pa;
	pa = &b;
	A *pa2 = new A;
	pa->FuncA();     //£¨3£©
		pa->FuncB(); //£¨4£©
		pa2->FuncA();//£¨5£©
		pa2->FuncB();
	delete pa2;
	system("pause");
	return 0;
}

/*
int main()
{
	//char a[14] = "Hello, world!"; 
	//char b[14];
	//b = "Hello, world!"; 
	/*int(*p)[3];
	int arr[][3] = {{ 1, 2, 3 }, { 2, 3, 4 }, { 4, 5, 6 } };
	p = arr;
	system("pause");
	return 0;
}

/*
string maxSubstr(string str1, string str2)
{
	string strRet = "";
	if (str1.size() > str2.size())
	{
		string tmp = str1;
		str1 = str2;
		str2 = tmp;
	}
	for (int i = 0; i < str1.size(); ++i)
	{
		string substr = "";
		int n = str1.size() - i;
		do
		{
			substr = str1.substr(i, n--);
			if (substr.size() <= strRet.size())
				n = 0;
		} while (str2.find(substr) == string::npos && n != 0);

		if (n != 0)
		{
			strRet = strRet.size() >= substr.size() ? strRet : substr;
		}
	}
	return strRet;
}

int main()
{
	string str1, str2;
	//getline(cin, str1);
	//getline(cin, str2);
	str1 = "abcdefghijklmnop";
	str2 = "abcsafjklmnopqrstuvw";
	cout << maxSubstr(str1, str2) << endl;
	system("pause");
	return 0;
}

/*
int main()
{
	int n, x;
	vector<int> a;
	while (cin >> x && x != 0)
	{
		a.push_back(x);
	}
	for (int i = 0; i < a.size(); ++i)
	{
		int soda = 0;
		int emptyPop = a[i];
		while (emptyPop > 2)
		{
			soda += emptyPop / 3;
			emptyPop = emptyPop % 3 + emptyPop / 3;
		}
		if (emptyPop == 2)
			soda++;
		cout << soda << endl;
	}
	system("pause");
	return 0;
}

*/