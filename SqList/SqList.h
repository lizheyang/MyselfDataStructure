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
	//��������˳���Ľṹ��   
	int *elem;
	int length;
	int listsize;
}SqList;

Status InitSqList(SqList &L){
	//����һ���յ����Ա�L        
	L.elem = (int *)malloc(sizeof(int)*LIST_INIT_SIZE);
	if(! L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

Status DestroySqList(SqList &L){
	//��ʼ���������Ա�L�Ѵ��� 
	//����������������Ա�L   
	if(!L.elem) exit(OVERFLOW);
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}

Status ClearSqList(SqList L){
	//��ʼ���������Ա�L�Ѵ��� 
	//�����������L����Ϊ�ձ�     
	L.length = 0;
	return OK;
}

bool SqListEmpty(SqList L){
	//��ʼ���������Ա�L�Ѵ���  
	// �����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE    
	if(L.length == 0) 
		return TRUE;
	else 
		return FALSE;
}

int SqListLength(SqList L){
	//��ʼ���������Ա�L�Ѵ���  
	// �������������L������Ԫ�ظ���      
	return L.length;
}

Status GetElem_Sq(SqList L, int i, int &e){
	//��ʼ����:���Ա�L�Ѵ��ڣ�1<=i<=ListLength_Sq(L) 
	// �������:��e����L�е�i������Ԫ�ص�ֵ    
	if(i<1 || i>L.length)
		return ERROR;
	e = L.elem[i-1];
	return OK;
}

Status PriorElem_Sq(SqList L, int cur_e, int &pre_e){
	//��ʼ����:���Ա�L�Ѵ���  
	//�������:��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ��,
	//�������ʧ�ܣ�pre_e�޶��� 
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
	//��ʼ����:���Ա�L�Ѵ���   
	//�������:��cur_e��L������Ԫ�أ��Ҳ������һ��������pre_e�������ĺ��
	//�������ʧ�ܣ�next_e�޶���  
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
	//��ʼ���������Ա�L�Ѵ���,1<=i<=ListLength(L)+1  
	//�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1  
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
	//��ʼ���������Ա�L�Ѵ���,1<=i<=ListLength(L)+1  
	// ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 
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
	//��ʼ���������Ա�L�Ѵ��� 
	//������������ζ�L��ÿ������Ԫ�ص��ú���visit()��ֱ��visit()ʧ��
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