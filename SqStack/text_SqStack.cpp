#include "SqStack.h"

int main()
{
	SqStack S;
	SElemType e;
	int order,temp;
	while(scanf("%d",&order) && order != -1)
	{
		switch (order)
		{
		case 0:
			temp = InitStack_Sq(S);
			if (temp == OVERFLOW)
				printf("OVERFLOW\n");
			else
				printf("InitStack_Sq Successfully!\n");
			break;

		case 1:
			temp = DestoryStack_Sq(S);
			if (temp == OVERFLOW)
				printf("OVERFLOW\n");
			else
				printf("DestoryStack_Sq Successfully!\n");
			break;

		case 2:
			temp = ClearStack_Sq(S);
			if (temp == OVERFLOW)
				printf("OVERFLOW\n");
			else
				printf("ClearStack_Sq Successfully!\n");
			break;

		case 3:
			temp = StackEmpty_Sq(S);
			if(temp == TRUE)
				printf("The stack is empty!\n");
			else 
				printf("The stack is not empty!\n");
			break;

		case 4:
			temp = StackLength_Sq(S);
			printf("The stack's length is %d\n",temp);
			break;

		case 5:
			temp = GetTop_Sq(S,e);
			if (temp == FALSE)
				printf("the stcak is empty\n");
			else
				printf("The top element of the stack is %d\n",e);
			break;

		case 6:
			temp = Push_Sq(S, 'a');
			if (temp == OVERFLOW)
				printf("OVERFLOW\n");
			else
				printf("Push_Sq Successfully!\n");
			break;

		case 7:
			temp = Pop_Sq(S,e);
			if (temp == ERROR)
				printf("the stcak is empty\n");
			else
				printf("Pop_Sq Successfully! Deleted elem is %c\n",e);
			break;

		case 8:
			temp = StackTraverse(S,visit);
			if (temp == ERROR)
				printf("ERROR occured in StackTraverse(...)\n");
			break;
		}
	}


}
