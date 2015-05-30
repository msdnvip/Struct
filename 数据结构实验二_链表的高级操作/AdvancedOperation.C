#define _CRT_SECURE_NO_WARNINGS			//在Visual Studio中定义的宏
#define TRUE 1
#define FALSE 0
#define NULL 0


//头文件
#include <stdio.h>
#include <stdlib.h>

/*
实验方法
第一步：定义单链表的存储结构。
第二步：编写单链表操作的具体函数定义。
第三步：使用定义的单链表并调用单链表的一些操作，实现具体运算。
具体函数的定义有：
（1）	insert(L,i,x)在单链表的第i个元素之前插入一个新元素x.
（2）	deletet(L,i) 删除单链表的第i个元素。
（3）	listprint(L) 输出单链表。


书本上关于单链表的定义
typedef int datatype;			//datatype可为任何类型，这里假设为int
typedef struct node{
datatype data;
struct node* next;
} linklist;
linklist* head,p;
*/

typedef int dataType;			//dataType可为任何类型，这里假设为int
typedef struct node{
	dataType data;
	struct node* next;
} linkList;

//单链表的逆序_待看
void reverseList(linkList *L){
	printf("开始逆序...\n");
	if ((NULL == L) || (NULL == L->next)){			//边界检测
		return;
	}
	linkList *pPre = L;			//先前指针
	linkList *pCur = pPre->next;			//当前指针
	linkList *pNext = NULL;			//后继指针
	while (pCur != NULL){
		pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	L->next = NULL;
	L = pPre;        //记录下新的头结点
	return;
}

//单链表的逆序二_待看
void reverseLink(linkList *L){
	if (NULL == L)
	{
		return;
	}
	linkList *pNode = L;
	linkList *Prev = NULL;
	linkList *pNext = NULL;
	while (NULL != pNode){
		pNext = pNode->next;
		if (NULL == pNext)
		{
			L = pNode;
		}
		pNode->next = Prev;
		Prev = pNode;
		pNode = pNext;
	}
}

//删除重复元素
void deleteSame(linkList *L){
	linkList *p;	//第一个遍历指针
	linkList *q;	//第二个遍历指针
	linkList *r;	//辅助指针
	p = L->next;	//使第一个遍历指针p指向开始节点
	while (p){
		q = p;
		while (q->next){
			if (q->next->data == p->data){
				r = q->next;			//辅助指针指向相同两个元素中，位置靠后的那个元素
				q->next = r->next;		//使q所在的节点的后继为上述节点的后继
				free(r);
			}
			else
				q = q->next;
		}
		p = p->next;
	}
	return L;
}