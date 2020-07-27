#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> a;
	while (cin >> n)
	{
		int root = 0;
		while (n > 9)
		{
			root += n % 10;
			n /= 10;
			if (n < 9)
			{
				root += n;
				if (root > 9)
				{
					n = root;
					root = 0;
				}
			}
		}
		cout << root << endl;
	}
	
	return 0;
}