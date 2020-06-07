#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str("Hello Bit.");//15
	str.reserve(111);
	str.resize(5);
	str.reserve(50);
	cout << str.size() << ":" << str.capacity() << endl;
	return 0;
}

/*
int main(int argc, char *argv[])
{
	string a = "hello world";
	string b = a;
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;//
	string c = b;
	c = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;//
	a = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;//
	system("pause");
	return 0;
}

*/