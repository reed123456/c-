#include<iostream>
#include<string>
#include<vld.h>
#include <cassert>
using namespace std;

namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s) : _str(nullptr), _size(0), _capacity(0)
		{
			string tmp(s._str);
			this->swap(tmp);
		}

		string& operator=(const string &s)
		{
			if (this != &s)
			{
				string temp(s);
				this->swap(temp);
			}
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

		// iterator
		iterator begin(){return _str;}
		iterator end(){return _str + _size;}

		// modify
		void push_back(char c)
		{
			if (_size == _capacity)
				reserve(_capacity * 2);

			_str[_size++] = c;
			_str[_size] = '\0';
		}

		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}

		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		const char* C_Str()const
		{
			return _str;
		}

		// capacity
		size_t size()const{return _size;}
		size_t capacity()const{return _capacity;}
		bool empty()const{return _size == 0;}

		void resize(size_t newSize, char c = '\0')
		{
			if (newSize > _size)
			{
				// ���newSize���ڵײ�ռ��С������Ҫ���¿��ٿռ�
				if (newSize > _capacity)
				{
					reserve(newSize);
				}
				memset(_str + _size, c, newSize - _size);
			}
			_size = newSize;
			_str[newSize] = '\0';
		}

		void reserve(size_t newCapacity)
		{
			// ������������ھ��������򿪱ٿռ�
			if (newCapacity > _capacity)
			{
				char* str = new char[newCapacity + 1];
				strcpy(str, _str);
				// �ͷ�ԭ���ɿռ�,Ȼ��ʹ���¿ռ�
				delete[] _str;
				_str = str;
				_capacity = newCapacity;
			}
		}

		// access
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}

		//relational operators
		bool operator<(const string& s)const
		{
			int res = strcmp(_str, s._str);
			if (res < 0)
				return true;

			return false;
		}

		bool operator<=(const string& s)const
		{
			return !(*this > s);
		}

		bool operator>(const string& s)const
		{
			int res = strcmp(_str, s._str);
			if (res > 0)
				return true;

			return false;
		}

		bool operator>=(const string& s)const
		{
			return !(*this < s);
		}

		bool operator==(const string& s)const
		{
			int res = strcmp(_str, s._str);
			if (res == 0)
				return true;

			return false;
		}

		bool operator!=(const string& s)const
		{
			return !(*this == s);
		}

		// ����c��string�е�һ�γ��ֵ�λ��
		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == c)
					return i;//�ҵ��������±�
			}
			return -1;//δ�ҵ�
		}

		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
		size_t find(const char* s, size_t pos = 0) const
		{
			assert(s);
			assert(pos < _size);
			const char* src = _str + pos;
			while (*src)
			{
				const char* match = s;//�����ƥ�䣬�����Ӵ���ʼ�����²���
				const char *cur = src;
				while (*match && *match == *cur)//��������
				{
					++match;
					++cur;
				}
				if (*match == '\0')//�ҵ��Ӵ�
				{
					return src - _str;//�����±�
				}
				else
				{
					++src;
				}
			}
			return -1;//δ�ҵ�
		}

		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
		string& insert(size_t pos, char c)
		{
			assert(pos <= _size);
			if (_size > _capacity)
			{
				//����
				char *newstr = new char[_capacity * 2 + 1];//���ռ�
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity *= 2;
			}
			//������
			for (int i = _size; i >= (int)pos; --i)
			{
				_str[i + 1] = _str[i];
			}

			_str[pos] = c;
			_size++;
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)//����
			{
				//����
				char *newstr = new char[_capacity * 2 + 1];//���ռ�
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity *= 2;
			}
			//��������
			for (int i = _size; i >= (int)pos; --i)
			{
				_str[len + i] = _str[i];
			}
			//�����ַ���
			while (*str != '\0')
			{
				_str[pos++] = *str++;
			}
			_size += len;
			return *this;
		}

		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
		string& erase(size_t pos, size_t len)
		{
			assert(pos < _size);
			if (pos + len >= _size)//posλ��֮��ȫΪ0
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
	private:
		friend ostream& operator<<(ostream& _cout, const bit::string& s);
		friend istream& operator>>(istream& _cin, bit::string& s);
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
};

