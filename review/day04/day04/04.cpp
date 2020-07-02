#include <iostream>
#include <string>
using namespace std;


int main()
{
	int num = 13, scale = 4;

	string ret;
	int flag1, flag2;
	while (num > 0)
	{
		
		flag2 = num % scale;
		flag1 = num / scale;
		if (flag2 >= 10)
		{
			ret += flag2 - 10 + 'A';
		}
		else
		{
			ret += flag2 + '0';
		}
		
		num /= scale; 
	}

	cout << ret << endl;
	system("pause");
	return 0;
}

/*
int main()
{
	int AsubB, BsubC, AplusB, BplusC;
	while (scanf("%d %d %d %d", &AsubB, &BsubC, &AplusB, &BplusC))
	{
		if (AsubB > 30 && AsubB < -30 && BsubC > 30 && BsubC < -30 &&
			AplusB > 30 && AplusB < -30 && BplusC > 30 && BplusC < -30)
		{
			break;
		}
	}
	if ((AplusB - AsubB) % 2 != 0)
	{
		cout << "N0" << endl;
		return 0;
	}
	int b = (AplusB - AsubB) / 2;
	int a = AsubB + b;
	int c = BplusC - b;
	if (b - c != BsubC)
	{
		cout << "N0" << endl;
	}
	else
	{
		cout << a << " " << b << " " << c << endl;
	}
	
	
	system("pause");
	return 0;
}
*/