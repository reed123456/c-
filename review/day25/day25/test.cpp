#include <iostream>
#include <string>
using namespace std;




class SmallInt{
public:
	SmallInt(int i = 0);
	//重载插入和抽取运算符
	friend ostream &operator<<(ostream&os, const SmallInt &si);
	friend istream &operator>>(istream &is, SmallInt &si);
	
	//重载算术运算符
	SmallInt operator+(const SmallInt &si){ return SmallInt(val + si.val); }
	SmallInt &operator+=(const SmallInt &si);
	SmallInt operator-(const SmallInt &si){ return SmallInt(val - si.val); }
	SmallInt operator*(const SmallInt &si){ return SmallInt(val*si.val); }
	SmallInt operator/(const SmallInt &si){ return SmallInt(val / si.val); }
	//重载比较运算符
	bool operator==(const SmallInt &si){ return (val == si.val); }
private:
	char val;
};
SmallInt::SmallInt(int i)
{
	while (i>127)
		i -= 256;
	while (i<-128)
		i += 256;
	val = i;
}

ostream &operator<<(ostream &os, const SmallInt &si)
{
	os << (int)si.val;
	return os;
}

istream &operator>>(istream &is, SmallInt &si)
{
	int tmp;
	is >> tmp;
	si = SmallInt(tmp);
	return is;
}

SmallInt & SmallInt::operator+=(const SmallInt &si)
{
	val = val + si.val;
	return SmallInt(val);
}

/*
class A{
private:
	static int object_count;
public:
	A(){ object_count++; }
	~A(){ object_count--; }
	virtual void func(int data){ cout << "class A : " << data << endl; }
	void func(char *str){ cout << "class A : " << str << endl; }
	static int GetObjectCount(){ return object_count; }
};
int A::object_count = 0;
void main()
{
	A *pA = new A[3];
	cout << "There are " << pA->GetObjectCount() << " objects" << endl;
	delete[]pA;
	cout << "There are " << A::GetObjectCount() << " objects" << endl;
}

/*
class B : public A{
	//…其它成员
public:
	void func() { cout << "function in B without parameter!\n"; }
	void func(int data) { cout << "class B : " << data << endl; }
	void func(char *str){ cout << "class B : " << str << endl; }
};


/*
int main(int argc, char *argv[])
{
	A *pA;
	B b;
	pA = &b;

	pA->func(1);
	pA->func("haha");
	system("pause");
	return 0;
}



/*
int main()
{
	queue<int> q;
	queue<int> p[10];

}


///*****************文件queue.h**************************************/
//template<class Type>
//class Queue;
///**********定义模板类QueueItem*******************************/
//template <class Type>
//class QueueItem
//{
//public:
//	QueueItem(const Type &elem) :item(elem){}
//	QueueItem(){}
//private:
//	Type item;
//	QueueItem *nextItem;
//	friend class Queue<Type>;
//};
///***************定义模板类Queue*****************************/
//template<class Type>
//class Queue{
//public:
//	 Queue() :front(NULL),back(NULL){}
//	 ~Queue();
//	 Type remove();
//	 void add(const Type &);
//	 bool is_empty()const { return  front == NULL; }
//private:
//	QueueItem<Type> *front;
//	QueueItem<Type> *back;
//};
////模板类Queue的函数成员remove()的实现
////从队列头取出一个节点，并返回该节点的值
//template<class Type>
//Type Queue<Type>::remove()
//{
//	QueueItem<Type> *pFront; //指向头节点的临时指针
//	Type retVal;  //返回值
//	pFront = front;
//	retVal = front->item;
//	front = front->nextItem;
//	delete  pFront;
//	return  retVal;
//}
////模板类Queue的函数成员add()的实现
//template<class Type>
//void Queue<Type>::add(const Type& newItem)
//{
//	QueueItem<Type> *pNew = new QueueItem<Type>;
//	pNew->item = newItem;
//	pNew->nextItem == NULL;
//	if (front == NULL)
//		front = back = pNew;
//	else
//	{
//		back->nextItem = pNew;
//		back = back->next;
//	}
//}
//template <class Type>
//Queue<Type>::~Queue()
//{
//	QueueItem<Type> *p = front, *q;
//	while (p != NULL)
//	{
//		q = p->nextItem;
//		delete p;
//		p = q;
//	}
//}


/*
int CalcDigital(char *str)
{
	//在下面写出程序的实现 
	int count = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] >= 0 && str[i] <= '9')
			count++;
	}
	return count;
}

long sum(int n)
{
	long ret = 0;
	while (n)
	{
		ret += n * n;
		n--;
	}
}
int main()
{
	char str[] = "olympic2000";
	cout << CalcDigital(str) << endl;
	system("pause");
	return 0;
}

/*
int minDistance(string word1, string word2) {
	// word与空串之间的编辑距离为word的长度
	if (word1.empty() || word2.empty()) {
		return max(word1.size(), word2.size());
	}
	int len1 = word1.size();
	int len2 = word2.size();
	// F(i,j)初始化
	vector<vector<int> > f(1 + len1, vector<int>(1 + len2, 0));
	for (int i = 0; i <= len1; ++i) {
		f[i][0] = i;
	}
	for (int i = 0; i <= len2; ++i) {
		f[0][i] = i;
	}
	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) {
			// F(i,j) = min { F(i-1,j）+1, F(i,j-1) +1, F(i-1,j-1) +
			//(w1[i]==w2[j]?0:1) }
			// 判断word1的第i个字符是否与word2的第j个字符相等
			if (word1[i - 1] == word2[j - 1]) {
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// 字符相等，F(i-1,j-1)编辑距离不变
				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}
			else {
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// 字符不相等，F(i-1,j-1)编辑距离 + 1
				f[i][j] = min(f[i][j], 1 + f[i - 1][j - 1]);
			}
		}
	}
	return f[len1][len2];
}

int main(){
	string a, b;
	//while (cin >> a >> b)
	a = "abcdef";
	b = "abcdefgh";
	cout << minDistance(a, b) << endl;
	return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Date
{
	char a;
	int b;
	unsigned long long c;
	char d;
};

int main()
{
	
	Date data[2][10];
	cout << (long)&(data[1][5].c) - (long)&data  << endl;
	system("pause");
	return 0;
}
*/