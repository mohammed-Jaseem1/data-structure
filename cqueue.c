#include<stdio.h>
#include<stdlib.h>
#define size 10
int queue[size];
int front=0,rear=0;
void main()
{
void insertq(int);
void deleteq();
int searchq(int);
int data,opt;
do
{
printf("\n1.Insert\n");
printf("2.Delete\n");
printf("3.Search\n");
printf("4.Exit\n");
printf("Enter your option :");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("Enter data :");
scanf("%d",&data);
insertq(data);
break;
case 2:deleteq();
break;
case 3:
if(front == rear)
printf("\nqueue is empty\n");
else
{
printf("enter the to search:");
scanf("%d",&data);
if(searchq(data))
printf("\n:Found the searched item\n");
else
printf("\n:The searched item not found\n");
}
break;
case 4:
exit(0);
default:printf("\n enter the valide choice:");
break;
}
}
while(1);
}
void insertq(int data)
{
int trear=(rear+1)%size;
if(trear==front){
printf("Queue is full");
}else{
rear=trear;
queue[rear]=data;
}
}

void deleteq()
{
if(front==rear)
{
printf("Queue is empty\n");
}
else
{
front=(front+1)%size;
printf("\n[%d]seleted from queue\n",queue[front]);
}
}
int searchq(int item)
{
int tfront;
tfront=(front+1)%size;
while(tfront!=rear && queue[tfront]!=item)
tfront=(tfront+1)%size;
if(queue[tfront]==item)
return 1;
return 0;
}


