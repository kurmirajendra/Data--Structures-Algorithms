

#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int rollno;
    struct Student *next;
}*start;
void add()
{
     struct Student *s,*last;
     s=(struct Student*)malloc(sizeof(struct Student));
     if(s==NULL)
     {
         printf("\nNo enough memory allocated ");
         return;
     }
      printf("\nRoll no ");
      scanf("%d",&s->rollno);
      if(start==NULL)
      {
          start=s;
          s->next=start;
      }
      else
      {
          last=start;
          while(last->next!=start)
          {
              last=last->next;
          }
          last->next=s;
          s->next=start;
      }

}
void addAtBeg()
{
    struct Student *s,*last;
    s=(struct Student *)malloc(sizeof(struct Student));
     printf("\nEnter Roll No. ");
    scanf("%d",&s->rollno);

    if(start==NULL)
    {
        printf("\nEnter a node first ");
        return;
    }
    else
        {
             last=start;
            while(last->next!=start)
            {
                last=last->next;
            }
            s->next=start;
            last->next=s;
            start=s;
        }
}
void addAtMiddle()
{
    int no;
    struct Student * s,*last;
    s=(struct Student *)malloc(sizeof(struct Student));
    printf("\nEnter rollno ");
    scanf("%d",&s->rollno);
    last=start;
    printf("\nEnter roll no after which you want to add ");
    scanf("%d",&no);
    while(last->next!=start)
    {
        if(last->rollno==no)
        {
            s->next=last->next;
            last->next=s;
            return;
        }
        last=last->next;
    }
}
void display()
{
 struct Student *ptr;
 ptr=start;
 do
 {
     printf("\n Roll no %d ",ptr->rollno);
     printf("\n-------------------");
     ptr=ptr->next;
 }while(ptr!=start);
}
void delNode()
{
    struct Student *ptr,*last,*v;
    int no;
    printf("\nEnter no to delete node ");
    scanf("%d",&no);
    ptr=start;
    do
    {
        if(ptr->rollno==no)
        {
            if(ptr==start)
            {
                if(ptr->next==start)
                    start=NULL;
                else
                {
                    v=start;
                    while(v->next!=start)
                        v=v->next;

                     v->next=start->next;
                     start=start->next;

                }
            }
            else if(ptr->next==start)
            {
                last->next=start;
            }
            else
            {
                last->next=ptr->next;
            }


        }
        last=ptr;
        ptr=ptr->next;
    }while(ptr!=start);
}
void main()
{
    start=NULL;
    int c;
    while(1)
    {
        printf("\n1.Add Student ");
        printf("\n2.Add Student at Beg ");
        printf("\n3.Add at Middle ");
        printf("\n4.Display Students ");
        printf("\n5.Delete Node ");
        printf("\n.Exit ");
        printf("\nEnter your choice 1-6 ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            addAtBeg();
        else if(c==3)
           addAtMiddle();
        else if(c==4)
           display();
        else if(c==5)
            delNode();
        else
            break;
    }
}
