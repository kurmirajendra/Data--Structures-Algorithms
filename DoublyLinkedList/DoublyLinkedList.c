#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int rollno;
    char name[15];
    struct Student *next,*prev;

}*start,*end;
void addNode()
{
     struct Student *s;
     s=(struct Student *)malloc(sizeof(struct Student));
     printf("\nRoll no ");
     scanf("%d",&s->rollno);
     printf("\nName ");
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
void display()
{
  struct Student *p;
  for(p=start;(p);p=p->next)
  {
      printf("\n Roll No. %d ",p->rollno);
      printf("\n Name %s ",p->name);
      printf("\n------------------");
  }

}
void revDisplay()
{
 struct Student *p;
 for(p=end;(p);p=p->prev)
 {
     printf("\n Roll No. %d ",p->rollno);
     printf("\n Name  %s ",p->name);
     printf("\n---------------------");
 }
}
void searchStudent()
{
     int rno,flag=0;
     struct Student *p;
     printf("\n Enter roll no to search ");
     scanf("%d",&rno);
     for(p=start;(p);p=p->next)
     {
         if(p->rollno==rno)
         {
             printf("Student Data Found!!");
             printf("\n Rollno %d",p->rollno);
             printf("\n Name %s",p->name);
             printf("\n-------------------");
             flag=1;
         }
     }
     if(flag==0)
        printf("No student with the rollno %d found ",rno);

}
void delNode()
{
 struct Student *p;
 int rno;
 printf("\nEnter roll no to deleted ");
 scanf("%d",&rno);
 p=start;
 while(p!=NULL)
 {
     if(rno==p->rollno)
     {
         if(p==end)
         {
             end=end->prev;
             end->next=NULL;
         }
        else if(p==start)
         {
             start=start->next;
             start->prev=NULL;

         }
         else
         {
             p->next->prev=p->prev;
             p->prev->next=p->next;

        }
        free(p);
        printf("\nNode deleted ");
        break;
     }
     p=p->next;
 }

}
void main()
{
    start=end=NULL;
    int c;
    do
    {
        printf("\n1.Add Student ");
        printf("\n2.Dispaly all Student -start to end");
        printf("\n3.Display all Student -end to start ");
        printf("\n4.Search Student ");
        printf("\n5.Delete a Student ");
        printf("\n6.Exit ");
        printf("\nEnter your choice 1-6 ");
        scanf("%d",&c);
        if(c==1)
            addNode();
       else if(c==2)
            display();
       else if(c==3)
        revDisplay();
       else if(c==4)
          searchStudent();
       else if(c==5)
        delNode();

    }while(c!=6);
}
