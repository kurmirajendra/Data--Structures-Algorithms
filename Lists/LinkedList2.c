#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int sno,marks;
    char name[15];
    struct Student *next;
}*head;

void addStudent()
{
  struct Student *s,*st,*prev;

  s=(struct Student *)malloc(sizeof(struct Student));
  printf("\nEnter Student no ");
  scanf("%d",&s->sno);
  printf("\nEnter makrs ");
  scanf("%d",&s->marks);
  printf("\nEnter name ");
  scanf("%s",&s->name);
  if(head==NULL)
  {
      head=s;
      s->next=NULL;
  }
  else
  {
      for(st=head;st!=NULL;st=st->next)
        prev=st;
        prev->next=s;
        s->next=NULL;

  }
}
void displayAll()
{
  struct Student *ptr;
  ptr=head;
  while(ptr!=NULL)
  {
      printf("\nStudent no %d ",ptr->sno);
      printf("\nStudent Marks %d ",ptr->marks);
     ptr=ptr->next;
      printf("\n---------------------");
  }
}
void delNode()
{
  struct Student *ptr,*prev;
  int no;
  printf("\nEnter no to delete student ");
  scanf("%d",&no);
  for(ptr=head;(ptr);ptr=ptr->next)
  {
       if(ptr->sno==no)
  {
      if(ptr->next==NULL)
        prev->next=NULL;

        else if(ptr==head)
            head=head->next;
        else
        prev->next=ptr->next;
        free(ptr);
  }
  prev=ptr;

  }

}
void main()
{
    head=NULL;
    int c;
    while(1)
    {
        printf("\n1. Add a Stduent ");
        printf("\n2. Display All Students ");
        printf("\n3. Delete a Student ");
        printf("\n4.Exit ");
        printf("\n Enter your choice (1-4)");
        scanf("%d",&c);
        if(c==1)
            addStudent();
        else if(c==2)
            displayAll();
        else if(c==3)
            delNode();
        else if(c==4)
            break;
    }
}
