#define _CRT_SECURE_NO_WARNINGS			//在Visual Studio中定义的宏
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0


//头文件
#include <stdio.h>

/*
实验方法
第一步：定义顺序表的存储结构。
第二步：编写顺序表操作的具体函数定义。
第三步：使用定义的顺序表并调用顺序表的一些操作、实现具体运算。
具体函数的定义有：
（1）	insert(L,i,x)在顺序表的第i个元素之前插入一个新元素x。
（2）	delete (L,i) 删除顺序表的第i个元素。
（3）	listprint(L) 输出顺序表。

书本上关于顺序表结构的定义
typedef int datatype;			//datatype可为任何类型，这里假设为int
#define maxsize 1024		//线性表的最大长度
typedef struct{
	datatype data[maxsize];			//定义线性表是向量，以一个节点data[0]
	int last;
} sequenlist;
*/

//定义顺序表结构
typedef int elementType;
typedef struct node{
	elementType data[MAXSIZE];			//顺序表数据成员所占据的存储空间
	int last;			//顺序表中最后一个元素在数组中的下标(从0开始)
}sequenceList;

//插入操作（将新节点x插入到顺序表L的第i（非下标）个位置上）
int insertElement(sequenceList* L, int i, elementType x){
	int j;
	if ((L->last) >= MAXSIZE - 1){			//表空间溢出
		printf("Insert failed, List is overflow!\n");
		return FALSE;
	}
	else{
		if ((i < 1) || (i >(L->last + 1))){			//非法位置
			printf("Insert failed, Illegal position!\n");
			return FALSE;
		}
		else{
			for (j = L->last; j >= (i - 1); j--){			/*节点后移*/
				L->data[j + 1] = L->data[j];
			}
			L->data[i - 1] = x;			//把x插入到第i个位置
			L->last++;			//终端节点的下标加1
			return TRUE;
		}
	}
}

//删除操作（在顺序表L中删除第i（非下标）个位置的节点）
int deleteElement(sequenceList* L, int i){
	int j;
	if ((i < 1) || (i >(L->last + 2))){			//非法位置
		printf("Delete failed, Illegal position!\n");
		return FALSE;
	}
	else{
		for (j = i; j <= L->last; j++){			//第i个节点的下标值是i-1
			L->data[j - 1] = L->data[j];			//前移元素，覆盖掉要删除元素的值
		}
		L->last--;			//表长减一
		return TRUE;
	}
}

//遍历操作（输出线性表L中所有元素的值）
void printSequenceList(sequenceList* L){
	int i;
	printf("Sequence list at this time:\n");
	for (i = 0; i <= L->last; i++){
		printf("Index = %d, Value = %d\n", i, L->data[i]);
	}
	return;
}

//定位操作
int locateElement(sequenceList* L, int x){
	int i;
	for (i = 0; i <= L->last; i++){
		if (L->data[i] == x){
			printf("The first location of %d is:%d\n", x, i + 1);
			return TRUE;
		}
	}
	printf("Locate failed, Not such element!\n");
	return FALSE;
}

//逆置操作
void diverseList(sequenceList* L){
	int i, tmp;
	float centerIndex = (float)(L->last + 2) / 2;
	for (i = 0; (float)i < centerIndex - 1; i++){
		tmp = L->data[L->last - i];
		L->data[L->last - i] = L->data[i];
		L->data[i] = tmp;
	}
	return;
}

//删除重复操作
void deleteSame(sequenceList* L){
	int i, j, k;
	for (i = 0; i < L->last; i++){
		j = i + 1;
		for (; j <= L->last; j++){
			if (L->data[i] == L->data[j]){
				for (k = j; k <= L->last; k++){
					L->data[k] = L->data[k + 1];
				}
				L->last--;
			}
		}
	}
	return;
}

//主函数
int main(){
	sequenceList sqenceList = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }, 21 };			//手工初始化顺序表
	sequenceList *L;			//定义一个指向顺序表类型的指针变量
	int i, j, x, y;
	L = &sqenceList;
	printSequenceList(L);
	printf("Please input the insert position and insert value:\n");
	scanf("%d%d", &i, &x);
	printf("The insert position:%d, insert value:%d\n", i, x);
	if (!insertElement(L, i, x)){
		return 0;
	}
	printSequenceList(L);
	printf("Please intput the delete position:\n");
	scanf("%d", &j);
	printf("The delete position:%d\n", j);
	if (!deleteElement(L, j)){
		return 0;
	}
	printSequenceList(L);
	printf("Please intput a integer you want to locate:\n");
	scanf("%d", &y);
	printf("The locate element:%d\n", y);
	if (!locateElement(L, y)){
		return 0;
	}
	printf("Diverse operation is carried out......\n");
	diverseList(L);
	printSequenceList(L);
	printf("Delete the same element is carried out......\n");
	deleteSame(L);
	printSequenceList(L);
	return 0;
}