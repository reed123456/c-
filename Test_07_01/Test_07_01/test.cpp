#include <iostream>
using namespace std;

/*
class Solution {
public:
	bool GetNodePath(TreeNode* pRoot, TreeNode* pNode, stack<TreeNode*>& path)
	{
		if (nullptr == pRoot)
			return false;

		path.push(pRoot);
		if (pNode == pRoot)
			return true;

		bool isPath = false;
		if (isPath = GetNodePath(pRoot->left, pNode, path))
			return true;

		if (isPath = GetNodePath(pRoot->right, pNode, path))
			return true;

		path.pop();
		return false;

	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (nullptr == root)
			return nullptr;

		stack<TreeNode*> pPath;
		stack<TreeNode*> qPath;
		GetNodePath(root, p, pPath);
		GetNodePath(root, q, qPath);

		size_t pSize = pPath.size();
		size_t qSize = qPath.size();
		TreeNode* pCommonAncestor = nullptr;
		while (pSize && qSize)
		{
			if (pSize > qSize)
			{
				pPath.pop();
				pSize--;
			}
			else if (pSize < qSize)
			{
				qPath.pop();
				qSize--;
			}
			else
			{
				if (pPath.top() == qPath.top())
				{
					pCommonAncestor = pPath.top();
					break;
				}
				else
				{
					pPath.pop();
					qPath.pop();
					pSize--;
					qSize--;
				}
			}
		}

		return pCommonAncestor;
	}
};
/*
int main()
{

	system("pause");
	return 0;
}

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
	int _findNode(TreeNode* root, TreeNode* n)
	{
		if (root == nullptr)
			return 0;
		if (root->val == n->val || (root->left != nullptr && root->left->val == n->val)
			|| (root->right != nullptr && root->right->val == n->val))
			return 1;
		return _findNode(root->left, n) > _findNode(root->right, n) ?
			_findNode(root->left, n) : _findNode(root->right, n);
	}
	TreeNode* _lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (p == nullptr)
			return q;
		if (q == nullptr)
			return p;
		if (root->val == p->val || root->val == q->val)
			return root;

		int r1 = _findNode(root->left, p);
		int r2 = _findNode(root->left, q);
		if (r1 != r2)
			return root;
		else if (r1 == 1 && r2 == 1)
		{
			return _lowestCommonAncestor(root->left, p, q);
		}
		else
		{
			return _lowestCommonAncestor(root->right, p, q);
		}
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		return _lowestCommonAncestor(root, p, q);
	}
};
*/