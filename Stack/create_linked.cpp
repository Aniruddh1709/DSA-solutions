
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
class Stack{
    private:
    Node *top;
    public:
    Stack(){top=nullptr;}
    void push(int data);
    int pop();
    void display();
    
};

void Stack::push(int x)
{
    Node *t= new Node;
    if(t==0){
        cout<<"Stack is Full";
    }else{
    t->data=x;
    t->next=top;
    top=t;
    }
}

int Stack :: pop(){
    int x=-1;
    if(top==0){
        cout<<"Stack is Empty";
    }else{
        Node *t;
        x=top->data;
        t=top;
        top=top->next;
        delete t;
    }
    return x;
}

void Stack::display(){
    Node *p;
    p=top;
    if(top==0){
        cout<<"Nothing to show";
    }else{
        while(p){
            cout<<p->data<<endl;
            p=p->next;
        }
    }
}
int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.display();
    cout<<st.pop()<<"pop";
    st.display();

    return 0;
}