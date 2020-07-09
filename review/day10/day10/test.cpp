#include <iostream>
#include <string>
using namespace std;

int getSorce(string pPasswordStr)
{
	int score;
	int sz = pPasswordStr.size();
	if (sz <= 4)
		score = 5;
	else if (sz <= 7)
		score = 10;
	else
		score = 25;

	int arr[4] = { 0 };
	for (int i = 0; i < sz; i++)
	{
		if ((pPasswordStr[i] >= '0') && (pPasswordStr[i] <= '9'))
			arr[0] += 10;
		else if ((pPasswordStr[i] >= 'a') && (pPasswordStr[i] <= 'z'))
			arr[1] = 10;
		else if ((pPasswordStr[i] >= 'A') && (pPasswordStr[i] <= 'Z'))
			arr[2] = 10;
		else
			arr[3] += 10;
	}
	if (arr[0] >= 20)
		arr[0] = 20;
	if (arr[3] >= 20)
		arr[3] = 25;
	score += arr[0] + arr[1] + arr[2] + arr[3];

	int added = 0;
	if ((arr[0] != 0) && ((arr[1] + arr[2]) != 0))
	{
		added = 2;
		if (arr[1] != 0 && arr[2] != 0)
		{
			added = 3;
			if (arr[3] != 0)
				added = 5;
		}
	}
	return score + added;
}


int main()
{
	string str = "3";
	//getline(cin, str);
	int sorce = getSorce(str);
	if (sorce >= 90)
		cout << "VERY_WEAK" << endl;
	else if (sorce >= 80)
		cout << "WEAK" << endl;
	else if (sorce >= 70)
		cout << "AVERAGE" << endl;
	else if (sorce >= 60)
		cout << "STRONG" << endl;
	else if (sorce >= 50)
		cout << "VERY_STRONG" << endl;
	else if (sorce >= 25)
		cout << "SECURE" << endl;
	else
		cout << "VERY_SECURE" << endl;
	system("pause");
	return 0;
}