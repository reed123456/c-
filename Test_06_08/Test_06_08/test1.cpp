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
int res = Max(10, 20);// ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
int res = Max<int>(10, 20);// ���ñ������ػ���Max�汾
int res = Max(10.23, 20.34);// ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Max����
}


// ע�⣺Vector���Ǿ�����࣬�Ǳ��������ݱ�ʵ�������������ɾ������ģ��
template<class T>
class Vector
{
public:
Vector(size_t capacity = 10)
: _pData(new T[capacity])
, _size(0)
, _capacity(capacity)
{}
// ʹ������������ʾ�������������������ⶨ�塣
~Vector();
void PushBack(const T& data)��
void PopBack()��
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
// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
template <class T>
Vector<T>::~Vector()
{
if (_pData)
delete[] _pData;
_size = _capacity = 0;
}
*/