#include<iostream>
#include<vector>
using namespace std;

//������һ���������������Hash��Hash��Ĵ洢��λ��ΪͰ��ÿ��Ͱ�ܷ�3��������
//��һ��Ͱ��Ҫ�ŵ�Ԫ�س���3��ʱ����Ҫ���µ�Ԫ�ش�������Ͱ�У�ÿ�����ͰҲ�ܷ�3��Ԫ�أ�
//������Ͱʹ��������������Hash��Ļ�Ͱ��ĿΪ����P��Hash���hash������Pȡģ�����붨�����£�

#define P 7
#define NULL_DATA -1
struct bucket_node
{
	int data[3];
	struct bucket_node *next;
};
bucket_node hash_table[P];

//���ڼ���hash_table�Ѿ���ʼ�����ˣ�insert_new_element()����Ŀ���ǰ�һ���µ�ֵ����hash_table�У�
//Ԫ�ز���ɹ�ʱ����������0�����򷵻�-1����ɺ�����

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
˼·��
1. �Ӻ����������л�ȡ�����ĸ��ڵ㣬ע�⣺������������������������������ڵ㣬���Ӧ�ôӺ���ǰ��     ȡ���ڵ�
2. ��������������ȷ�����ڵ��λ�ã����ո�λ�ý�������������Ϊ������
�Ұ벿���Ǹ��ڵ�����������ݹ鴴�����ڵ��������---->ע����Ҫ��ԭ����������
��벿���Ǹ��ڵ�����������ݹ鴴�����ڵ��������


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
		// ����ֱ�ӷ���
		vector<int> vRet;
		if (nullptr == root)
			return vRet;

		TreeNode* pCur = root;
		TreeNode* pPrev = nullptr;
		stack<TreeNode*> s;
		while (pCur || !s.empty())
		{
			// ����pCurΪ���Ķ����������Ľڵ㣬��������·���еĽڵ���ջ
			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->left;
			}
			TreeNode* pTop = s.top();
			// pTop�������Ѿ�����
			// ���pTop���������ǿգ������������Ѿ����ʹ��ˣ��Ϳ��Է���pTop
			if (nullptr == pTop->right || pPrev == pTop->right)
			{
				vRet.push_back(pTop->val);
				s.pop();
				// ���ոշ��ʹ��Ľڵ�������
				pPrev = pTop;
			}
			else
			{
				// ���������û�з��ʣ�������������һ���µĶ���������
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