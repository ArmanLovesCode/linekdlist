#include<iostream>
using namespace std;

class  linkedlist{
    struct  node {
   // public:
    int data;
    node *next;


}*head;
public:
node*search(int data)
{
    node*t;
    if(head==NULL)
    return NULL;
    else{
        t=head;
        while(t!=NULL)
        {
            if(t->data==data)
            return t;
t=t->next;
        }
    }
    return NULL;

}
linkedlist()
{
    head=NULL;
} 
void insertatfirst(int data);
void inseratLast(int data);
void inseratBetween(int currentdata,int data);
void print();
};
void linkedlist::insertatfirst(int data)
{
    node*n=new node();
    n->data=data;
    n->next=NULL;
    if(head==NULL)
    head=n;
    else{
        n->next=head;
        head=n;

    }
}
void linkedlist::inseratLast(int data)
{
    node*n=new node();
    node*t;

    n->data=data;
    n->next=NULL;
    if(head==NULL)
    head=n;
    else{
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=n;

    }
}
void linkedlist::inseratBetween(int currentdata,int data)
{
    node*n=new node();
    n->data=data;
    n->next=NULL;
    node*t=search(currentdata);
    if(t==NULL)
    {
        cout<<"\n given information is incorrect\n";
    }
    else{
        n->next=t->next;
        t->next=n;

    }


}
void  linkedlist::print()
{
    node*t;
    if(head==NULL)
    cout<<" \nlinkedlist is empty\n";
    else
    {
        t=head;
        while(t!=NULL)
        {
            cout<<t->data<<"  ->  ";
         t=t->next;
        }
        
    }

}
int main ()
{
    linkedlist l1;
    l1.insertatfirst(10);
    l1.insertatfirst(20);
    l1.insertatfirst(30);
    l1.insertatfirst(40);
    cout<<" print element\n";
    l1.print();

    l1.inseratLast(50);
    l1.inseratLast(60);
    l1.inseratLast(70);
    cout<< endl;
    l1.print();
    l1.inseratBetween(50,100);
    l1.print();

}
