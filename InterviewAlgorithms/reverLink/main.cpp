#include <iostream>
#include<stdlib.h>
using namespace std;
///////121
/*/*
/*
*/
struct node
{
    int value;
    node * next;
};

node* make_link(void);
node* reverse(node*);
void display(node *);

int main()
{
    node *head=make_link();
    display(head);
    head=reverse(head);
    display(head);

    return 0;
}

node* make_link(void)
{
    node *head=new node();
    node *cur=head;
    for(int i=0;i<10;i++)
    {
        cur->value=rand()%100;
        cur->next=new node();
        cur=cur->next;
    }

    return head;
}

node* reverse(node *head)
{
    node *pre,*post,*cur;
    if(!head && !head->next)
        return head;
    pre=head;
    cur=pre->next;
    while(cur)
    {
        post=cur->next;
        cur->next=pre;
        pre=cur;
        cur=post;
    }
    head->next=NULL;
    return pre;
}

void display(node * head)
{
    node * cur=head;
    while(cur)
    {
        cout<<cur->value<<" ";
        cur=cur->next;
    }
    cout<<endl;
}
