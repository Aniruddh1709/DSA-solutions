
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* link;
};

Node *first;

void create(int ar[],int n){
    Node *t,*temp;
    first=new Node;
    first->data=6;
    first->link=nullptr;
    t=first;
    for(int i=1;i<n;i++){
        temp=new Node;
        temp->data=ar[i];
        temp->link=nullptr;
        t->link=temp;
        t=temp;
    }
    
   
}
void display(){
    Node *p;
    p=first;
    while(p){
        cout<<p->data<<endl;
        p=p->link;
    }
}

int main() {
    int a[]={1,2,3,4,5};
    create(a,5);
    display();
    return 0;
}