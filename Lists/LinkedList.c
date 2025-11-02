#include <stdio.h>
#include<stdlib.h>
struct Person
{
    int pno;
    char name[10];
    struct Person *next;

}*start;

void addPerson()
{
   struct Person *ptr,*p,*last;
   ptr= (struct Person *)malloc(sizeof(struct Person));
   printf("Enter Person no ");
   scanf("%d",&ptr->pno);
   printf("\nPerson name ");
   scanf("%s",&ptr->name);
   if(start==NULL)
   {
        start=ptr;
       ptr->next=NULL;
   }
   else
   {
       for(p=start;p!=NULL;p=p->next)
        last=p;
       last->next=ptr;
       ptr->next=NULL;

   }
}
void showPerson()
{
    struct Person *pn;
    for(pn=start;pn!=NULL;pn=pn->next)
    {
        printf("\nPerson Number %d ",pn->pno);
        printf("\nPerson name %s",pn->name);
        printf("\n-------------------------");
    }
}
void main()
{
    start=NULL;
    int c;
    do
    {
        printf("\n1. Add Person ");
        printf("\n2. Show All Person");
        printf("\n3.Exit");
        printf("\nEnter choice ");
        scanf("%d",&c);

        if(c==1)
           addPerson();
           else if(c==2)
           showPerson();

    }while(c!=3);
}
