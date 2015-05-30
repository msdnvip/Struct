//头文件
#include <stdio.h>

//宏
#define TRUE 1
#define FALSE 0
#define NULL 0

//数组文件结构定义
typedef int dataType
typedef struct {
	int key;
	dataType other;
} recType;

//直接插入排序
void insertSort(recType R[], int n) {
	int i, j;
	for (i = 2; i < n; i++){
		R[0] = R[i];
		j = i - 1;
		while (R[0].key < R[j].key) {
			R[j + 1] = R[j--];
		}
		R[j + 1] = R[0];
	}
	return;
}

//冒泡排序
void bubbleSort(recType R[], int n) {
	int i, j, noSwap;
	recType temp;
	for (i = 0; i < n -2; i++){
		noSwap = TRUE;
		for(j = n -1; j >= i; j--) {
			if(R[j + 1].key < R[j].key) {
				temp = R[j + 1];
				R[j + 1] = R[j];
				R[j] = temp;
				noSwap = FALSE;
			}
			if(noSwap) {
				break;
			}
		}
	}
}
