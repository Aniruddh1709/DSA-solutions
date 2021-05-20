
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
}*head=nullptr;

void Insert(int pos,int d){
  if(pos==0){
      Node* t=new Node;
      t->data=d;
      t->link=head;
      head=t;
  }
  else if(pos>0){
      Node *t,*p;
      t=new Node;
      t->data=d;
      p=head;
      for(int i=1;i<pos-1;i++){
          p=p->link;
      }
      t->link=p->link;
      p->link=t;
  }
}

void create(int a[],int n){
    Node *t;
    head=new Node;
    head->data=a[0];
    head->link=nullptr;
    t=head;
    for(int i=1;i<n;i++){
        Node *temp=new Node;
        temp->data=a[i];
        t->link=temp;
        temp->link=nullptr;
        t=temp;
    }


}

void display(){
    Node *p;
    p=head;
    while(p){
        cout<<p->data<<endl;
        p=p->link;
    }
}

int main(){
    int a[]={1,2,3,4,5};
    int n=5;
    int p=3,dat=7;
    create(a,n);
    display();
    Insert(p,dat);
    display();

    return 0; 
}