#include "HString.h"


int main() {
	int i;
	char* str1 = "abcdeabcfg";
	char* str2 = "abc";
	HString S,S1,S2;
	InitStr(S);
	InitStr(S1);
	InitStr(S2);
    StrAssign(S1, "abcdeabcfg");
	StrAssign(S2, "abc");
	visit(S1);
	visit(S2);
	i = StrCompare(S1, S2);
	printf("%d\n",i);
	Concat(S,S1,S2);
	visit(S);
	ClearString(S1);
	visit(S1);
	SubString(S1,S,2,5);
	visit(S1);
	DeleteSubString(S,S2);
	visit(S);
	return 0;
}