#ifndef GUARD_HSTRING
#define GUARD_HSTRING

#include "DSDefine.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char * ch;
	int    length;
}HString;

void InitStr(HString &S){
	S.ch = NULL;
	S.length =0;
}


Status StrAssign(HString &T, char* chars){
	char* c;
	int i;
	if(T.ch) free(T.ch);
	for(i=0,c=chars; *c; ++i,++c);
	if(!i) {T.ch=NULL; T.length=0;}
	else {
		if(!(T.ch=(char*)malloc(i*sizeof(char))))
			exit (OVERFLOW);
		T.length = i;
		for(i=0; i<T.length; i++)
			T.ch[i] = chars[i];
	}
	return OK;
}

Status StrCopy(HString &T, HString S){
	if(T.ch) free(T.ch);
	T.ch = (char*)malloc(S.length*(sizeof(char)));
	T.length = S.length;
	for(int i=0; i<T.length; i++)
		T.ch[i] = S.ch[i];
	return OK;
}


int StrLength(HString S){
	return S.length;
}

int StrCompare(HString S, HString T){
	for(int i=0; i<S.length&&i<T.length; i++)
		if(S.ch[i] != T.ch[i]) return S.ch[i]-T.ch[i];
	return S.length-T.length;
}

Status ClearString(HString &S){
	if(S.ch) {free(S.ch); S.ch=NULL;}
	S.length =0;
	return OK;
}

Status Concat(HString &T, HString S1, HString S2){
	if(T.ch) free(T.ch);
	if(!(T.ch = (char*)malloc((S1.length+S2.length)*sizeof(char))))
		exit (OVERFLOW);
	for(int i=0; i<S1.length; i++)
		T.ch[i] = S1.ch[i];
	T.length = S1.length + S2.length;
	for(int i=S1.length; i<T.length; i++)
		T.ch[i] = S2.ch[i-S1.length];
	return OK;
}

Status SubString(HString &Sub, HString S, int pos, int len){
	if(pos<1 || pos>S.length || len<0 || len>S.length-pos+1)
		return ERROR;
	if(Sub.ch) free(Sub.ch);
	if(!len) {Sub.ch=NULL; Sub.length = 0;}
	else {
		Sub.ch = (char*)malloc(len*sizeof(char));
		for(int i=0; i<len; i++)
			Sub.ch[i] = S.ch[i+pos-1];
		Sub.length = len;
	}
	return OK;
}

int DeleteSubString(HString &S, HString T){
	//从串s中删除所有和串t相同的子串，返回删除次数
	int n,i;
	HString sub,head,tail;
	InitStr(sub);
	InitStr(head);
	InitStr(tail);
	for(n=0,i=1; i<=S.length-T.length+1; i++)
	{
		SubString(sub, S, i, T.length);
		if(!StrCompare(sub, T))
		{
			SubString(sub, S, 1, i-1);
			StrCopy(head, sub);
			SubString(sub, S, i+T.length, S.length-i-T.length+1);
			StrCopy(tail, sub);
			Concat(S, head, tail);
			n++;
		}
	}
	return n;
}

Status visit(HString S)
{
	if(S.ch == NULL) {printf("the string is empty\n"); return ERROR;}
	for(int i=0; i<S.length; i++)
		printf("%c ",S.ch[i]);
	printf("\n");
	return OK;
}

#endif