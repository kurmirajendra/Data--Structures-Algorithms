#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int rollno;
    struct Queue *next;
}*front,*rear;
void add()
{
    struct Queue *ptr;
    ptr=(struct Queue *)malloc(sizeof(struct Queue));
    if(ptr==NULL)
        printf("\nMemory not allocate ");
    else
    {
        printf("\nEnetr Roll No. ");
        scanf("%d",&ptr->rollno);
        if(front==NULL)
        {
            ptr->next=NULL;
            front=rear=ptr;
        }
        else
        {
          ptr->next=NULL;
          rear->next=ptr;
          rear=ptr;

        }
    }
}
void display()
{
    if(front==NULL)
    {
        printf("\nNO Node Fround ");
    }
    else
    {
          struct Queue *ptr;
       for(ptr=front;ptr!=NULL;ptr=ptr->next)
        {
            printf("\nRoll No. %d ",ptr->rollno);
        }
        printf("\n=======================\n ");
    }


}
void delNode()
{
    if(front==NULL)
        printf("\nNo Node Found ");
    else
    {
         struct Queue *ptr;
           ptr=front;
           front=ptr->next;
           free(ptr);
           printf("\n Node %d deleted ",ptr->rollno);
    }



}
void main()
{
 front=rear=NULL;
 int c;
 while(1)
 {
     printf("\n1.ADD STUDENT ");
     printf("\n2.DISPLAY ALL STUDENT ");
     printf("\n3.DELETE STUDENT ");
     printf("\n4.EXIT ");
     printf("\nEnter YOUR Choice ");
     scanf("%d",&c);
     if(c==1)
        add();
    else if(c==2)
        display();
    else if(c==3)
        delNode();
     else
        break;
 }
}

