#include<iostream>
#include<vector>
using namespace std;

//现在有一个用来存放整数的Hash表，Hash表的存储单位称为桶，每个桶能放3个整数，
//当一个桶中要放的元素超过3个时，则要将新的元素存放在溢出桶中，每个溢出桶也能放3个元素，
//多个溢出桶使用链表串起来。此Hash表的基桶数目为素数P，Hash表的hash函数对P取模。代码定义如下：

#define P 7
#define NULL_DATA -1
struct bucket_node
{
	int data[3];
	struct bucket_node *next;
};
bucket_node hash_table[P];

//现在假设hash_table已经初始化好了，insert_new_element()函数目的是把一个新得值插入hash_table中，
//元素插入成功时，函数返回0，否则返回-1，完成函数。

int my_hash(int x)
{
	return x % P;
}
int Insert_new_element(int new_element)
{
	int flag = 0;
	int pos = my_hash(new_element);
	for (int i = 0; i < 3; ++i)
	{
		if (hash_table[pos]->data[i] == -1)
		{
			hash_table[pos]->data[i] == new_element;

			return 0;
		}
	}
	if (hash_table[pos]->next == nullptr)
	{
		bucket_node *b = new bucket_node;
		hash_table[pos]->next = b;
		for (int i = 0; i < 3; ++i)
		{
			if (b->data[i] == -1)
			{
				b->data[i] == new_element;
				flag = 1;
				return 0;
			}
		}
	}
	return -1;
}
int main()
{
	Init_bucket_node();
	int array[] = { 15, 14, 21, 87, 96, 293, 35, 24, 149, 19, 63, 16, 103, 77, 5, 153, 145, 356, 51, 68, 705, 453 };
	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		Insert_new_element(array[i]);
	}
	return 0;
}





/*
#include <iostream>
using namespace std;


class Solution {
public:
	void _Convert(TreeNode* pRoot, TreeNode*& pPrev)
	{
		if (nullptr == pRoot)
			return;

		_Convert(pRoot->left, pPrev);
		pRoot->left = pPrev;

		if (pPrev)
			pPrev->right = pRoot;

		pPrev = pRoot;
		_Convert(pRoot->right, pPrev);
	}

	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (nullptr == pRootOfTree)
			return nullptr;

		TreeNode* pHead = pRootOfTree;
		while (pHead->left)
			pHead = pHead->left;

		TreeNode* prev = nullptr;
		_Convert(pRootOfTree, prev);
		return pHead;
	}
};


/*
思路：
1. 从后序遍历结果中获取到树的根节点，注意：后序遍历规则：左子树、右子树、根节点，因此应该从后往前获     取根节点
2. 在中序遍历结果中确定根节点的位置，按照该位置将中序遍历结果分为两部分
右半部分是根节点的右子树，递归创建根节点的右子树---->注意先要还原根的右子树
左半部分是根节点的左子树，递归创建根节点的左子树


class Solution {
public:
	TreeNode* _buildTree(vector<int>& postorder, int& index, vector<int>& inorder, int begin, int end)
	{
		TreeNode* pRoot = nullptr;
		if (index < 0)
			return pRoot;

		pRoot = new TreeNode(postorder[index]);
		int mid = begin;
		while (mid < end)
		{
			if (inorder[mid] == postorder[index])
				break;

			mid++;
		}
		
		if (mid + 1 < end)
		{
			pRoot->right = _buildTree(postorder, --index, inorder, mid + 1, end);
		}
		
		if (begin < mid)
		{
			pRoot->left = _buildTree(postorder, --index, inorder, begin, mid);
		}
		return pRoot;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		int index = postorder.size() - 1;
		return _buildTree(postorder, index, inorder, 0, inorder.size());
	}
};
/*

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> v;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (!st.empty() || cur)
		{
			while (cur)
			{
				v.push_back(cur->val);
				st.push(cur);
				cur = cur->left;
			}
			
			TreeNode* top = st.top();
			st.pop();
			cur = top->right;
		}

		return v;
	}
};
/*
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> vRet;
		if (nullptr == root)
			return vRet;

		TreeNode* pCur = root;
		stack<TreeNode*> s;
		while (pCur || !s.empty())
		{
			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->left;
			}

			pCur = s.top();

			vRet.push_back(pCur->val);
			s.pop();

			pCur = pCur->right;
		}

		return vRet;
	}
};
/*
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		// 空树直接返回
		vector<int> vRet;
		if (nullptr == root)
			return vRet;

		TreeNode* pCur = root;
		TreeNode* pPrev = nullptr;
		stack<TreeNode*> s;
		while (pCur || !s.empty())
		{
			// 找以pCur为根的二叉树最左侧的节点，并将所经路径中的节点入栈
			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->left;
			}
			TreeNode* pTop = s.top();
			// pTop左子树已经访问
			// 如果pTop的右子树是空，或者右子树已经访问过了，就可以访问pTop
			if (nullptr == pTop->right || pPrev == pTop->right)
			{
				vRet.push_back(pTop->val);
				s.pop();
				// 将刚刚访问过的节点标记起来
				pPrev = pTop;
			}
			else
			{
				// 如果右子树没有访问，将右子树当成一棵新的二叉树访问
				pCur = pTop->right;
			}
		}
		return vRet;
	}
};


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };

class Solution {
public:
	void preorder(TreeNode* t, string &str)
	{
		if (t == nullptr)
			return;
		str += to_string(t->val);
		if (t->left == nullptr && t->right != nullptr)
		{
			str += "(";
			str += ")";
		}
		if (t->left != nullptr)
		{
			str += "(";
			preorder(t->left, str);
			str += ")";
		}
		if (t->right != nullptr)
		{
			str += "(";
			preorder(t->right, str);
			str += ")";
		}

	}
	string tree2str(TreeNode* t) {
		string str;
		preorder(t, str);
		return str;
	}
};
int main()
{
	int ar[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	system("pause");
	return 0;
}
*/