#include <iostream>
#include <string>
#include <vector>
using namespace std;

//并查集
class UnionFindSet
{
public:
	// 初始时，将数组中元素全部设置为1
	UnionFindSet(size_t size)
		: _ufs(size, -1)
	{}
	// 给一个元素的编号，找到该元素所在集合的名称
	int FindRoot(int index)
	{
		// 如果数组中存储的是负数，找到，否则一直继续
		while (_ufs[index] >= 0)
		{
			index = _ufs[index];
		}

		return index;
	}
	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		// x1已经与x2在同一个集合
		if (root1 == root2)
			return false;

		// 将两个集合中元素合并
		_ufs[root1] += _ufs[root2];

		// 将其中一个集合名称改变成另外一个
		_ufs[root2] = root1;
		return true;
	}
	// 数组中负数的个数，即为集合的个数
	size_t Count()const
	{
		size_t count = 0;
		for (auto e : _ufs)
		{
			if (e < 0)
				++count;
		}

		return count;
	}

private:
	vector<int> _ufs;
};

//LRU算法
/*--------------------------------------------------------
class LRUCache {
public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
		auto ret = _hashmap.find(key);
		if (ret != _hashmap.end())
		{
			// 保证LRU机制，把刚get数据放到链表的头上
			list<pair<int, int>>::iterator pos = ret->second;
			pair<int, int> kv = *pos;
			_lrulist.erase(pos);
			_lrulist.push_front(kv);
			//_hashmap[key] = _lrulist.begin();
			ret->second = _lrulist.begin();
			return kv.second;
		}
		else
		{
			return -1;
		}
	}

	void put(int key, int value) {
		// 判断是插入还是更新？
		auto ret = _hashmap.find(key);
		// 1、找到了就是更新
		// 2、没找到就是插入
		if (ret != _hashmap.end())
		{
			list<pair<int, int>>::iterator pos = ret->second;
			_lrulist.erase(pos);
			_lrulist.push_front(make_pair(key, value));
			// _hashmap[key] = _lrulist.begin();
			ret->second = _lrulist.begin();
		}
		else
		{
			// 满了
			if (_lrulist.size() == _capacity)
			{
				pair<int, int> back = _lrulist.back();
				_hashmap.erase(back.first);
				_lrulist.pop_back();
			}

			_lrulist.push_front(make_pair(key, value));
			_hashmap.insert(make_pair(key, _lrulist.begin()));
		}
	}
private:
	unordered_map<int, list<pair<int, int>>::iterator> _hashmap;
	list<pair<int, int>>   _lrulist;
	int _capacity;
};

-----------------------------------------------------*/