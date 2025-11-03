#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int rollno;
    char name[20];
    struct Student *next,*prev;
}*start,*end;
void addstudent()
{
  struct Student *s;
  s=(struct Student *)malloc(sizeof(struct Student));
  printf("\nEnter Rollno ");
  scanf("%d",&s->rollno);
  printf("\nEnter Name ");
  scanf("%s",&s->name);
  if(start==NULL)
  {
      start=s;
      end=s;
      s->next=NULL;
      s->prev=NULL;
  }
  else
  {
     end->next=s;
     s->prev=end;
     s->next=NULL;
     end=s;
  }
}
void addatBeg()
{
 struct Student *s;
 s=(struct Student *)malloc(sizeof(struct Student));
 printf("\nEnter Roll NO. ");
 scanf("%d",&s->rollno);
 printf("\nEnter Name ");
 scanf("%s",&s->name);
 if(start==NULL)
 {
     start=s;
     end=s;
     s->next=s->prev=NULL;
 }
 else
 {
    start->prev=s;
    s->next=start;
    s->prev=NULL;
    start=s;
 }
}
void addAtMiddle()
{
  int no;
 struct Student *s,*p;
 s=(struct Student *)malloc(sizeof(struct Student));
 printf("\nEnter Roll  No. ");
 scanf("%d",&s->rollno);
 printf("\n Enter Name ");
 scanf("%s",&s->name);
 printf("\nEnter rollno ");
 scanf("%d",&no);
 if(start==NULL)
 {
     printf("\nAdd  a node first");
     return;
 }
 else
 {
     for(p=start;(p);p=p->next)
     {
         if(p->rollno==no)
         {
             s->next=p->next;
             p->next->prev=s;
             s->prev=p;
             p->next=s;
         }
     }

}

}
void addMiddle()
{
    int no;
 struct Student *s,*p;
 s=(struct Student *)malloc(sizeof(struct Student));
 printf("\nEnter Roll  No. ");
 scanf("%d",&s->rollno);
 printf("\n Enter Name ");
 scanf("%s",&s->name);
 printf("\nEnter rollno ");
 scanf("%d",&no);
 if(start==NULL)
 {
     printf("\nAdd  a node first");
     return;
 }
 else
    {
     for(p=end;(p);p=p->prev)
     {
         if(p->rollno==no)
         {
             s->next=p;
             s->prev=p->prev;
             p->prev->next=s;
             p->prev=s;
         }
     }
 }
}
void display()
{
struct Student *s;
for(s=start;(s);s=s->next)
{
    printf("\n Roll NO. %d",s->rollno);
    printf("\n Name %s",s->name);
    printf("\n------------------ ");
}
}
void main()
{
    start=end=NULL;
    int c;
    do
    {   printf("\n1.Add Stundent ");
        printf("\n2.Add Student in Begging ");
        printf("\n3.Add Student at Middle after any node ");
        printf("\n4..Add Student at Middle before any node ");
        printf("\n5.Display all Student ");
        printf("\n6.Exit");
        printf("\nEnter your choice 1-6 ");
        scanf("%d",&c);
        if(c==1)
            addstudent();
        else if(c==2)
            addatBeg();
        else if(c==3)
            addAtMiddle();
         else if(c==4)
            addMiddle();
         else if(c==5)
         display();


    }while(c!=6);
}
