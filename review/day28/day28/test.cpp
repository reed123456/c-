#include <iostream>
#include <vector>
std::vector<int> a = { 1, 1 };
void data_init()
{
	int i;
	for (i = 2; i<10005; i++){
		a.push_back((a[i - 1] + a[i - 2]) % 10000);
	}
}
int main()
{
	int n, t;
	data_init();
	while (std::cin >> n){
		while (n--){
			std::cin >> t;
			printf("%04d", a[t]);
		}
		printf("\n");
	}
	return 0;
}

/*
int main()
{
	int a = 1;
	system("pause");
	return 0;
}

/*
string IsTriangle(int a, int b, int c)
{
	if (a + b > c && a + c > b && b + c > a &&
		a > ((b > c) ? (b - c) : (c - b)) &&
		b > ((a > c) ? (a - c) : (c - a)) &&
		c > ((a > b) ? (a - b) : (b - a)))
		return string("Yes");
	return string("No");
}

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
		cout << IsTriangle(a, b, c) << endl;
	system("pause");
}
/*
int Add(int num1, int num2)
{
	int sum = 0, carry = 0;
	while (num2 != 0){
		//对应位的和
		sum = num1^num2;
		//对应位和的进位，既然是进位，就要整体左移一位
		carry = (num1&num2) << 1;
		num1 = sum;
		num2 = carry;
	}
	return sum;
}

int main()
{
	int num1, num2;
	num1 = 3;
	num2 = 0;
	//cin >> num1 >> num2;
	cout << Add(num1, num2) << endl;
	system("pause");
	return 0;
}
*/