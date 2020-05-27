#include <iostream>
using namespace std;

class CGoods
{
public:
	CGoods(char *name = "no name", int count = 0, double price = 0)
	{
		cout << "Constructor using " << this <<  " called..." << endl;
		strcpy(m_name, name);
		m_count = count;
		m_price = price;
		m_total_price = m_count * m_price;
	}

	CGoods(const CGoods &t)
	{
		cout << "Copy constructor using " << this << " called..." << endl;
		strcpy(m_name, t.m_name);
		m_count = t.m_count;
		m_price = t.m_price;
		m_total_price = m_count * m_price;
	}

	~CGoods()
	{
		cout << "Destructor called: " << this <<endl;
	}

	CGoods & operator=(const CGoods &t)
	{
		cout << "Operator = using " << this << " called..." << endl;
		if (this != &t)
		{
			strcpy(m_name, t.m_name);
			m_count = t.m_count;
			m_price = t.m_price;
			m_total_price = m_count * m_price;
		}
		return *this;
	}

	void Display()const
	{
		cout << "Goods  name: " << m_name << endl;
		cout << "      count: " << m_count << endl;
		cout << "      price: " << m_price << endl;
		cout << "total price: " << m_total_price << endl;
	}
private:
	char m_name[20];
	int m_count;
	double m_price;
	double m_total_price;
};
int main()
{
	CGoods g1("C++", 10, 56.78);
	CGoods g2("JAVA", 20, 12.34);
	CGoods g3 = g1;
	CGoods g4;
	g4 = g2;
	//system("pause");
	return 0;
}



/*






namespace Jack{
	double pail;  //变量声明
	void fetch(); //函数原型
	struct {};    //结构体声明
}

namespace Jill{
	double pail;  //变量声明
	void fetch(); //函数原型
	struct {};    //结构体声明
}

using Jill::fetch; //把fetch加入到全局命名空间
int main()
{
	Jack::pail = 12.34; //使用变量
	Jill::fetch();  //使用函数
}
/*
class Person
{
public:                    //公有成员，在类外可以直接被访问
	void PrintPersonInfo(); 
private:                   //私有成员，在类外不能直接被访问
	char m_name[20];
	int m_age;
};
// 这里需要指定PrintPersonInfo是属于Person这个类域
void Person::PrintPersonInfo()
{
	cout << m_name << " " << m_age << endl;
	//cout << this->m_name << " " << this->m_age << endl;
}

int main()
{
	Person p;//类的实例化
}
*/