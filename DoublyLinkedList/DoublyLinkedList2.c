#include<stdio.h>
#include<stdlib.h>
struct Customer
{
    int cno;
    struct Customer *next,*prev;
}*start,*end;
void add()
{
    struct Customer *c;
    c=(struct Customer *)malloc(sizeof(struct Customer));
    if(c==NULL)
    {
        printf("\nNot Enough Memory ");
        return;
    }
    else
    {
        printf("\nEnter Customer No. ");
        scanf("%d",&c->cno);
        if(start==NULL)
        {
            start=c;
            end=c;
            c->next=NULL;
            c->prev=NULL;
        }
        else
        {
            end->next=c;
            c->prev=end;
            c->next=NULL;
            end=c;
        }
    }
}
void addatBeg()
{
    struct Customer *ptr;
    ptr=(struct Customer *)malloc(sizeof(struct Customer));
   printf("\nEnter Customer No. ");
    scanf("%d",&ptr->cno);
    if(start==NULL)
     {
         start=ptr;
         end=ptr;
         ptr->next=NULL;
         ptr->prev=NULL;
     }
     else
     {
         start->prev=ptr;
         ptr->next=start;
         ptr->prev=NULL;
         start=ptr;

     }
}
void addAtMiddle()
{
    struct Customer *s,*p;
    s=(struct Customer *)malloc(sizeof(struct Customer));
    int no;
    printf("\n Enter Customer No. ");
    scanf("%d",&s->cno);
    printf("\n Enter Customer after you want add ");
    scanf("%d",&no);
    if(start==NULL)
    {
        printf("\n Add Customer First ");
        return;
    }
    else
    {
       for(p=start;(p);p=p->next)
       {
           if(p->cno==no)
           {
               s->next=p->next;
               p->next->prev=s;
               p->next=s;
               s->prev=p;
           }
       }
    }
}
void addMiddle()
{
    struct Customer *s,*p;
    s=(struct Customer *)malloc(sizeof(struct Customer));
    printf("\nEnter Customer No. ");
    scanf("%d",&s->cno);
    int no;
  printf("\n Enter Customer before you want add ");
    scanf("%d",&no);
    if(start==NULL)
    {
        printf("\nAdd A Customer First ");
        return;
    }
    else
    {
        for(p=end;(p);p=p->prev)
        {
            if(p->cno==no)
            {
                s->next=p;
                s->prev=p->prev;
                p->prev->next=s;
                p->prev=s;

            }
        }
    }
}
void delNode()
{
    struct Customer *cs;
    int no;
    printf("\nEnter Customer No. to delete: ");
    scanf("%d", &no);

    if (start == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        return;
    }

    cs = start;
    while (cs != NULL)
    {
        if (no == cs->cno)
        {

            if (start == end && cs == start) {
                start = end = NULL;
            }

            else if (cs == start) {
                start = start->next;
                start->prev = NULL;
            }

            else if (cs == end) {
                end = end->prev;
                end->next = NULL;
            }
            else {
                cs->next->prev = cs->prev;
                cs->prev->next = cs->next;
            }
            free(cs);
            printf("\nCustomer %d deleted successfully.\n", no);
            return;
        }
        cs = cs->next;
    }

    printf("\nCustomer %d not found.\n", no);
}

void Show()
{
    if(start==NULL)
    {
        printf("\n No. Customer Found!! ");
        return;
    }
    struct Customer *cs;
    for(cs=start;(cs);cs=cs->next)
    {
        printf("\n Customer No %d ",cs->cno);
        printf("\n------------------ ");
    }
}
void main()
{
    start=end=NULL;
    int c;
    do
    {
        printf("\n1. Add Customer ");
        printf("\n2.Show All Customers ");
        printf("\n3.Add Customer at Begging");
        printf("\n4.Add Customer at Middle after any customer");
        printf("\n5.Add Customer at Middle before any customer");
        printf("\n6.Delete a Customer ");
        printf("\n7.Exit ");
        printf("\nEnter Your Choice ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            Show();
            else if(c==3)
                addatBeg();
                else if(c==4)
                    addAtMiddle();
                    else if(c==5)
                        addMiddle();
                        else if(c==6)
                            delNode();
    }while(c!=7);
}
