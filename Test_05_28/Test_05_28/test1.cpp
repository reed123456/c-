#include <iostream>
using namespace std;

namespace N1
{
	int fun(int a, int b)
	{
		return a + b;
	}
}

namespace N2
{
	int fun(int a, int b)
	{
		return a * b;
	}
}

using namespace N2;
int main()
{
	cout << N1::fun(10, 20) << endl;
	cout << fun(2, 3) << endl;
	system("pause");
	return 0;
}