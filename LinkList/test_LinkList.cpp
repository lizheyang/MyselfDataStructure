#include "LinkList.h"

int main()
{
	LinkList L;
	Link p;
	Position pos;
	int order,temp;
	while(scanf("%d",&order) && order != -1)
	{
		switch (order)
		{
		
		case 0: 
			temp = MakeNode(p,1);
			if(temp == ERROR)
				printf("ERROR\n");
			else
				printf("MakeNode successfully!\n");
			break;

		case 1: 
			temp = InitList_L(L);
			if(temp = ERROR)
				printf("ERROR\n");
			else
				printf("InitList successfully!\n");
			break;

		case 2:
			temp = DestroyList_L(L);
			if(temp = ERROR)
				printf("ERROR\n");
			else
				printf("DestroyList successfully!\n");
			break;

		case 3:
			temp = ClearList_L(L);
			if(temp = ERROR)
				printf("ERROR\n");
			else
				printf("ClearList successfully!\n");
			break;

		case 4:///!!!
			p->data = 2;
			temp = InsFirst(L.head, p);
			if(temp = ERROR)
				printf("ERROR\n");
			else
				printf("InsFirst successfully!\n");
			break;

		case 5:
			temp = DelFirst(L.head, p);
			if(temp = ERROR)
				printf("ERROR\n");
			else
				printf("DelFirst successfully!\n");
			break;

		case 6:
			Link s;
			MakeNode(s,3);
			temp = Append(L, s);
			if(temp = ERROR)
				printf("ERROR\n");
			else
				printf("Append successfully!\n");
			break;
		
		case 7:
			p = L.head->next;
			temp = Remove(L, p);
			if(temp = ERROR)
				printf("ERROR\n");
			else
				printf("Remove successfully!\n");
			break;

		case 8:
			//InsBefore
			break;
		case 9:
			//InsAfter
			break;
		case 10:
			p = L.head->next;
			temp = SetCurElem(p, 4);
			if(!temp)
				printf("ERROR\n");
			else
				printf("SetCurElem successfully!  %d\n",p->data);
			break;

		case 11:
			p = L.head->next;
			temp = GetCurElem(p);
			if(temp == NULL)
				printf("ERROR\n");
			else
				printf("GetGurElem successfully!   %d\n",p->data);
			break;

		case 12:
			temp = ListEmpty_L(L);
			if(temp == FALSE)
				printf("FALSE\n");
			else
				printf("TRUE\n");
			break;

		case 13:
			temp = ListLength_L(L);
			if(temp == NULL)
				printf("ERROR\n");
			else
				printf("ListLength_L successfully!   %d\n",L.len);
			break;

		case 14:
			pos = GetHead(L);
			printf("%d\n",pos->next->data);
			break;

		case 15:
			pos = GetLast(L);
			printf("%d\n", pos->data);
			break;

		case 16:
			pos = PriorPos(L, L.tail);
			if(pos == NULL)
				printf("ERROR\n");
			else
				printf("PriorPos successfully!   %d\n",pos->data);
			break;

		case 17:
			pos = NextPos(L, L.head);
			if(pos == NULL)
				printf("ERROR\n");
			else
				printf("NextPos successfully!   %d\n",pos->data);
			break;

		case 18:
			temp = LocatePos(L, 1, p);
			if(temp == ERROR)
				printf("ERROR\n");
			else
				printf("LocatePos successfully!   %d\n",p->data);
			break;

		case 19:
			pos = LocateElem(L, 3);
			if(pos == NULL)
				printf("don't have this num\n");
			else
				printf("LocateElem successfully!   %d\n",pos->data);
			break;
			break;

		case 20:
			temp = ListTraverse(L,visit);
			if (temp == ERROR)
				printf("ERROR occured in ListTraverse(...)\n");
			break;
		}
	}
	return 0;
}
