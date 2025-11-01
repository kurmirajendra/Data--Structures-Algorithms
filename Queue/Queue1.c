#include<stdio.h>
#include<stdlib.h>
struct Student
{
    char name[15];
    struct Student *next;
}*rear,*front;
void add()
{
    struct Student *st;
    st=(struct Student *)malloc(sizeof(struct Student));
    if(st==NULL)
    {
        printf("\n Memory not allocated ");
        return;
    }
   else
   {
      printf("\nEnter Name ");
      scanf("%s",&st->name);
    if(front==NULL)
    {
     st->next=NULL;
     rear=front=st;
    }
    else
    {
        st->next=NULL;
        rear->next=st;
        rear=st;
    }
   }
}
void show()
{
    if(front==NULL)
        printf("\n No Student Found!! ");
    else
    {
        struct Student *ptr;
        for(ptr=front;(ptr);ptr=ptr->next)
        {
            printf("\n Student Name %s ",&ptr->name);
            printf("\n--------------------- ");
        }
    }
}
void delNode()
{
    if(front==NULL)
        printf("\nQueue is UnderFlow ");
    else
    {
        struct Student *s;
        s=front;
        front=s->next;
        free(s);
        printf("\nStudent Deleted %s ",s->name);

    }
}
void main()
{
    rear=front=NULL;
    int ch;
    do
    {
        printf("\n1.Enter Student (InQueue) ");
        printf("\n2.Delete Student (DeQueue) ");
        printf("\n3.Show All Students ");
        printf("\n4.Exit");
        printf("\nEnter your choice (1-4) ");
        scanf("%d",&ch);
        if(ch==1)
            add();
        else if(ch==2)
          delNode();
          else if(ch==3)
            show();
    }while(ch!=4);
}
