#include <iostream>
#include <string>
#include <vector>
using namespace std;

//���鼯
class UnionFindSet
{
public:
	// ��ʼʱ����������Ԫ��ȫ������Ϊ1
	UnionFindSet(size_t size)
		: _ufs(size, -1)
	{}
	// ��һ��Ԫ�صı�ţ��ҵ���Ԫ�����ڼ��ϵ�����
	int FindRoot(int index)
	{
		// ��������д洢���Ǹ������ҵ�������һֱ����
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

		// x1�Ѿ���x2��ͬһ������
		if (root1 == root2)
			return false;

		// ������������Ԫ�غϲ�
		_ufs[root1] += _ufs[root2];

		// ������һ���������Ƹı������һ��
		_ufs[root2] = root1;
		return true;
	}
	// �����и����ĸ�������Ϊ���ϵĸ���
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

//LRU�㷨
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
			// ��֤LRU���ƣ��Ѹ�get���ݷŵ������ͷ��
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
		// �ж��ǲ��뻹�Ǹ��£�
		auto ret = _hashmap.find(key);
		// 1���ҵ��˾��Ǹ���
		// 2��û�ҵ����ǲ���
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
			// ����
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