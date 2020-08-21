#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



/*
int maxSubstr(string str1, string str2)
{
	string strRet = "";
	if (str1.size() > str2.size())
	{
		string tmp = str1;
		str1 = str2;
		str2 = tmp;
	}
	for (int i = 0; i < str1.size(); ++i)
	{
		string substr = "";
		int n = str1.size() - i;
		do
		{
			substr = str1.substr(i, n--);
			if (substr.size() <= strRet.size())
				n = 0;
		} while (str2.find(substr) == string::npos && n != 0);

		if (n != 0)
		{
			strRet = strRet.size() >= substr.size() ? strRet : substr;
		}
	}
	return strRet.size();
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
		cout << maxSubstr(str1, str2) << endl;

	return 0;
}

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int _maxSubstr(string str1, string str2)
{
	for (int i = 0; i < str2.size(); ++i)
	{
		string substr = str2.substr(i, str1.size());
		if (str1 == substr)
			return str1.size();
	}
	return 0;
}

int maxSubstr(string str1, string str2)
{
	if (str1.size() > str2.size())
	{
		string tmp = str1;
		str1 = str2;
		str2 = tmp;
	}
	int max_sz = 0;
	for (int i = 0; i < str1.size(); i++)
	{
		for (int j = str1.size() - i; j > 0; j--)
		{
			 int sz = _maxSubstr(str1.substr(i, j), str2);
			 max_sz = max_sz > sz ? max_sz : sz;
		}
	}
	return max_sz;
}

int main()
{
	string str1, str2;
	//while (cin >> str1 >> str2)
	str1 = "abcfbc";
	str2 = "abfcab";
	cout << maxSubstr(str1, str2) << endl;
	system("pause");
	return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define  LEN  5
typedef  int  Elemtype;
typedef struct LNode{
	Elemtype data;
	struct LNode *next;
}LNode, *Linklist;
//单链表初始化,带头结点
void Init_Linklist(Linklist *L)
{
	*L = (Linklist)malloc(sizeof(LNode));
	assert(*L != NULL);
	(*L)->next = NULL;
}
//头插
void PushFront(Linklist *L, int item)
{
	LNode *p, *q;
	p = *L;
	q = (Linklist)malloc(sizeof(LNode));
	assert(q != NULL);
	q->data = item;
	q->next = p->next;
	p->next = q;
}
//创建单链表
void Create_Linklist(Linklist *L)
{
	int item;
	printf("请输入要插入的值[以-1结束]:>");
	while (scanf("%d", &item), item != -1)
	{
		PushFront(L, item);
	}
}

void SortList(Linklist *L)
{
	if (L == NULL)
		return;
	LNode *p = (*L)->next;
	LNode *q, *head, *cur, *prev = NULL;

	head = *L; 
	head->next = NULL;//断开链表
	while (p != NULL)
	{
		q = p->next;
		if (head->next == NULL)
		{
			p->next = head->next;
			head->next = p;
			
		}
		else
		{
			prev = head;
			cur = head->next;
			while (cur != NULL && p->data > cur->data)
			{
				prev = cur;
				cur = cur->next;
			}
			p->next = cur;
			prev->next = p;
		}
		p = q;
	}
}

LNode * mergeTwoLists(Linklist* L1, Linklist* L2)
{
	if (L1 == NULL)
		return (*L2);
	else if (L2 == NULL)
		return (*L1);

	LNode *head, *l1 = *L1, *l2 = *L2;
	if (l1->data < l2->data)
	{
		head = l1;
		l1 = l1->next;
	}
	else
	{
		head = l2;
		l2 = l2->next;
	}

	LNode *tail = head;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->data < l2->data)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	if (l1 != NULL)
		tail->next = l1;
	if (l2 != NULL)
		tail->next = l2;

	return head->next;
}

//清空链表
void ListClear(Linklist* head)
{
	LNode *p = *head;
	while (p != NULL)
	{
		*head = p->next;
		free(p);
		p = *head;
	}
}

void Print_Linklist(Linklist *L)
{
	LNode *p;
	p = (*L)->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	Linklist L, L1, L2;
	printf("请输入第一个单链表：\n");
	Init_Linklist(&L1);
	Create_Linklist(&L1);
	SortList(&L1);
	printf("请输入第二个单链表：\n");
	Init_Linklist(&L2);
	Create_Linklist(&L2);
	SortList(&L2);
	Init_Linklist(&L);
	L = mergeTwoLists(&L1, &L2);
	Print_Linklist(&L);
	ListClear(&L);
	system("pause");
	return 0;
}
*/