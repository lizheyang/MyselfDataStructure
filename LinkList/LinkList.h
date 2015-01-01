#ifndef GUARD_LINKLIST
#define GUARD_LINKLIST

#include "DSDefine.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct LNode {
	int              data;
	struct LNode     *next;
}*Link, *Position;

typedef struct {
	Link   head,tail;
	int    len;
}LinkList;

Position PriorPos(LinkList L, Link p);
Status ListEmpty_L(LinkList L);

Status MakeNode(Link &p, int e) {
	//分配由p指向的结点并赋值为e
	p = (Link)malloc(sizeof(struct LNode));
	if(!p) return ERROR;
	p->data =e;
	p->next = NULL;
	return OK;
}

void FreeNode(Link &p){
	//释放p所指向的结点
	free(p);
}

Status InitList_L(LinkList &L){
	//构造一个由L指向的空的线性表
	Link p;
	if(!MakeNode(p,NULL)) return ERROR;
	L.head = p;
	L.head->next = NULL;
	L.tail = L.head;
	L.len = 0;
	return OK;
}

Status DestroyList_L(LinkList &L){
	//销毁由L指向的线性表
	if(!L.head) return ERROR;
	Link p;
	p = L.tail;
	while(p != L.head)
	{
		p = PriorPos(L, p);
		FreeNode(p->next);
	}
	FreeNode(L.head);
	return OK;
}

Status ClearList_L(LinkList &L){
	//将线性表L置为空表，并释放原链表的节点空间
	if(!L.head) return ERROR;
	Link p;
	p = L.head->next;
	while(L.head->next)
	{
		p = p->next;
		FreeNode(L.head->next);
	}
	L.head->next = NULL;
	L.tail = L.head;
	return OK;
}

Status InsFirst(Link h, Link s){
	//将s指向的结点插入线性链表的第一个结点之前
	if(!h) return ERROR;
	if(!h->next) h->next = s;
	s->next = h->next;
	h->next = s;
	return OK;
}

Status DelFirst(Link h, Link &q){
	//删除表中第一个结点并以q返回
	if(!h) return ERROR;
	q = h->next;
	h->next = h->next->next;
	return OK;
}

Status Append(LinkList &L, Link s){
	//将指针s所的一串结点链接在线性表L的最后一个结点
	if(! L.head) return ERROR;
	L.tail->next = s;
	Link p = L.tail;
	while( p->next )
		p = p->next;
	L.tail = p;
	L.len++;
	return OK;
}

Status Remove(LinkList &L, Link &q){
	if(!L.head || ListEmpty_L(L)) return ERROR;
	q = L.tail;
	L.tail = PriorPos(L, L.tail);
	L.tail->next = NULL;
	return OK;
}

Status InsBefore(LinkList &L, Link &p, Link s){
	////TODO 修改指针p指向新插入的节点
	Link q;
	q = PriorPos(L, p);
	s->next = p;
	q->next = s;
	L.len++;
	return OK;
}

Status InsAfter(LinkList &L, Link &p, Link s){
	//TODO 修改指针p指向新插入的节点
	s->next = p->next;
	p->next = s;
	L.len ++;
	return OK;
}

Status SetCurElem(Link &p, int e){
	//用e更新p所指向的当前结点
	p->data = e;
	return OK;
}

int GetCurElem(Link p){
	//返回p所指结点中元素的值
	return p->data;
}

Status ListEmpty_L(LinkList L){
	//若线性表为空表则返回TRUE，否则返回FALSE
	if(L.head == L.tail)
		return TRUE;
	else return FALSE;
}

int ListLength_L(LinkList L){
	//返回线性表中元素个数
	//return L.len;
	int k;
	Link p = L.head;
	for( k=0; p->next; p=p->next,k++);
	return k;
}

Position GetHead(LinkList L){
	//返回线性表中头结点的位置
	return L.head;
}

Position GetLast(LinkList L){
	//返回线性表中最后一个结点的位置
	return L.tail;
}

Position PriorPos(LinkList L, Link p){
	//返回p所指结点的直接前驱的位置
	Link q;
	q = L.head;
	if(q->next ==p) return NULL;
	while(q->next != p)
		q = q->next;
	return q;
}

Position NextPos(LinkList L, Link p){
	//返回p所指结点的直接后继的位置
	Link q;
	if(p->next == NULL) return NULL;
	q = p->next;
	return q;
}

Status LocatePos(LinkList L, int i, Link &p){
	//用p返回线性表中第i个结点的位置，并返回ok
	if(i<1 || i>L.len) return ERROR;
	p = L.head;
	for(int j=1; j<=i; j++)
		p = p->next;
	return OK;
}

Position LocateElem(LinkList L, int e){
	//返回表中第一个与e满足一定函数关系的结点次序位置
	Link p = L.head->next;
	while(p->data != e)
	{
		if(p->data == NULL) exit (NULL);
		p = p->next;
	}
	return p;
}


Status visit(Link p){
	printf("%d ",p->data);
	return OK;
}

Status ListTraverse(LinkList L,Status (*visit)(Link)){
	//依次对线性表的每个元素调用visit(),一旦visit()失败则操作失败
	Link q;
	int i = 1;
	q = L.head->next;
	while(i < L.len)
	{
		if(visit(q))
			q = q->next;
		else
			exit (ERROR);
	}
	printf("\n");
	return OK;
}

void ListConcat(Link ha, Link hb, Link &hc){
	Link p;
	hc = ha;
	p = ha;
	while(p->next) p = p->next;
	p->next = hb->next;
}


#endif