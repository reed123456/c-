#include<iostream>
#include<vld.h>
#include<string>
using namespace std;

int main()
{

	cout << "hh" << endl;
}
//template<class Type>
//class BST;
//
////ʵ��һ�ö���������
//template<class Type>
//class BSTNode
//{
//	friend class BST<Type>;
//public:
//	BSTNode(Type d = Type(), BSTNode<Type> *left = nullptr, BSTNode<Type> *right = nullptr)
//		: data(d), leftChild(left), rightChild(right)
//	{}
//	~BSTNode()
//	{}
//private:
//	Type data;
//	BSTNode<Type> *leftChild;
//	BSTNode<Type> *rightChild;
//};
//
//template<class Type>
//class BST
//{
//public:
//	BST() : root(nullptr)
//	{}
//	BST(Type ar[], int n) : root(nullptr)
//	{
//		for (int i = 0; i<n; ++i)
//			Insert(ar[i]);
//	}
//	~BST()
//	{
//		MakeEmpty(root);
//		root = nullptr;
//	}
//public:
//	Type Min()const
//	{
//		return Min(root);
//	}
//	Type Max()const
//	{
//		return Max(root);
//	}
//	bool Insert(const Type &x)
//	{
//		return Insert(root, x);
//	}
//	bool Remove(const Type &key)
//	{
//		return Remove(root, key);
//	}
//	BSTNode<Type>* Search(const Type &key)
//	{
//		return Search(root, key);
//	}
//	void Sort()
//	{
//		Sort(root);
//	}
//	void SortPair()
//	{
//		SortPair(root);
//	}
//	void MakeEmpty()
//	{
//		MakeEmpty(root);
//	}
//protected:
//	Type& Min(BSTNode<Type> *t)const
//	{
//		while (t->leftChild != nullptr)
//			t = t->leftChild;
//		return t->data;
//	}
//	Type& Max(BSTNode<Type> *t)const
//	{
//		while (t->rightChild != nullptr)
//			t = t->rightChild;
//		return t->data;
//	}
//	bool Insert(BSTNode<Type> *&t, const Type &x)
//	{
//		if (t == nullptr)
//		{
//			t = new BSTNode<Type>(x);
//			return true;
//		}
//		else if (x < t->data)
//			Insert(t->leftChild, x);
//		else if (x > t->data)
//			Insert(t->rightChild, x);
//		else
//			return false;
//	}
//	bool Remove(BSTNode<Type> *&t, const Type &key)
//	{
//		BSTNode<Type> *p = nullptr;
//		if (t != nullptr)
//		{
//			if (key < t->data)
//				Remove(t->leftChild, key);
//			else if (key > t->data)
//				Remove(t->rightChild, key);
//			else if (t->leftChild != nullptr && t->rightChild != nullptr)
//			{
//				p = t->leftChild;
//				while (p->rightChild != nullptr)
//					p = p->rightChild;
//				t->data = p->data;
//				Remove(t->leftChild, p->data);
//			}
//			else
//			{
//				p = t;
//				if (t->leftChild != nullptr)
//					t = p->leftChild;
//				else
//					t = p->rightChild;
//				delete p;
//
//				return true;
//			}
//		}
//		return false;
//	}
//	BSTNode<Type>* Search(BSTNode<Type> *t, const Type &key)
//	{
//		if (t == nullptr)
//			return nullptr;
//		if (t->data == key)
//			return t;
//		else if (key < t->data)
//			return Search(t->leftChild, key);
//		else
//			return Search(t->rightChild, key);
//	}
//	void Sort(BSTNode<Type> *t)
//	{
//		if (t != nullptr)
//		{
//			Sort(t->leftChild);
//			cout << t->data << " ";
//			Sort(t->rightChild);
//		}
//	}
//	void SortPair(BSTNode<Type> *t)
//	{
//		if (t != nullptr)
//		{
//			SortPair(t->leftChild);
//			cout << (t->data).first << ":" << (t->data).second << endl;
//			SortPair(t->rightChild);
//		}
//	}
//	void MakeEmpty(BSTNode<Type> *&t)
//	{
//		if (t != nullptr)
//		{
//			MakeEmpty(t->leftChild);
//			MakeEmpty(t->rightChild);
//			delete t;
//		}
//
//	}
//private:
//	BSTNode<Type> *root; //����
//};
//
//void main()
//{
//	//key  value  ��ֵ��
//	pair<int, string> v1 = { 1, "abc" };   //stu_id  --> name 
//	//cout<<v1.first<<" : "<<v1.second<<endl;
//	pair<int, string> v2 = { 4, "xyz" };
//	pair<int, string> v3 = { 2, "hjk" };
//
//	BST<pair<int, string>> bst;
//	bst.Insert(v1);
//	bst.Insert(v2);
//	bst.Insert(v3);
//
//	bst.SortPair();
//
//}