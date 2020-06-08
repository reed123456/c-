#include <iostream>
#include <string>
using namespace std;

void main()
{
	string s1 = "hello world";
	string s2 = "change world";
string::iterator it = s1.begin();

	swap(s1, s2);

while (it != s1.end())
		cout << *it;

cout << endl;
	system("pause");
}

/*
int main()
{
string str = "Hello Bit.";
string::iterator it = str.begin();

while (it != str.end())
{
if (*it != ' ')
cout << *it;
else
str.erase(it);

it++;
}
system("pause");
return 0;
}

/*
int main(int argc, char *argv[])
{
string strText = "How are you?";
string strSeparator = " ";
string strResult;
int size_pos = 0;
int size_prev_pos = 0;

while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
{
strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
cout << strResult << " ";
size_prev_pos = ++size_pos;
}
if (size_prev_pos != strText.size())
{
strResult = strText.substr(8, -1);
cout << strResult << " ";
}
cout << endl;
system("pause");
return 0;
}



/*
int Max(int a, int b)
{
return a > b ? a : b;
}

template <typename Type>
Type Max(Type a, Type b)
{
return a > b ? a : b;
}

int main()
{
int res = Max(10, 20);// 与非函数模板类型完全匹配，不需要函数模板实例化
int res = Max<int>(10, 20);// 调用编译器特化的Max版本
int res = Max(10.23, 20.34);// 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Max函数
}


// 注意：Vector不是具体的类，是编译器根据被实例化的类型生成具体类的模具
template<class T>
class Vector
{
public:
Vector(size_t capacity = 10)
: _pData(new T[capacity])
, _size(0)
, _capacity(capacity)
{}
// 使用析构函数演示：在类中声明，在类外定义。
~Vector();
void PushBack(const T& data)；
void PopBack()；
// ...
size_t Size() { return _size; }
T& operator[](size_t pos)
{
assert(pos < _size);
return _pData[pos];
}
private:
T* _pData;
size_t _size;
size_t _capacity;
};
// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
template <class T>
Vector<T>::~Vector()
{
if (_pData)
delete[] _pData;
_size = _capacity = 0;
}
*/