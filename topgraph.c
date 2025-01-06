#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct
{
int data;
int status;
struct node *next,point;
}
node;
typedef struct
{
int n;
struct topsort*next;
}
top sort;
int d[SIZE],f[SIZE],time;
node*q[10];
int front=0,rear=0;
node*g=0;
top sort tsort=0;
\\
void add vertex(int n)
{
node *t(node *)malloc(size of(node));
t->data=n;
t->point=0;
t->next=g;
g-t;
}
node * fint(int n)
{
noe *t=g;
wile(t!=0 && t->data!=n)
t=t->next;
return t;
}
void addedge ()int u, int v )
{
node *v1,*v2,t;
v1=find(u);
v2=find(v);
t=(node *)malloc(sizeof(node));
t->next=v1->point;
v1->point=t;
t->point=v2;
return;
}
void printgraph()
{
node *t1,*t2,*t3;
printf("\nvetrex \t edge list \n");
t1=g;
while(t1!=0)
{
printf("\n %d......\t",t1->data);
t2=t1->point;
while(t2!=0)
{
t3=t2->point;
printf("%d,",t3->data);
t2=t2->next;
}
t1=t1->next;
}
}
void topsorting(int n)
{
topsort *z=(topsort*malloc)(sizeof(topsort));
z->n=n;
z->next=tsort;
tsort=z;
}
void topsortout()
{
while(tsort!=0)
}
printf("%d, ,"tsort->n);
tsort=tsort->next;
}
}
void dfs_visit(node *u)
{
node *t,*t1;
u->status=1;
printf("%d, ,"u->data);
++time;
d[u->date]=time;
t=u->point;
while(t!=0)
{
t1=t->point;
if(t1->status==0)
dfs_visit(t1);
t=t->next;
}
++time;
f[u->data]=time
topsorting(u->data);
return;
}
void dfs(nod *g1)
{
node *t=g;
while(t!=0)
{
t->status=0;
t=t->next;
}
dfs_visit(g1);
}
void enque (node *s)
{
int r1=rear;
r1=(r1+1)%SIZE;
if(f==r1)
{
printf("q full");
exit(1);
}
rear=r1;
q[rear]=s;
}
int emptyq()
{
if(front==rear)
return 1;
else
return 0;
}
node *deque()
{
if(emptyq())
{
printf("emptyq");
exit(2);
}
front=(front+1)%SIZE;
return q[front];
}
void bfs(node *s)
{
node*t=g,*t1,*u;
while(t!=0)
{
t->status=0;
t=t->next;
}
s->status=1;
printf("%d, ",s->data
