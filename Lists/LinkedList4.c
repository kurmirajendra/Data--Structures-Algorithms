#include<stdio.h>
#include<stdlib.h>
struct Employee
{
    int eno;
    char name[10];
    struct Employee *next;
}*start;
void addEmp()
{
  struct Employee *e,*p,*last;
 e=(struct Employee *)malloc(sizeof(struct Employee));
 printf("\nEnter Employee No. ");
 scanf("%d",&e->eno);
 printf("\nEnter Name ");
 scanf("%s",&e->name);
 if(e==NULL)
 {
     printf("\n No enough memory ");
 }
 else
 {
     if(start==NULL)
     {
         start=e;
         e->next=NULL;
     }
     else
     {
         for(p=start;(p);p=p->next)
         last=p;
         last->next=e;
         e->next=NULL;
     }
 }
}
void addBeg()
{
     struct Employee *s;
     s=(struct Employee *)malloc(sizeof(struct Employee));
          printf("\nEnter Employee No. ");
           scanf("%d",&s->eno);
          printf("\nEnter Name ");
            scanf("%s",&s->name);
            s->next=start;
            start=s;
}
 void addMiddle()
 {
     if(start==NULL)
     {
         printf("\nNO Nodes  Found!! ");
         return;
     }
     printf("\nAdd node at Middle ");
     struct Employee *ptr,*p;
     ptr=(struct Employee *)malloc(sizeof(struct Employee));
            printf("\nEnter Employee No. ");
            scanf("%d",&ptr->eno);
            printf("\nEnter Name ");
            scanf("%s",&ptr->name);
            int no;
            printf("\nEnter no after which you want to add node ");
            scanf("%d",&no);
            for(p=start;(p);p=p->next)
            {
                 if(p->eno==no)
              {
                 ptr->next=p->next;
                 p->next=ptr;
             }
     }
 }
void display()
{
   struct Employee *s;

   for(s=start;s!=NULL;s=s->next)
    {
     printf("\nEmployee No. %d ",s->eno);
     printf("\nEmployee Name %s ",s->name);
     printf("\n-----------------------");
    }
}
void delEmp()
{

 struct Employee *ptr,*prev;
  int no;
  printf("\nEnter no. to delete node ");
  scanf("%d",&no);
 ptr=start;
 while(ptr!=NULL)
 {
    if(ptr->eno==no)
    {
        if(ptr->next==NULL)
        prev->next=NULL;
       else if(ptr==start)
        start=start->next;
        else
          prev->next=ptr->next;
        free(ptr);
     }
     prev=ptr;
    ptr=ptr->next;
   }
}
void main()
{
    start=NULL;
    int c;
    while(1)
    {
        printf("\n1.Add Employee ");
        printf("\n2.Add at Begging ");
        printf("\n3.Add at Middle ");
        printf("\n4.Display Employee ");
        printf("\n5.Delete Employee ");
        printf("\n6.Exit ");
        printf("\nEnter your choice 1-6 ");
        scanf("%d",&c);
        if(c==1)
            addEmp();

        else if(c==2)
             addBeg();
        else if(c==3)
            addMiddle();
        else if(c==4)
            display();
        else if(c==5)
            delEmp();
        else
            break;
    }
}
