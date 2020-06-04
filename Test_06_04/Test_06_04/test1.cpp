#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int > vi{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (auto &t : vi)
		cout << t << " ";
	cout << endl;
	system("pause");
	return 0;
}
/*
template <typename Type>
Type Max(Type a, Type b)
{
	return a > b ? a : b;
}

int main()
{
	cout << Max(10, 20) << endl;
	cout << Max('A', 'B') << endl;
	cout << Max(12.34, 56.78) << endl;
	system("pause");
	return 0;
}
*/