//����������
istream& bit::operator>>(istream& _cin, bit::string& s)
{
	//Ԥ����100���ռ�
	char *str = (char *)malloc(sizeof(char)* 100);
	char *buf = str;
	int i = 1;
	//Ԥ������������������пո�ͻس�
	while ((*buf = getchar()) == ' ' || (*buf == '\n'));

	for (;; ++i)
	{
		if (*buf == '\n') //�س�����
		{
			*buf = '\0';
			break;
		}
		else if (*buf == ' ') //�ո�����
		{
			*buf = '\0';
			break;
		}
		else if (i % 100 == 0) //�ռ䲻��
		{
			i += 100; //׷��100���ռ�
			str = (char *)realloc(str, i);
		}
		else  //ÿ��getchar()һ��ֵ
		{
			buf = (str + i);//Ϊ�˱���realloc�����׵�ַ�ı䣬��ʹ��++buf��������str����ƫ��.
			//ÿ�ζ�ȡһ���ַ�
			*buf = getchar();
		}
	}
	//�������,����s
	s._str = str;
	s._capacity = s._size = i;

	return _cin;
}

//���������
ostream& bit::operator<<(ostream& _cout, const bit::string& s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		_cout << s[i];
	}
	return _cout;
}

/*
//����һ: string�Ĵ�ͳ��ʵ��
class string
{
public:
	string(const char* str = "")
	{
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	string(const string& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	string& operator=(const string &s)
	{
		if (this != &s)
		{
			delete[]_str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}

	~string()
	{
		delete[]_str;
		_str = nullptr;
	}
private:
	char *_str;
};





//--------------------------------------------------------------------------
namespace bit
{
	//ǳ����
	class string
	{
		friend ostream& operator<<(ostream &out, const string &s);
	public:
		string(const char *str = "") :m_use_count(new int(1))
		{
			if (nullptr == str)
				m_data = new char[1]{'\0'};
			else
			{
				m_data = new char[strlen(str) + 1];
				strcpy(m_data, str);
			}
		}
		string(const string &s) :m_data(s.m_data), m_use_count(s.m_use_count)
		{
			//�������ü���
			increment_ref_count();
		}
		string& operator=(const string &s)
		{
			if (this != &s)
			{
				decrement_ref_count();
				m_data = s.m_data;
				m_use_count = s.m_use_count;
				increment_ref_count();
			}
			return *this;
		}
		~string()
		{
			decrement_ref_count();
		}
	public:
		void increment_ref_count()
		{
			(*m_use_count)++;
		}
		void decrement_ref_count()
		{
			if (--(*m_use_count) == 0)
			{
				//�ͷ����ݿռ�
				delete[]m_data;
				m_data = nullptr;
				//�ͷ����ü����ռ�
				delete m_use_count;
				m_use_count = nullptr;
			}
		}
	public:
		//дʱ����
		void to_upper()
		{
			char *new_data = new char[strlen(m_data) + 1];
			strcpy(new_data, m_data);
			int *new_use_count = new int(1);
			char *pstr = new_data;
			while (*pstr != '\0')
			{
				*pstr -= 32;
				pstr++;
			}
			decrement_ref_count();

			m_data = new_data;
			m_use_count = new_use_count;
		}
	private:
		char *m_data;
		//���ü���
		int  *m_use_count;
	};

	//��Ԫ
	ostream& operator<<(ostream &out, const string &s)
	{
		out << s.m_data;
		return out;
	}
};
void main()
{
	bit::string str("abc"); //����
	bit::string str1 = str;
	cout << "str = " << str << endl;
	cout << "str1 = " << str1 << endl;
	str.to_upper();
	cout << "str = " << str << endl;
	cout << "str1 = " << str1 << endl;
}
*/