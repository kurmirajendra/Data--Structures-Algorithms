#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int rollno;
    struct Stack *next;
}*top;
void add()
{
   struct Stack *ptr;
   ptr = (struct Stack *)malloc(sizeof(struct Stack));
   if(ptr==NULL)
    printf("\nNo enough memory ");
   else
   {
       printf("\nRoll No. ");
       scanf("%d",&ptr->rollno);
       if(top==NULL)
       {
           ptr->next=NULL;
           top=ptr;
       }
       else
       {
           ptr->next=top;
           top=ptr;
       }
   }
}
void show()
{
    struct Stack *ptr=top;
    while(ptr!=NULL)
    {
        printf("\nRoll No. %d ",ptr->rollno);
        ptr=ptr->next;
    }
    printf("\n--------------------");
}
void pop()
{
    if(top==NULL)
        printf("\nUnderFlow - No Node Found ");
    else
    {
        struct Stack *ptr=top;
        top=top->next;
        free(ptr);
    }
}

void main()
{
    top==NULL;
    int c;
    do
    {
        printf("\n1.To Push - Add Student ");
        printf("\n2.To Pop - Delete Student ");
        printf("\n3.Show all Student ");
        printf("\n4.Exit ");
        printf("\nEnter Your Choice ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            pop();
        else if(c==3)
            show();

    }while(c!=4);
}

