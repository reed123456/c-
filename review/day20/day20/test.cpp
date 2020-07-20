#include <iostream>
#include <string>
#include <vld.h>
using namespace std;

class A
{
public:
	void f()
	{
		printf("A\n");
	}
};
class B : public A
{
public:
	virtual void f()
	{
		printf("B\n");
	}
};
int main()
{
	A *a = new B;
	a->f();
	delete a;
	//int *p = new int;
	return 0;
}

/*
class CSomething
{
public:
	CSomething(int a = 0) : _a(a)
	{
		cout << "construct()." << endl;
		counter++;
	}
private:
	int _a;
	static int counter;
};

int CSomething::counter = 0;

int main()
{
	CSomething a();
	CSomething b(2);
	CSomething c[3];
	CSomething &ra = b;
	CSomething d = b;
	CSomething *pA = c;
	CSomething *p = new CSomething(4);
	//cout << CSomething::counter << endl;
	system("pause");
	return 0;
}
/*
class myClass
{
	public:
	void foo(){};
};
void myClass::foo(){
	delete this;
}

void func(){
	myClass *a = new myClass();
	a->foo();

/*
int FindSubString(char* pch)
{
	int count = 0;
	char * p1 = pch;
	while (*p1 != '\0')
	{
		if (*p1 == p1[1] - 1)
		{
			p1++;
			count++;
		}
		else {
			break;
		}
	}
	int count2 = count;
	while (*p1 != '\0')
	{
		if (*p1 == p1[1] + 1)
		{
			p1++;
			count2--;
		}
		else {
			break;
		}
	}
	if (count2 == 0)
		return(count);
	return(0);
}
void ModifyString(char* pText)
{
	char * p1 = pText;
	char * p2 = p1;
	while (*p1 != '\0')
	{
		int count = FindSubString(p1);
		if (count > 0)
		{
			*p2++ = *p1;
			sprintf(p2, "%i", count);
			while (*p2 != '\0')
			{
				p2++;
			}
			p1 += count + count + 1;
		}
		else {
			*p2++ = *p1++;
		}
	}
}
void main(void)
{
	char text[32] = "XYBCDCBABABA";
	ModifyString(text);
	printf(text);
	system("pause");
}

/*
int main()
{
	char a[] = "ABCD\0EF"; 
	char b[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	cout << "a[] = " << sizeof(a) << endl;
	cout << "b[] = " << sizeof(b) << endl;
	system("pause");
	return 0;
}
*/