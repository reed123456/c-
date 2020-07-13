#include <iostream>
using namespace std;

#define N 4
int x[N];
//static int count = 0;
void dump() {
	int i = 0;
	for (i = 0; i < N; i++) {
		printf("%d", x[i]);
	}
	printf("\n");
}
void swap(int a, int b) {
	int t = x[a];
	x[a] = x[b];
	x[b] = t;
}
void run(int n, int &count) {
	int i;
	if (N - 1 == n) {
		dump();
		count++;
		return;
	}
	for (i = n; i < N; i++) {
		swap(n, i);
		run(n + 1, count);
		swap(n, i);
	}
}
int main() {
	int i;
	int count = 0;
	for (i = 0; i < N; i++) {
		x[i] = i + 1;
	}
	run(0, count);
	printf("* Total: %d\n", count);
}

/*
void main() {
	int x = 3, y = 3;
	switch (x % 2) {
	case 1:
		switch (y) {
		case 0:cout << "first";
		case 1:cout << "second"; break;
		default: cout << "hello";
		}
	case 2:cout << "third";
	}
}
/*
int foo(int n){
	if (n<2){
		return n;
	}
	else
		return 2 * foo(n - 1) + foo(n - 2);
}

int main()
{
	cout << foo(5) << endl;
	system("pause");
	return 0;
}


/*
#pragma(4)

struct A
{
	int a;    //4
	short b;  //2 + 2
	int c;    //4
	char d;   // 2 + 2
};//16
struct B
{
	int a;    //4
	short b;  //2
	char c;   //1 + 1
	int d;    //4
};// 12
int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	system("pause");
	return 0;
}

*/