#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define NULL 0
typedef int Status;
typedef struct Node
{
 int elem;
 struct Node *next;
}Node,*QNode;
typedef struct
{
 QNode front;
 QNode rear;
}Queue;
#define MAX 20
typedef struct ArcNode       //头节点
{
 int adjvex;              //该边所指向的顶点的位置
 struct ArcNode *nextarc; //指向下一条边
}ArcNode;
typedef struct VNode           //表节点
{
 int data;                //顶点信息
 ArcNode *firstarc;       //指向第一条依附该节点的边的指针
}VNode,AdjList[MAX];
typedef struct
{
 AdjList vertices;     //表节点
 int vexnum;           //节点的个数
 int arcnum;           //边的条数
}Graph;
Status InitQueue(Queue *Q)
{
 Q->front=Q->rear=(QNode)malloc(sizeof(Node));
 if(!Q->front)  exit(OVERFLOW);
 Q->front->next=NULL;
 return OK;
}
Status EnQueue(Queue *Q,int e)
{
 QNode p=(QNode)malloc(sizeof(Node));
 if(!p) exit(OVERFLOW);
 p->elem=e;
 p->next=NULL;
 Q->rear->next=p;
 Q->rear=p;
 return OK;
}
Status DeQueue(Queue *Q,int *e)
{
 QNode p;
 p=Q->front->next;
 Q->front->next=p->next;
 if(Q->rear==p)
   Q->rear=Q->front;
 *e=p->elem;
 free(p);
 return OK;
}
Status QueueEmpty(Queue Q)
{
 if(Q.rear==Q.front)
   return TRUE;
 else
   return FALSE;
}
int LocateVex(Graph *G,int v)    //返回节点v在图中的位置
{
 int i;
 for(i=0;i<G->vexnum;++i)
   if(G->vertices[i].data==v)
     break;
   else
    continue;
 if(i<G->vexnum)
    return i;
 else
   return -1;
}
Status CreateGraph(Graph *G)
{//以邻接表形式创建无向连通图G
 int m,n,i,j,k,v1,v2,flag=0;
 ArcNode *p1,*q1,*p,*q;
 printf("Please input the number of VNode: ");
 scanf("%d",&m);
 printf("Please input the number of ArcNode: ");
 scanf("%d",&n);
 G->vexnum=m;            //顶点数目
 G->arcnum=n;            //边的数目
 for(i=0;i<G->vexnum;++i)
 {
   G->vertices[i].data=i+1;      //顶点信息
   G->vertices[i].firstarc=NULL;
 }
    //顶点信息
 printf("Output the message of VNode:\n");
 for(i=0;i<G->vexnum;++i)
   printf("v%d\n",G->vertices[i].data);
 for(k=0;k<G->arcnum;++k)
 {
   printf("Please input the %d edge beginpoint and endpoint: ",k+1);
   scanf("%d%d",&v1,&v2);
   i=LocateVex(G,v1);
   j=LocateVex(G,v2);
   if(i>=0&&j>=0)
   {
    ++flag;
     p=(ArcNode *)malloc(sizeof(ArcNode));
     p->adjvex=j;
     p->nextarc=NULL;
     if(!G->vertices[i].firstarc)
  G->vertices[i].firstarc=p;
     else
    {
      for(p1=G->vertices[i].firstarc;p1->nextarc;p1=p1->nextarc);
      p1->nextarc=p;
    }
     q=(ArcNode *)malloc(sizeof(ArcNode));
     q->adjvex=i;
     q->nextarc=NULL;
     if(!G->vertices[j].firstarc)
  G->vertices[j].firstarc=q;
     else
    {
 for(q1=G->vertices[j].firstarc;q1->nextarc;q1=q1->nextarc);
          q1->nextarc=q;
    }
   }
   else
   {
    printf("Not hava this edge!\n");
    k=flag;
   }
 }
printf("The Adjacency List is:\n"); //输出邻接表
 for(i=0;i<G->vexnum;++i)
 {
   printf("\t%d v%d->",i,G->vertices[i].data);
   p=G->vertices[i].firstarc;
   while(p->nextarc)
   {
    printf("%d->",p->adjvex);
    p=p->nextarc;
   }
   printf("%d\n",p->adjvex);
 }
 return OK;
}
int FirstAdjVex(Graph G,int v)
{//返回v的第一个邻接顶点
 if(G.vertices[v].firstarc)
   return G.vertices[v].firstarc->adjvex;
 else
   return -1;
}
int NextAdjVex(Graph G,int v,int w)
{//返回v中相对于w的下一个邻接顶点
 int flag=0;
 ArcNode *p;
 p=G.vertices[v].firstarc;
 while(p)
 {
   if(p->adjvex==w)
   {
    flag=1;
    break;
   }
   p=p->nextarc;
 }
 if(flag && p->nextarc)
   return p->nextarc->adjvex;
 else
   return -1;
}
int Visited[MAX];
void DFS(Graph G,int v)
{//深度优先遍历
 int w;
 Visited[v]=TRUE;
    printf("v%d ",G.vertices[v].data);
 for(w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
   if(!Visited[w])
    DFS(G,w);
}
void DFSTraverse(Graph G)
{
 int v;
 for(v=0;v<G.vexnum;++v)
   Visited[v]=FALSE;
 for(v=0;v<G.vexnum;++v)
   if(!Visited[v])
    DFS(G,v);       //递归
}
void BFSTraverse(Graph G)
{//广度优先遍历
 int v,v1,w;
 Queue q;         //定义一个队列
 for(v=0;v<G.vexnum;++v)
   Visited[v]=FALSE;
 InitQueue(&q);    //初始化队列
 for(v=0;v<G.vexnum;++v)
   if(!Visited[v])
   {
    Visited[v]=TRUE;
    printf("v%d ",G.vertices[v].data);
    EnQueue(&q,v);   //第一个顶点入队
    while(!QueueEmpty(q))
    {
     DeQueue(&q,&v1); //第一个顶点出对
     for(w=FirstAdjVex(G,v1);w>=0;w=NextAdjVex(G,v1,w))
      if(!Visited[w])
      {
       Visited[w]=TRUE;
                  printf("v%d ",G.vertices[w].data);
       EnQueue(&q,w);
      }
    }
   }
}
int main()
{
 Graph G;
 CreateGraph(&G);
 printf("Depth First Search:\n");
 DFSTraverse(G);
 printf("\nBreadth First Search:\n");
 BFSTraverse(G);
 printf("\n");
 getch();

 return 0;
}