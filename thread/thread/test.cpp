#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
#include <atomic>

//原子操作
atomic_long sum{ 0 };
void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
		sum++; // 原子操作
}
int main()
{
	cout << "Before joining, sum = " << sum << std::endl;
	thread t1(fun, 1000000);
	thread t2(fun, 1000000);
	t1.join();
	t2.join();
	cout << "After joining, sum = " << sum << std::endl;
	return 0;
}
/*
//互斥量
mutex mt;
void thread_fun1(int n)
{
	mt.lock();
	cout << "This is thread fun1. " << endl;
	//Sleep(3000);
	cout << "thread fun1 wake up." << endl;
	mt.unlock();
}
void thread_fun2(int n)
{
	mt.lock();
	cout << "This is thread fun2." << endl;
	//Sleep(1000);
	cout << "thread fun2 wake up." << endl;
	mt.unlock();
}
void main()
{
	int n = 5;
	thread th1(thread_fun1, n);
	thread th2(thread_fun2, n);
	th1.join();
	th2.join();
	cout << "Main Thread End." << endl;
}
/*
class thread_obj
{
public:
	thread_obj(thread &th) : th_obj(th)
	{}
	~thread_obj()
	{
		if (th_obj.joinable())
		{
			th_obj.join();
		}
	}
public:
	thread_obj(const thread_obj &) = delete;
	thread_obj& operator=(const thread_obj &) = delete;
private:
	thread  &th_obj;
};
////////////////////////////////////////////////////////////
void ThreadFunc()
{
	cout << "ThreadFunc()" << endl;
}
bool DoSomething(int x)
{
	if (x > 0)
		return true;
	return false;
}
//串行执行
int main()
{
	std::thread t(ThreadFunc);
	//t.detach();
	thread_obj obj(t);   //代理 t

	if (!DoSomething(0)) //>0 <0 =0
		return -1;
	//th.join();
	return 0;
}

/*
void thread_fun1(int &a)
{
	a += 10;
	cout << "In thread fun1 x = " << a << endl;
}
void thread_fun2(int *a)
{
	*a += 10;
	cout << "In thread fun2 x = " << *a << endl;
}
void thread_fun3(int &a)
{
	a += 10;
	cout << "In thread fun1 x = " << a << endl;
}
void main()
{
	int x = 10;
	int y = 10;
	int z = 10;
	thread th1(thread_fun1, x);
	thread th2(thread_fun2, &y);
	thread th3(thread_fun3, ref(z));

	th1.join();
	th2.join();
	th3.join();
	cout << "In main x = " << x << endl;
	cout << "In main y = " << y << endl;
	cout << "In main z = " << z << endl;
}


/*
void thread_fun()
{
	cout << "This is Child Thread." << endl;
}
void main()
{
	thread th(thread_fun);
	cout << "th id = " << th.get_id() << endl;
	//th.detach();
	cout << "This is Main Thread." << endl;
	th.join();
	cout << "Main End." << endl;
}
*/