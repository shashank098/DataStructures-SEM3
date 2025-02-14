#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *Node;

Node getnode()
{
Node x;
x=(Node)malloc(sizeof(Node));
if(x!=NULL)
return x;
else
{
printf("Memory not allocated\n");
exit(0);
}
return(0);
}
Node push(Node first,int item)
{
    Node x,curr;
    x=getnode();
    x->data=item;
    x->next=NULL;
    if(first==NULL)
    return x;

    else
    {
curr=first;
while(curr->next!=NULL)
{
curr=curr->next;
}
curr->next=x;
    }
    return first;
}
Node pop(Node first)
{       Node temp,prev;
if(first==NULL)
{
printf("List is empty");
}
temp=first;
prev=NULL;
while(temp->next!=NULL)
{
prev=temp;
temp=temp->next;
}
printf("Deleted item: %d\n",temp->data);
prev->next=NULL;
free(temp);

return first;
}
Node reverse(Node first)
{
Node curr,prev,temp;
prev=NULL;
curr=first;
while(curr!=NULL)
{
temp=curr->next;
curr->next=prev;
prev=curr;
curr=temp;
}
first=prev;
return first;
}
Node disp_stack(Node first)
{
Node temp;
if(first==NULL)
printf("List is empty\n");
else
{
temp=first;
printf("Elements in the list:\n");
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->next;
}
printf("\n");
}
first=reverse(first);
return(first);
}

Node enqueue(Node first1,int item)
{
    Node x,curr;
    x=getnode();
    x->data=item;
    x->next=NULL;
    if(first1==NULL)
    return x;

    else
    {
curr=first1;
while(curr->next!=NULL)
{
curr=curr->next;
}
curr->next=x;
    }
    return first1;
}
Node dequeue(Node first1)
{
Node temp;
if(first1==NULL)
printf("List is empty\n");
else
{
temp=first1;
printf("Deleted item: %d\n",temp->data);
temp=temp->next;
free(first1);
}
return temp;
}
void disp_queue(Node first1)
{
Node temp;
if(first1==NULL)
printf("List is empty\n");
else
{
temp=first1;
printf("Elements in the list :\n");
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->next;
}
printf("\n");
}
}
void main()
{
Node first=NULL;
Node first1=NULL;
int value;
int n;
while(1)
{
printf("1.Push element into stack\n");
printf("2.Pop element from stack\n");
printf("3.Display the contents of stack\n");
printf("4.Enter element intp queue\n");
printf("5.Delete element from queue\n");

printf("6.Display the contents of queue\n");
printf("7.exit\n");
scanf("%d",&n);
switch(n)
{
case 1:printf("Enter element to be pushed\n");
scanf("%d",&value);
first=push(first,value);
break;
case 2:first=pop(first);
break;
case 4:printf("Enter element to enqueue\n");
scanf("%d",&value);
first1=enqueue(first1,value);
break;
case 5:first1=dequeue(first1);
break;
case 3:first=reverse(first);
first=disp_stack(first);
break;
case 6:disp_queue(first1);
break;
case 7:exit(0);
default:printf("Invalid choice\n");
}
}

}
