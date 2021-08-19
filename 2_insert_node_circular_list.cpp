#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
}*head;

class List
{
    public:

    List()
    {
        head=NULL;
    }
    List(int a[],int n);
    void insert(int index,int x);
    void display();
};

List::List(int a[],int n)
{
    node *last,*t;
    head=new node;
    head->data=a[0];
    head->next=head;
    last=head;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;

    }

}

void List::insert(int index,int x)
{
    node *p=head;
    node *t;

    if(index==0)
    {
        t=new node;
        t->data=x;

        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next=t;
            t->next=head;
            head=t;
        }
    }

    else
    {
        p=head;
        for(int i=0;i<index-1;i++)
        {
          p=p->next;
        }
            t=new node;
            t->data=x;
            t->next=p->next;
            p->next=t;
    }
}

void List::display()
{
    node *h=head;
    cout<<" Your List is : ";
    do
    {
        cout<<h->data<<" ";
        h=h->next;
    }while(h!=head);
}

int main()
{
    int a[]={2,3,4,5,6};
    List l(a,5);
    l.display();

    cout<<endl;

    l.insert(0,10);
    l.display();

}

