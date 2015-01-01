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
	//������pָ��Ľ�㲢��ֵΪe
	p = (Link)malloc(sizeof(struct LNode));
	if(!p) return ERROR;
	p->data =e;
	p->next = NULL;
	return OK;
}

void FreeNode(Link &p){
	//�ͷ�p��ָ��Ľ��
	free(p);
}

Status InitList_L(LinkList &L){
	//����һ����Lָ��Ŀյ����Ա�
	Link p;
	if(!MakeNode(p,NULL)) return ERROR;
	L.head = p;
	L.head->next = NULL;
	L.tail = L.head;
	L.len = 0;
	return OK;
}

Status DestroyList_L(LinkList &L){
	//������Lָ������Ա�
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
	//�����Ա�L��Ϊ�ձ����ͷ�ԭ����Ľڵ�ռ�
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
	//��sָ��Ľ�������������ĵ�һ�����֮ǰ
	if(!h) return ERROR;
	if(!h->next) h->next = s;
	s->next = h->next;
	h->next = s;
	return OK;
}

Status DelFirst(Link h, Link &q){
	//ɾ�����е�һ����㲢��q����
	if(!h) return ERROR;
	q = h->next;
	h->next = h->next->next;
	return OK;
}

Status Append(LinkList &L, Link s){
	//��ָ��s����һ��������������Ա�L�����һ�����
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
	////TODO �޸�ָ��pָ���²���Ľڵ�
	Link q;
	q = PriorPos(L, p);
	s->next = p;
	q->next = s;
	L.len++;
	return OK;
}

Status InsAfter(LinkList &L, Link &p, Link s){
	//TODO �޸�ָ��pָ���²���Ľڵ�
	s->next = p->next;
	p->next = s;
	L.len ++;
	return OK;
}

Status SetCurElem(Link &p, int e){
	//��e����p��ָ��ĵ�ǰ���
	p->data = e;
	return OK;
}

int GetCurElem(Link p){
	//����p��ָ�����Ԫ�ص�ֵ
	return p->data;
}

Status ListEmpty_L(LinkList L){
	//�����Ա�Ϊ�ձ��򷵻�TRUE�����򷵻�FALSE
	if(L.head == L.tail)
		return TRUE;
	else return FALSE;
}

int ListLength_L(LinkList L){
	//�������Ա���Ԫ�ظ���
	//return L.len;
	int k;
	Link p = L.head;
	for( k=0; p->next; p=p->next,k++);
	return k;
}

Position GetHead(LinkList L){
	//�������Ա���ͷ����λ��
	return L.head;
}

Position GetLast(LinkList L){
	//�������Ա������һ������λ��
	return L.tail;
}

Position PriorPos(LinkList L, Link p){
	//����p��ָ����ֱ��ǰ����λ��
	Link q;
	q = L.head;
	if(q->next ==p) return NULL;
	while(q->next != p)
		q = q->next;
	return q;
}

Position NextPos(LinkList L, Link p){
	//����p��ָ����ֱ�Ӻ�̵�λ��
	Link q;
	if(p->next == NULL) return NULL;
	q = p->next;
	return q;
}

Status LocatePos(LinkList L, int i, Link &p){
	//��p�������Ա��е�i������λ�ã�������ok
	if(i<1 || i>L.len) return ERROR;
	p = L.head;
	for(int j=1; j<=i; j++)
		p = p->next;
	return OK;
}

Position LocateElem(LinkList L, int e){
	//���ر��е�һ����e����һ��������ϵ�Ľ�����λ��
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
	//���ζ����Ա��ÿ��Ԫ�ص���visit(),һ��visit()ʧ�������ʧ��
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