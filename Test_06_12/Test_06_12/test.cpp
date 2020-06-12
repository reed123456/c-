#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> array{-6, -3, -2, -7, -15, -1, -2, -2};
	int max = array[0];
	int sum = array[0];
	for (int i = 1; i < array.size(); i++)
	{
		if (max < 0)
		{
			max = max > array[i] ? max : array[i];
			sum = 0;
		}
		else if (array[i] >= 0)
		{
			sum += array[i];
			max = max > sum ? max : sum;
		}
		else if (sum + array[i] >= 0)
		{
			sum += array[i];
		}
		else 
		{
			max = max > sum ? max : sum;
			sum = 0;

		}
	}

	cout << max << endl;

	system("pause");
	return 0;

}
/*
int main()
{
	int ar[] = { 1, 2, 3, 4, 0, 5, 6, 7, 8, 9 };
	int n = sizeof(ar) / sizeof(int);
	vector<int> v(ar, ar + n);
	vector<int>::iterator it = v.begin();

	while (it != v.end())
	{
		if (*it != 0)
			cout << *it;
		else
			v.erase(it);

		it++;
	}
	system("pause");
	return 0;
}
/*
int main()
{
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(ar) / sizeof(int);

	vector<int> v(ar, ar + n);
	cout << v.size() << ":" << v.capacity() << endl;

	v.reserve(100);
	v.resize(20);
	cout << v.size() << ":" << v.capacity() << endl;

	v.reserve(50);
	v.resize(5);
	cout << v.size() << ":" << v.capacity() << endl;

	system("pause");
	return 0;
}


/*
int main(void)
{
	vector<int>array;

	array.push_back(100);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(300);
	array.push_back(500);
	
	//100, 300, 300, 300, 300, 500
	vector<int>::iterator itor;

	for (itor = array.begin(); itor != array.end(); itor++)
	{
		if (*itor == 300)
		{
			itor = array.erase(itor);
		}
	}//100, 300, 300, 500

	for (itor = array.begin(); itor != array.end(); itor++)
	{
		cout << *itor << " ";
	}

	system("pause");
	return 0;
}
*/