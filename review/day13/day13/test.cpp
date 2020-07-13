#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string str;
	vector<string> vRet;
	vector<int> a;
 	getline(cin, str);
	int pre_pos = 0;
	int pos = 0;
	string target = " ";
	string strResult;
	a.push_back(0);
	while ((pos = str.find_first_of(target, pre_pos)) != string::npos)
	{
		strResult = str.substr(pre_pos, pos - pre_pos);
		vRet.push_back(strResult);

		pre_pos = ++pos;
	}
	if (pre_pos != str.size())
	{
		strResult = str.substr(pre_pos, pos - pre_pos);
		vRet.push_back(strResult);
	}

	cout << vRet.size() << endl;
	for (const auto &e : vRet)
	{
		cout << e << endl;
	}
	system("pause");
	return 0;
}