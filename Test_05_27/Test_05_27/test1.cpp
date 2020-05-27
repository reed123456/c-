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
	double pail;  //��������
	void fetch(); //����ԭ��
	struct {};    //�ṹ������
}

namespace Jill{
	double pail;  //��������
	void fetch(); //����ԭ��
	struct {};    //�ṹ������
}

using Jill::fetch; //��fetch���뵽ȫ�������ռ�
int main()
{
	Jack::pail = 12.34; //ʹ�ñ���
	Jill::fetch();  //ʹ�ú���
}
/*
class Person
{
public:                    //���г�Ա�����������ֱ�ӱ�����
	void PrintPersonInfo(); 
private:                   //˽�г�Ա�������ⲻ��ֱ�ӱ�����
	char m_name[20];
	int m_age;
};
// ������Ҫָ��PrintPersonInfo������Person�������
void Person::PrintPersonInfo()
{
	cout << m_name << " " << m_age << endl;
	//cout << this->m_name << " " << this->m_age << endl;
}

int main()
{
	Person p;//���ʵ����
}
*/