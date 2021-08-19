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
    void Delete(int index);
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

void List::Delete(int index)
{
    node *p,*q;
    int x,i;

    if(index==1)
    {
        p=head;

        while(p->next!=head)
        {
            p=p->next;
        }
        p->next=head->next;
        x=head->data;
        delete head;
        head=p->next;
    }

    else
    {
        p=head;
        for(i=0;i<index-2;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
}

void List::display()
{
    node *p=head;
    cout<<" Your List is : ";
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}

int main()
{
    int a[]={2,3,4,5,6};
    List l(a,5);
    l.display();
    cout<<endl;
    l.Delete(4);
    l.display();
}

