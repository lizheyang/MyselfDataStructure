#ifndef GUARD_SQSTACK
#define GUARD_SQSTACK

#include "DSDefine.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef char SElemType;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack_Sq(SqStack &S){
	//����һ����ջ
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S.base) exit (OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status DestoryStack_Sq(SqStack &S){
	//����ջS��S���ٴ���
	free(S.base);
	return OK;
}

Status ClearStack_Sq(SqStack &S){
	//��ջS��Ϊ��ջ
	S.top = S.base;
	return OK;
}

Status StackEmpty_Sq(SqStack &S){
	//��SΪ��ջ���򷵻�TRUE�����򷵻�FALSE
	if(S.top == S.base) 
		return TRUE;
	else
		return FALSE;
}

int StackLength_Sq(SqStack  S){
	//����S��Ԫ�ظ�������ջ�ĳ���
	return S.top-S.base;
}

Status GetTop_Sq(SqStack S, SElemType &e){
	//��ջ���գ�����e����S��ջ��Ԫ�أ������أ����򷵻�FALSE
	if(S.top == S.base) return FALSE;
	e = *(S.top -1);
	return OK;
}

Status Push_Sq(SqStack &S, SElemType e){
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if(S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType *)realloc(S.base, 
			(S.stacksize + STACKINCREMENT)* sizeof(SElemType));
		if(!S.base) exit (OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top = e;
	S.top++;
	return OK;
}

Status Pop_Sq(SqStack &S, SElemType &e){
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if(S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}

Status visit(SElemType *e){
	printf("%c ",*e);
	return OK;
}



Status StackTraverse(SqStack S, Status (*visit)(SElemType*)){
	//��visit����ջ����������
	if(S.base == S.top) return ERROR;
	SElemType *p = S.base;
	while(p != S.top)
	{
		if(visit(p))
			p++;
		else 
			return ERROR;
	}
	printf("\n");
	return OK;
}

void TrainArrange(char *train){
	//������ʹ��ϯ���ᱻ����Ӳϯ����֮ǰ
	char *p,*q;
	SqStack S;
	SElemType c;
	if(!InitStack_Sq(S)) exit (ERROR);
	while(*p)
	{
		if(*p=='H') Push_Sq(S, *p);
		else *(q++) = *p;
		p++;
	}
	while(!StackEmpty_Sq(S))
	{
		Pop_Sq(S,c);
		*(q++) = c;
	}
}

Status BracketTest(char *str){
	//�б���ʽ��С�����Ƿ�ƥ��
	int count=0;
	char* p;
	for(p=str;*p;p++)
	{
		if(*p =='(') count++;
		else if(*p =='(') count--;
		if(count<0) return ERROR;
	}
	if(count) return ERROR;
	return OK;
}


#endif