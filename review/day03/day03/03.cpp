#include <iostream>
#include <string>
using namespace std;

int main()
{
	system("pause");
	return 0;
}

/*
int main()
{
	string str;
	getline(cin, str);

	int pos = -1, pre_pos = -1;
	int length = 0, pre_length = 0;

	for(int i = 0; i < str.size(); ++i)
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (pos == -1)
				pos = i;
			length++;
			i++;
			if (i == str.size())
				break;
		}
		if (length != 0 || i == str.size())
		{
			pre_length = pre_length > length ? pre_length : length;
			pre_pos = pre_length > length ? pre_pos : pos;
			pos = -1;
			length = 0;
		}
	}
	string str1(str.begin() + pre_pos, str.begin() + pre_pos + pre_length);
	cout << pre_pos << "£º" << pre_length << endl;
	cout << str1 << endl;
	system("pause");
	return 0;
}
*/