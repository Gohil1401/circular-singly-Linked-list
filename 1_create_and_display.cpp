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
}
