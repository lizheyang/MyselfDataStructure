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
	//构造一个空栈
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S.base) exit (OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status DestoryStack_Sq(SqStack &S){
	//销毁栈S，S不再存在
	free(S.base);
	return OK;
}

Status ClearStack_Sq(SqStack &S){
	//把栈S置为空栈
	S.top = S.base;
	return OK;
}

Status StackEmpty_Sq(SqStack &S){
	//若S为空栈，则返回TRUE，否则返回FALSE
	if(S.top == S.base) 
		return TRUE;
	else
		return FALSE;
}

int StackLength_Sq(SqStack  S){
	//返回S的元素个数，即栈的长度
	return S.top-S.base;
}

Status GetTop_Sq(SqStack S, SElemType &e){
	//若栈不空，则用e返回S的栈顶元素，并返回，否则返回FALSE
	if(S.top == S.base) return FALSE;
	e = *(S.top -1);
	return OK;
}

Status Push_Sq(SqStack &S, SElemType e){
	//插入元素e为新的栈顶元素
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
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
	if(S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}

Status visit(SElemType *e){
	printf("%c ",*e);
	return OK;
}



Status StackTraverse(SqStack S, Status (*visit)(SElemType*)){
	//用visit遍历栈，出错即返回
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
	//火车排序，使软席车厢被调至硬席车厢之前
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
	//判别表达式中小括号是否匹配
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