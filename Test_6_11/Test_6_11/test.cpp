#include <iostream>
#include <string>
using namespace std;

int minArray(){
	//int numbers[] = { 2,2,2,0,1 };
	int numbers[] = { 3,1,3,3 };
	//int numbers[] = { 10, 10, 10, 1, 10 };

	int sz = sizeof(numbers) / sizeof(numbers[0]);
	int mid;
	int left = 0;
	int right = sz - 1;

	while (numbers[left] >= numbers[right] && right - left > 1)
	{
		mid = (left + right + 1) / 2;
		if (numbers[mid] == numbers[right])
			right--;

		else if (numbers[mid] < numbers[right])
			right = mid;
		else
			left = mid;

	}
	if (numbers[left] >= numbers[right])
		left = right;

	return numbers[left];
}

int main()
{
	int arr[] = {2,2,2,0,1 };
	

	int min = minArray();
	cout << min << endl;
	system("pause"); 
	return 0;
}
/*
int main()
{
	string str("The banker.");
	str.insert(4, "former "); // str = The former banker.
	cout << str << endl;
	system("pause");
	return 0;
}
*/