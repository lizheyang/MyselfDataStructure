#ifndef GUARD_BITREE
#define GUARD_BITREE

#include "DSDefine.h"
#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef char TElemType ;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

Status InitBiTree(BiTree &T){
	BiTree = NULL;
	return OK;
}

Status CreateBiTree(BiTree &T){
	char ch;
	scanf("%c",&ch);
	if(ch==' ') T=NULL;
	else {
		if(!(T = (BiTree *)malloc(sizeof(BiTNode)))) 
			exit (OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

Status visit_BiTree(TElemType e){
	printf("%c ",e);
	return OK;
}


Status PreOrder(BiTree T, Status(*visit_BiTree)(TElemType)){
	if(T){
		if(visit_BiTree(T->data))
			if(PreOrder(T->lchild,visit_BiTree))
				if(PreOrder(T->rchild,visit_BiTree))
					return OK;
		return ERROR;
	}
	else return OK;
}

Status PreOrder_Stack(BiTree T){
	//没有递归的先序遍历
	SqStack S;
	SElemType p;
	InitStack_Sq(S);
	Push_Sq(S, T);
	while(!StackEmpty_Sq(S)){
		while(GetTop_Sq(S,p)&&p){
			visit(p->data);
			Push_Sq(S,p->lchild);
		}
		Pop_Sq(S,p);
		if(!StackEmpty_Sq(S)){
			Pop_Sq(S,p);
			Push_Sq(S,p->rchild);
		}
	}
	return OK;
}

typedef struct {
	BiTNode * ptr;
	enum mark {o=0,l=1,z=2};
}PMType;

Status PostOrder_Stack(BiTree T){
	PMType a;
	SqStack S;
	InitStack_Sq(S);
	Push_Sq(S,{T,1});

}









#endif