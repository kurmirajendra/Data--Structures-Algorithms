#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int sno,age;
    char name[10];
    struct Student *next;
}*start;
void addStudent()
{
    struct Student *s,*p,*last;
    s=(struct Student*)malloc(sizeof(struct Student));
    if(s==NULL)
    {
        printf("No enough Memory ");
    }
    else
    {
        printf("\nEnter Student no.");
        scanf("%d",&s->sno);
        printf("\nEnter Age ");
        scanf("%d",&s->age);
        printf("\nEnter Name ");
        scanf("%s",&s->name);
        if(start==NULL)
        {
            start=s;
            s->next=NULL;
        }
        else
        {
            for(p=start;(p);p=p->next)
            last=p;
            last->next=s;
            s->next=NULL;
        }
    }
}
void showStudent()
{
    struct Student *s;
    s=start;
    while(s!=NULL)
    {
        printf("\nStudent no. %d",s->sno);
        printf("\nStduent Age %d",s->age);
        printf("\nStudnet Name %s",s->name);
        s=s->next;
        printf("\n---------------------");
    }
}
void delNode()
{
  struct Student *ptr,*prev;
  int no;
  printf("\nEnter no to delete the node ");
  scanf("%d",&no);
  for(ptr=start;(ptr);ptr=ptr->next)
  {
      if(ptr->sno==no)
      {
        if(ptr->next==NULL)
            prev->next=NULL;
         else if(ptr==start)
                start=start->next;
         else
            prev->next=ptr->next;
         free(ptr);
         break;
      }
      prev=ptr;
  }
}
void main()
{
    start=NULL;
    int ch;
    while(1)
    {
        printf("\n1.Add Student ");
        printf("\n2.Show all Student ");
        printf("\n3.Delete Student ");
        printf("\n4. Exit ");
        printf("\nEnter your choice ");
        scanf("%d",&ch);
        if(ch==1)
            addStudent();
        else if(ch==2)
            showStudent();
        else if(ch==3)
            delNode();
        else
            break;
    }
}
