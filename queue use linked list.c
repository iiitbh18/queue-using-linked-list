#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
}*front=NULL,*rear=NULL;
void push();
int pop();
int isempty();
int ispeek();
void display();
main()
{
    int choice,item;
    while(1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.peek\n");
        printf("5.quit\n");
        printf("enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the element to be inserted");
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            item=pop();
            printf("popped item is:");
            break;
        case 3:
            display();
            break;
        case 4:
            printf("%d elemant at peek",ispeek());
            break;
        case 5:
            exit(1);
        default:
            printf("choice is wrong");
        }
    }
}

 void push(int item)
 {
     struct node *temp;
     temp=(struct node *)malloc(sizeof(struct node));
     if(temp==NULL)
     {
         printf("queue is overflow");
         return;
     }
     temp->info=item;
     temp->link=NULL;
     if(front==NULL)
        front=temp;
     else
        rear->link=temp;
     rear=temp;

 }
int isempty()
{
    if(front==NULL)
        return 1;
    else
        return 0;

}
int pop()
{
    int item;
    struct node *temp,*p;
    if(isempty())
    {
        printf("queue is underflow");
        exit(1);
    }
    temp=front;
    item=temp->info;
    front=front->link;

    free(temp);
    return item;

}
int ispeek()
{
    if(isempty())
    {
        printf("list is empty");
        return;
    }
    return front->info;
}
void display()
{
    struct node *ptr;
    ptr=front;
    if(isempty())
    {
        printf("queue is empty\n");
        return;
    }
    printf("queue elements :\n\n");
    while(ptr!=NULL)
    {
        printf("%d",ptr->info);
        ptr=ptr->link;
    }
    printf("\n\n");
}





















