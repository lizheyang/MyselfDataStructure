#include "SqList.h"

int main() {
	/************************************************************************/
	/* ≤‚ ‘                                                                 */
	/************************************************************************/
	SqList L,La,Lb;
	int order, temp, result;
	while(scanf("%d", &order) && order != -1) {
		switch(order) {
			//InitList a list
			case 0 : temp = InitSqList(L);
				     if (temp == OVERFLOW)
						 printf("OVERFLOW\n");
					 else
						 printf("InitList Successfully!\n");
					 break;
			//Destroy a list
			case 1 : temp = DestroySqList(L);
					 if (temp == OVERFLOW)
						 printf("OVERFLOW\n");
					 else
						 printf("Destroy Successfully!\n");
					 break;
			//Clear a list
			case 2 : temp = ClearSqList(L);
					 if (temp == OK)
						 printf("Clear Successfully!\n");
					 else
						 printf("ERROR occured in ClearList_Sq(L)!\n");
					 break;
			//If it is empty
			case 3 : temp = SqListEmpty(L);
					 if (temp == TRUE)
						 printf("The SqList is empty\n");
					 else
						 printf("The SqList is not empty\n");
					 break;
			//The length of a list
			case 4 : result = SqListLength(L);
					 if (result == ERROR)
						 printf("ERROR occured in ListLength_Sq(L)\n");
					 else
						 printf("ListLength is %d\n", result);
					 break;
			//Get the specified element
			case 5 : temp = GetElem_Sq(L, 1, result);
					 if (temp == ERROR)
						 printf("ERROR occured in GetElem_Sq(...)\n");
					 else
						 printf("The specified element is : %d\n", result);
					 break;
			//Get the prior elememt
			case 6 : temp = PriorElem_Sq(L, 2, result);
					 if (temp == ERROR)
						 printf("ERROR occured in PriorElem_Sq(...)\n");
					 else
						 printf("The prior element is : %d\n", result);
					 break;
			//Get the next element
			case 7 : temp = NextElem_Sq(L, 1, result);
					 if (temp == ERROR)
						 printf("ERROR occured in NextElem_Sq(...)\n");
					 else
						 printf("The next element is : %d\n", result);
					 break;
			//Insert the list
			case 8 : temp = SqListInsert(L, 1, 1);
					 if (temp == ERROR)
						 printf("ERROR occured in ListInsert_Sq(...)\n");
					 else if (temp == OVERFLOW)
						 printf("OVERFLOW\n");
					 else
						 printf("List insert successfully\n");
					 break;
			//Delete an element
			case 9 : temp = SqListDelete(L, 1, result);
					 if (temp == ERROR)
						 printf("ERROR occured in ListDelete_Sq(...)\n");
					 else
						 printf("Delete successfully\n");

			//Traverse the list
			case 10 : temp = SqListTraverse(L, visit);
					 if (temp == ERROR)
						 printf("ERROR occured in ListTraverse(...)\n");
					 break;

			case 11 : 
				if(!(InitSqList(La) && SqListInsert(La,1,4) && SqListInsert(La,1,3)
					&& SqListInsert(La,1,2) && SqListInsert(La,1,1)))
					exit (OVERFLOW);
				if(!(InitSqList(Lb) && SqListInsert(Lb,1,4) && SqListInsert(Lb,1,3)
					&& SqListInsert(Lb,1,2) && SqListInsert(Lb,1,1)))
					exit (OVERFLOW);
				if(!InitSqList(L)) exit (OVERFLOW);
				MergeList_Sq(La, Lb, L);
				temp = SqListTraverse(L, visit);
					 if (temp == ERROR)
						 printf("ERROR occured in ListTraverse(...)\n");
			    break;
					
		}
	}
	return 0;
}