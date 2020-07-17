#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//����Լ���������1�ͱ����Լ��
void divisorNum(int n, vector<int> &divNum)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			divNum.push_back(i);
			//��ƽ����ʱ������һ����ҲҪ����
			if (n / i != i)
				divNum.push_back(n / i);
		}
	}
}
int Jump(int N, int M)
{
	//����ĵ����stepNum��Ĳ�������ʼNΪ1������N��NΪ1��
	vector<int> stepNum(M + 1, 0);
	stepNum[N] = 1;
	for (int i = N; i < M; i++)
	{
		//N������Լ������Ϊ�ӱ�������㿪ʼ���ߵ�����
		vector<int> divNum;
		//0��������㲻�ܵ�
		if (stepNum[i] == 0)
			continue;
		//����������ߵĲ���������divNum��������
		divisorNum(i, divNum);
		for (int j = 0; j < divNum.size(); j++)
		{
			//��λ��i�����ܵ���ĵ�Ϊ stepNum[divNum[j]+i]
			if ((divNum[j] + i) <= M && stepNum[divNum[j] + i] != 0)
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i],
				stepNum[i] + 1);
			else if ((divNum[j] + i) <= M)
				stepNum[divNum[j] + i] = stepNum[i] + 1;
		}
	}
	if (stepNum[M] == 0)
		return -1;
	else
		//��ʼ��ʱ�����һ��������Ҫ��1
		return stepNum[M] - 1;
}
int main()
{
	int n, m;
	cin >> n >> m;
	cout << Jump(n, m) << endl;
	system("pause");
	return 0;
}

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void func(const int& v1, const int& v2)
{
	std::cout << v1 << ' ';
	std::cout << v2 << ' ';
}

int main(int argc, char* argv[])
{
	int i = 0;
	func(++i, i++);
	system("pause");
	return 0;
}
/*
class myClass
{
	myClass(){
		this = NULL;
	};
	~myClass(){};
};
myClass::~myClass(){
	delete this;
	this = NULL;
}
/*
#define SQR(A) A*A
void main() {
	int x = 6, y = 3, z = 2;
	x /= SQR(y + z) / SQR(y + z);//
	cout << x << endl;
	cout << 6 /(3 + 2 * 3 + 2 / 3 + 2 * 3 + 2) << endl;
	system("pause");
}

/*
string AddLongInteger(string addend, string augend)
{
	if (addend.size() == 0)
		return augend;
	if (augend.size() == 0)
		return addend;

	reverse(addend.begin(), addend.end());
	reverse(augend.begin(), augend.end());
	if (augend.size() > addend.size())
	{
		string tmp = addend;
		addend = augend;
		augend = tmp;
	}
	int i, flag = 0;
	for (i = 0; i < augend.size(); i++)
	{
		int sum = addend[i] - '0' + augend[i] - '0' + flag;
		addend[i] = sum % 10 + '0';
		flag = sum / 10;
	}

	while (flag > 0 && i < addend.size())
	{
		int sum = addend[i] - '0' + flag;
		addend[i] = sum % 10 + '0';
		flag = sum / 10;
		i++;
	}
	if (flag > 0)
	{
		char c = flag + '0';
		addend.push_back(c);
	}

	reverse(addend.begin(), addend.end());
	return addend;
}

int main()
{
	string addend, augend;
	//getline(cin, addend);
	//getline(cin, augend);
	addend = "32";
	augend = "223";
	cout << AddLongInteger(addend, augend) << endl;
	system("pause");
	return 0;
}

/*
int evenPosition(int n)
{
	if (n == 1 || n == 2)
		return -1;
	if (n % 2 == 1)
		return 2;

	vector<int> a;
	a.resize(2 * n);
	a[1] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 2 * i - 1; j > 1; --j)
		{
			a[j] = a[j] + a[j - 1] + a[j - 2];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (a[i] % 2 == 0)
			return i;
	}
	return -1;
}
int main()
{
	int n = 4;
	//cin >> n;
	cout << evenPosition(n) << endl;
	system("pause");
	return 0;
}

*/