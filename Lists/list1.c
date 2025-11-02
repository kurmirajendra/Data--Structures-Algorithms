#include<stdio.h>
#include<stdlib.h>
struct Employee
{
    int emp;
    struct Employee *next;
}*start;
void addEmp()
{
    struct Employee *e,*p,*last;
    e=(struct Employee *)malloc(sizeof(struct Employee));
    if(e==NULL)
        printf("\nNot Enough Memory ");
    else
    {
        printf("\nEnter Employee Number ");
        scanf("%d",&e->emp);
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
void  addBeg()
{
    struct Employee *ep;
    ep=(struct Employee *)malloc(sizeof(struct Employee));
    printf("\nEnter Employee Number ");
    scanf("%d",&ep->emp);
    ep->next=start;
    start=ep;

}
void addMiddle()
{
    if(start==NULL)
       {
            printf("\n No Student Found!! ");
            return;
       }
        printf("\nAdd Node At Middle ");
       struct Employee *em,*last=start;
      em=(struct Employee *)malloc(sizeof(struct Employee));
      printf("\nEnter Employee Number ");
      scanf("%d",&em->emp);
      int no;
      printf("\nEnter no after which you want to add node ");
      scanf("%d",&no);
      while(last!=NULL)
      {
          if(last->emp==no)
          {
              em->next=last->next;
              last->next=em;
          }
          last=last->next;
      }

}
void display()
{
    struct Employee *p;
    p=start;
    while(p!=NULL)
    {
        printf("\nEmployee Number %d",p->emp);
        printf("\n=================== ");
        p=p->next;
    }
}
void delEmp()
{
 if(start==NULL)
 {
     printf("\nNo Node Found!! ");
     return;
 }
 struct  Employee *e,*prev;
 int no;
  printf("\nEnter no. to delete node ");
  scanf("%d",&no);
   e=start;
   while(e!=NULL)
   {
       if(e->emp==no)
       {
           if(e->next==NULL)
           prev->next=NULL;
           else if(e==start)
            start=start->next;
           else
            prev->next=e->next;
       }
       prev=e;
       e=e->next;
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


