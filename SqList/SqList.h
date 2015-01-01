#ifndef GUARD_SQLIST
#define GUARD_SQLIST

#include "DSDefine.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#define LIST_INIT_SIZE  100
#define LISTINCREMENT	10

typedef struct 
{
	//定义线性顺序表的结构体   
	int *elem;
	int length;
	int listsize;
}SqList;

Status InitSqList(SqList &L){
	//构造一个空的线性表L        
	L.elem = (int *)malloc(sizeof(int)*LIST_INIT_SIZE);
	if(! L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

Status DestroySqList(SqList &L){
	//初始条件：线性表L已存在 
	//操作结果：销毁线性表L   
	if(!L.elem) exit(OVERFLOW);
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}

Status ClearSqList(SqList L){
	//初始条件：线性表L已存在 
	//操作结果：将L重置为空表     
	L.length = 0;
	return OK;
}

bool SqListEmpty(SqList L){
	//初始条件：线性表L已存在  
	// 操作结果：若L为空表，则返回TRUE，否则返回FALSE    
	if(L.length == 0) 
		return TRUE;
	else 
		return FALSE;
}

int SqListLength(SqList L){
	//初始条件：线性表L已存在  
	// 操作结果：返回L中数据元素个数      
	return L.length;
}

Status GetElem_Sq(SqList L, int i, int &e){
	//初始条件:线性表L已存在，1<=i<=ListLength_Sq(L) 
	// 操作结果:用e返回L中第i个数据元素的值    
	if(i<1 || i>L.length)
		return ERROR;
	e = L.elem[i-1];
	return OK;
}

Status PriorElem_Sq(SqList L, int cur_e, int &pre_e){
	//初始条件:线性表L已存在  
	//操作结果:若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱,
	//否则操作失败，pre_e无定义 
	for(int i=0; i<L.length; i++)
	{
		if(cur_e == L.elem[i])
		{
			if(i == 1) return ERROR;
			else {pre_e = L.elem[i-1]; return OK;}
		}
	}
}

Status NextElem_Sq(SqList L, int cur_e, int &next_e){
	//初始条件:线性表L已存在   
	//操作结果:若cur_e是L的数据元素，且不是最后一个，则用pre_e返回它的后继
	//否则操作失败，next_e无定义  
	for(int i=0; i<L.length; i++)
	{
		if(cur_e == L.elem[i])
		{
			if(i == L.length-1) return ERROR;
			else {next_e = L.elem[i+1]; return OK;}
		}
	}
}

Status SqListInsert(SqList &L, int i, int e){
	//初始条件：线性表L已存在,1<=i<=ListLength(L)+1  
	//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1  
	if(i<1 || i>L.length+1) return ERROR;
	if(L.length >= L.listsize)
	{
		int *newbase = (int*)malloc((L.listsize+LISTINCREMENT)*sizeof(int));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	int *q = &(L.elem[i-1]);
	for(int *p = &(L.elem[L.length-1]); p>=q; --p)
		*(p+1) = *p;
	*q = e;
	++L.length;
	return OK;
}

Status SqListDelete(SqList &L, int i, int &e){
	//初始条件：线性表L已存在,1<=i<=ListLength(L)+1  
	// 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 
	if(i<1 || i>L.length) return ERROR;
	int* p = &(L.elem[i-1]);
	e = *p;
	int* q = L.elem + L.length -1;      
	for(++p; p<=q; ++p) *(p-1) = *p;
	--L.length;
	return OK;
}

Status visit(int e){
	printf("%d ",e);
	return OK;
}

Status SqListTraverse(SqList L, Status (*visit)(int)){
	//初始条件：线性表L已存在 
	//操作结果：依次对L的每个数据元素调用函数visit()。直到visit()失败
	int i=1;
	while(i <= L.length)
	{
		if(visit(L.elem[i-1]))
			i++;
		else
			return ERROR;
	}
	printf("\n");
	return OK;
}

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc){
	int *pa,*pb,*pc;
	int *pa_last,*pb_last;
	pa = La.elem;
	pb = Lb.elem;
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (int*)malloc(Lc.listsize*sizeof(int));
	if(!Lc.elem) exit (OVERFLOW);
	pa_last = La.elem + La.length -1;
	pb_last = Lb.elem + Lb.length -1;
	while(pa<=pa_last && pb<=pb_last)
	{
		if(*pa <= *pb) *pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while(pa<=pa_last) *pc++ = *pa++;
	while(pb<=pb_last) *pc++ = *pb++;

}


#endif