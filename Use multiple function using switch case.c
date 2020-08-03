#include <stdio.h>
#include <stdlib.h>
#define null 0
typedef struct list
{
    int x;
    struct list *next;
}l;
l *ptr,*head,*new1,*ptr1,*a,*b,*loc;
int ele,ele1;
void create(l*);
void display();
void count(l*);
void insert_beg(void);
void insert_end(void);
void insert_bet(l *);
void insert_bef(l *);
void sort(l *);
void swap(l *,l *);
void del(l *);
void rev(l *);

int main()
{
    int m;
    head=(l*)malloc(sizeof(l));
    create(head);
    while(1)
    {
        printf("\n         menu list               \n");
        printf("1. Count \n2. Display \n3. Insert_begning \n4. Insert_end\n5. Insert in between two numbers \n6. Insert before a number\n7. Sorting \n");
        printf("8. Delete :\n9. Reverse\n");
        scanf("%d",&m);
        switch(m)
        {
            case 1:count(head);
            break;
            case 2:display();
            printf("null");
            break;
            case 3:insert_beg();
            break;
            case 4:insert_end();
            break;
            case 5:insert_bet(head);
            break;
            case 6:insert_bef(head);
            break;
            case 7:sort(head);
            break;
            case 8:del(head);
            break;
            case 9:rev(head);
            break;
            default :
                printf("wrong choice:");
        }
    }
    return 0;
}
void create(l *ptr)
{
    char ch;
    printf("Enter the value of node:- ");
    scanf("%d",&ptr->x);
    ptr->next=null;
    printf("Do you want more node (y/n) :- ");
    scanf(" %c",&ch);
    if(ch=='y'||ch=='y')
    {
        ptr->next=(l*)malloc(sizeof(l));
        ptr=ptr->next;
        create(ptr);
    }
}
void display()
{
    ptr=head;
    printf("\nThe linked list is :- \t");
    while(ptr!=null)
    {
        printf("%d->",ptr->x);
        ptr=ptr->next;
    }
}
void count(l *ptr)
{
    int count=0;
    while(ptr!=null)
    {
        count++;
        ptr=ptr->next;
    }
    printf("\nNumber of element in the list is :- %d ",count);
}
void insert_beg()
{
    l *new1=(l*)malloc(sizeof(l));
    printf("\nEnter the number to be inserted : \n");
    scanf("%d",&new1->x);
    new1->next=head;
    head=new1;
}
void insert_end()
{
    l *new1=(l*)malloc(sizeof(l));
    printf("\nEnter the number to be inserted at end :- ");
    scanf("%d",&new1->x);
    ptr=head;
    while(ptr->next!=null)
        ptr=ptr->next;
    new1->next=ptr->next;
    ptr->next=new1;
}
void insert_bet(l *ptr)
{
    printf("\nEnter the nodes between which to enter :\n");
    scanf("%d%d",&ele,&ele1);
    l *new1=(l*)malloc(sizeof(l));
    printf("Enter the new value : ");
    scanf("%d",&new1->x);
    while(ptr->next!=null)
    {
        if((ptr->x==ele)&&(ptr->next->x==ele1))
        {
            new1->next=ptr->next;
            ptr->next=new1;
        }
        ptr=ptr->next;
    }
}
void insert_bef(l *ptr)
{
    l *new1=(l*)malloc(sizeof(l));
    printf("\nEnter the value before which to insert :- ");
    scanf("%d",&ele);
    printf("\nEnter the new number :\n");
    scanf("%d",&new1->x);
    if(ptr->x==ele)
        insert_beg();
    else
    {
        l *ptr1=ptr->next;
        while(ptr1!=null)
        {
            if(ptr1->x==ele)
            {
                new1->next=ptr->next;
                ptr->next=new1;
            }
            ptr=ptr1;
            ptr1=ptr1->next;
        }
    }
}
void sort(l *ptr)
{
    while(ptr->next!=null)
    {
        l *ptr1=ptr->next;
        while(ptr1!=null)
        {
            if(ptr->x > ptr1->x)
            {
                swap(ptr,ptr1);
            }
            ptr1=ptr1->next;
        }
        ptr=ptr->next;
    }
}
void swap(l *a,l *b)
{
    int temp;
    temp=a->x;
    a->x=b->x;
    b->x=temp;
    //display();
}
void del(l *ptr)
{
    printf("\nEnter the number to be deleted : \n");
    scanf("%d",&ele);
    if(ptr->x==ele)
    {
        head=ptr->next;
        loc=ptr;
        free(loc);
        ptr=ptr->next;

        if(head!=null)
            del(head);
        else
        {
            printf("\nList Empty : ");
            head=null;
        }
    }
    else
    {
        l *ptr1=ptr->next;
        while(ptr1!=null)
        {
            if(ptr1->x==ele)
            {
                ptr->next=ptr1->next;
                loc=ptr1;
                free(loc);
            }
            ptr=ptr1;
            ptr1=ptr->next;
        }
    }
}
void rev(l *ptr)
{
    l *prev=null;
    l *current=head;
    l *forw=null;
    while(current!=null)
    {
        forw=current->next;
        current->next=prev;
        prev=current;
        current=forw;
    }
    ptr=prev;
    ptr=ptr->next;

}
