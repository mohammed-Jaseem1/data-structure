#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack [SIZE];
int sp = -1;
int main()
{
int opt,data;
void push (int);
int pop();
void display();
do
{
printf("\n");
printf("1.push\n");
printf("2.pop\n");
printf("3.display\n");
printf("4.exit\n");
printf("your option:");
scanf("%d",&opt);
switch(opt)
{
case 1: printf("data:");
scanf("%d",&data);
push(data);
break;
case 2:data=pop(); 
printf("poped data:%d",data);
break;
case 3: display();
break;
case 4: exit(0);
}
}
while(1);
}
void push (int data)
{
if(sp==SIZE -1)
printf("full stack");
else
stack[++sp]=data;
}
int pop()
{
if(sp== -1)
{
printf("empty stack");
exit(0);
}
else
return stack [sp--];
}
void display()
{
int tsp=sp;
printf("stack contents:  ");
while (tsp!= -1)
{
printf("%d ", stack[tsp]);
tsp--;
}
}


