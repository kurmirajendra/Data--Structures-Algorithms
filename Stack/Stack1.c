#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int rollno;
    char name[10];
    struct Student *next;
}*top;
void add()
{
    struct Student *s;
    s=(struct Student *)malloc(sizeof(struct Student));
    if(s==NULL)
    {
        printf("\nMemory not Allocated ");
        return;
    }
    printf("\nEnter Roll No. ");
    scanf("%d",&s->rollno);
    printf("\nEnter name ");
    scanf("%s",&s->name);
        if(top==NULL)
        {
            top=s;
            s->next=NULL;
        }
        else
        {
            s->next=top;
            top=s;
        }
}
void show()
{
    struct Student *ptr=top;
    if(ptr==NULL)
        printf("\nNO Student Found ");
    while(ptr!=NULL)
    {
        printf("\n Student Roll No.%d ",ptr->rollno);
        printf("\n Student Name %s ",ptr->name);
        ptr=ptr->next;
        printf("\n====================");

    }


}
void delNode()
{
  struct Student *ptr=top;
  if(ptr==NULL)
    printf("\n UnderFLow - No Student Found !!");
  else
  {
      top=top->next;
      free(ptr);
  }
  printf("\nStudent Deleted  ");
}
void main()
{
    top=NULL;
    int c;
    while(1)
    {
        printf("\n1.Add  Student (Push)");
        printf("\n2.Delete Student (Pop)");
        printf("\n3.Show all Students");
        printf("\n4.Exit ");
        printf("\nEnter your choice (1-4)");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            delNode();
        else if(c==3)
            show();
        else
            break;
    }
}
