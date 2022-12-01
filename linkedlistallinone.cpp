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
void  deleteatfirst(); 
void deleteatLast();
void deleteatbetween(int data);
int  searchData(int data);
void shortlist();
void editdata(int currentdata,int newdata);
int countdata();
int firstelement();
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
void  linkedlist::deleteatfirst()
{
   // int x=-1;
    node*t;
    if(head==NULL )
    cout<< " \n linkedlist is empty to cann't delete element\n"<<endl;
    else{
        t=head;
        
      //  x=head->data;
        head=head->next;
       // x=head->data;
    cout<<t->data<<" delete element\n ";
    //return x;
    delete t;
    }
  //  return 0;
}
void linkedlist::deleteatLast()
{
    node*t1,*t2;
    if(head==NULL)
    cout<<"\n not delete\n";
    else
    t1=t2=head;
    { do{
        t2=t1;
        t1=t1->next;
    }
        while(t1->next!=NULL);
        
        t2->next=NULL;
        cout<<t1->data<<" \ndelete last element\n";
        delete t1;
    }
}
void linkedlist::deleteatbetween(int data)
{
    node*p;
    node*t=search(data);
    if(t==NULL)
    cout<< " given position is incorrect\n";
    if (t->next==NULL)
    {
        deleteatLast();
    }
    else
    {
        p=head;
        while(p->next!=t)
        {
            p=p->next;
        }
        p->next=t->next;
        delete t;
    }
}
int  linkedlist::searchData(int data)
{
    node*t;
    int pos=0;
    if(head==NULL)
    return -1;
    else
    {
        t=head;
        while(t!=NULL)
        {
            
            if(t->data==data)
            return (pos);
            t=t->next;
            pos++;
        }
    }
    return -1;
}
void linkedlist::shortlist()
{int temp;
    node*t1,*t2;
    if(head==NULL)
    cout<<"\n linkedlistl is empty\n";
    t2=NULL;
    t1=head;
    while(t1->next!=NULL)
    {
        t2=t1->next;
        while(t2->next!=NULL)
        
        {
            if(t1->data<t2->data)
            {
                temp=t2->data;
                t2->data=t1->data;
                t1->data=temp;
                
                
            }
            if(t1->data>t2->data)
            {
                temp=t1->data;
                t1->data=t2->data;
                t2->data=temp;
                
                
            }
            t2=t2->next;
        }
        t1=t1->next;
    }
    
}
void linkedlist::editdata(int currentdata,int newdata)
{
    node*t=search(currentdata);
    if(t==NULL)
    cout<<"\nfalse information\n";
    else
    {
        t->data=newdata;
    }
}
int  linkedlist::countdata()
{
    node*t;
    t=head;
    int count=0;
    while(t!=NULL)
    {
        count++;
        t=t->next;
    }
    return count;
    
}
int linkedlist::firstelement()
{
    if(head==NULL){
    cout<<" \nlinkedlist is empty\n";
    return -1;
    }
    else
    return(head->data);
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
    cout<<endl;
    l1.print();
    cout<<"       "<<endl;
    l1.deleteatfirst();
    l1.print();
    cout<<endl;
 //   cout<<l1.deleteatfirst();
 l1.deleteatLast();
 cout<<"\n";
 l1.print();
 cout<<endl;
 l1.deleteatbetween(100);
 l1.print();
 cout<<endl;
  cout<< l1.searchData(50);
  cout<<endl;
 l1.shortlist();
 l1.print();
 cout<<endl;
 l1.editdata(60,70);
 l1.print();
 cout<<endl;
 cout<<l1.countdata();
 cout<<endl;
 cout<<l1.firstelement();
 return 0;
}
