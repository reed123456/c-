#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>
#include <string.h>

#define ElemType char

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode *root;
}BinTree;


//初始化
void BinTreeInit(BinTree *pbt);
//创建
void BinTreeCreateByStr(BinTree *bt, const char *str);
BinTreeNode* BinTreeCreateByStr_1(const char *str, int *pindex);


//判断二叉树
bool isSubtree(BinTree* s, BinTree* t);
bool _isSubtree(BinTreeNode * s, BinTreeNode * t);
bool isSameTree(BinTreeNode* p, BinTreeNode* q);

//摧毁二叉树
void BinTreeDestroy(BinTree *bt);
void BinTreeDestroy_1(BinTreeNode *t);


int main()
{                                        //测试数
	BinTree  bt_a, bt_b;                //a树 ABC##DE##F##G#H##
	char str_a[50], str_b[50];          //b树 BC##DE##F##
	printf("请输入所要创建的树A：>");       
	scanf("%s", str_a);                  
	BinTreeCreateByStr(&bt_a, str_a);    
	printf("请输入所要创建的树B：>");         
	scanf("%s", str_b);                  
	BinTreeCreateByStr(&bt_b, str_b);    
	if (isSubtree(&bt_a, &bt_b) == true)
		printf("B is a subtree of A\n");
	else
		printf("B is not a subtree of A\n");
	BinTreeDestroy(&bt_a);
	BinTreeDestroy(&bt_b);
	system("pause");
	return 0;
}
//初始化
void BinTreeInit(BinTree *pbt)
{
	pbt->root = NULL;
}


//创建二叉树(通过字符串)
void BinTreeCreateByStr(BinTree *bt, const char *str)
{
	int index = 0;
	bt->root = BinTreeCreateByStr_1(str, &index);
}
//"ABC##DE##F##G#H##";
BinTreeNode* BinTreeCreateByStr_1(const char *str, int *pindex)
{
	if (str[*pindex] == '#' || str[*pindex] == '\0')
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[*pindex];
		(*pindex)++;
		t->leftChild = BinTreeCreateByStr_1(str, pindex);
		(*pindex)++;
		t->rightChild = BinTreeCreateByStr_1(str, pindex);
		return t;
	}
}

bool isSubtree(BinTree * s, BinTree * t)
{
	return (_isSubtree(s->root, t->root));
}

bool _isSubtree(BinTreeNode * s, BinTreeNode * t)
{
	if (t == NULL)
		return true;
	if (s == NULL)
		return false;

	if (isSameTree(s, t))
		return true;
	return _isSubtree(s->leftChild, t) || _isSubtree(s->rightChild, t);
}

bool isSameTree(BinTreeNode * p, BinTreeNode * q)
{
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	return (p->data == q->data && 
		isSameTree(p->leftChild, q->leftChild) && isSameTree(p->rightChild, q->rightChild));
}



//摧毁二叉树
void BinTreeDestroy(BinTree *bt)
{
	BinTreeDestroy_1(bt->root);
}
void BinTreeDestroy_1(BinTreeNode *t)
{
	if (t == NULL)
		return;
	BinTreeDestroy_1(t->leftChild);
	BinTreeDestroy_1(t->rightChild);
	free(t);
}




/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		unsigned long long count = 1;
		while (--n)
		{
			count *= 2;
		}
		cout << count << endl;
	}
	
	system("pause");
	return 0;
}

/*
int main()
{
	//3 Joe Quan,William Letendre,Bruce
	//2 Leon Kewell
	int n;
	while (cin >> n)
	{
		vector<string> a;
		a.resize(n);
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			int pos = str.find(',');
			if (pos == string::npos)
			{
				a[i] = str;
			}
			else
			{
				a[i] += '"';
				a[i] += str;
				a[i] += '"';
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if (i != n - 1)
				cout << a[i] << ", ";
			else
				cout << a[i];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

*/