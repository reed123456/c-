#include <iostream>
using namespace std;

class CGoods
{
public:
	void Register(char* name, double price, int count);
	char* GetName();
	int GetCount();
	double Getprice();
	double GetCountPrice();
private:
	char m_name[20];
	double m_price;
	int m_count;
	double m_count_price;
};

void CGoods::Register(char* name, double price, int count)
{
	strcpy(m_name, name);
	m_price = price;
	m_count = count;
	m_count_price = m_count * m_price;
}
char* CGoods::GetName()
{
	return m_name;
}
int CGoods::GetCount()
{
	return m_count;
}
double CGoods::Getprice()
{
	return m_price;
}
double CGoods::GetCountPrice()
{
	return m_count_price;
}

int main()
{
	CGoods g;
	g.Register("C++", 56.78, 10);
	cout << "name = " << g.GetName() << endl;
	cout << "price = " <<g.Getprice() << endl;
	cout << "count = " << g.GetCount() << endl;
	cout << "count price = " << g.GetCountPrice() << endl;
	system("pause");
	return 0;
}
/*
inline double square(double x){ return x * x; }
int Max(int a, int b)
{
	return a > b ? a : b;
}

char Max(char a, char b)
{
	return a > b ? a : b;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (auto &e : arr)
		cout << e << " ";
	cout << endl;
	int a = 10;
	int &ra = a;
	cout << "a = " << a <<endl;  // a = 10
	cout << "ra = " << ra << endl; //ra = 20
	cout << Max(10, 20) << endl;  // 20
	cout << Max('A', 'B') << endl;// 'B'
	system("pause");
	return 0;
}
*/