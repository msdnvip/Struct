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

//头插法创建单链表（创建链表函数以按下任意建开始创建，以输入字符'?'表示结束标志）
linkList *headCreatList(){
	char ch;
	linkList *head, *s;
	head = NULL;			//链表开始为空
	ch = getchar();			//读入第一个节点信息
	while (ch != '?'){
		s = (linkList *)malloc(sizeof(linkList));
		s->data = ch;
		s->next = head;
		head = s;			//将新节点插入到表头上
		ch = getchar();
	}
	return (head);
}

//没有头节点的尾插法创建链表
linkList *noHeadNodeTailCreateList(){
	char ch;
	linkList *head, *s, *r;
	head = NULL;			//链表初值为空
	r = NULL;			//尾指针初值为空
	ch = getchar();
	while (ch != '?'){
		s = (linkList *)malloc(sizeof(linkList));			//生成新节点
		s->data = ch;
		if (head == NULL){			//新节点s插入空表
			head = s;
		}
		else{
			r->next = s;
			r = s;
			ch = getchar();
		}
		if (r != NULL){
			r->next = NULL;
		}
		return (head);
	}
}

//有头节点的尾插法创建链表
linkList *withHeadNodeTailCreateList(){
	char ch;
	linkList *head, *s, *r;
	head = (linkList *)malloc(sizeof(linkList));			//生成头节点head
	r = head;			//尾指针初值指向头节点
	ch = getchar();
	while (ch != '?'){
		s = (linkList *)malloc(sizeof(linkList));
		s->data = ch;
		r->next = s;
		r = s;
		ch = getchar();
	}
	r->next = NULL;
	return (head);
}

//定位操作（按值查找）
int locateNodeByValue(linkList *head, int k){
	linkList *p;
	p = head->next;			//从开始节点比较
	while (p != NULL){
		if (s->data != k){
			s = s->next;
		}
		else{
			return TRUE;
		}
	}
	return FALSE;
}

//在任意位置插入操作
int insertElementEveryWhere(linkList *head, int i, dataType x)/*在链表head的第i个位置插入元素x*/
{
	linkList *s, *p = head;
	int j = 0;
	while (p->next && (j<i - 1)){
		p = p->next;
		j++;
	}
	if (!p || (j>i - 1)){
		printf("Insert failed, Illegal position!\n");
		return FALSE;
	}
	s = (linkList *)malloc(sizeof(linkList));
	if (!s){
		printf("Insert failed, List is overflow!\n");
		return FALSE;
	}
	s->data = x;
	s->next = p->next;
	p->next = s;
	return TRUE;
}

//删除链表L的第i个节点
void delete(linkList *head, int i){
	int j = 0;
	linkList *p = head, *s, *q;
	while ((p->next != NULL) && (j < i - 1)){
		p = p->next;
		j++;
	}
	if (p->next != NULL){
		q = p->next;
		p->next = p->next->next;
		free(q);
	}
	else{
		printf("Delete failed, Illegal position!\n");
	}
}

//遍历链表并打印
void print(linkList *head){
	linkList *p;
	p = head->next;
	while (p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return; 
}

//删除重复元素
//删除重复操作
void deleteSame(linkList *L){
	int i;
	linkList *s;
	while (L->next != NULL){
		s->next = L->next;
		for (; s->next != NULL; s = s->next){
		}
	}
	return;
}
