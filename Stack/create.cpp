// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st){
    cout<<"enter size"<<endl;
    cin>>st->size;
    st->s=new int[st->size];
    st->top=-1;
    
}
void display(struct Stack st){
    for(int i=st.top;i>=0;i--){
        cout<<st.s[i]<<endl;
    }
}

void push(struct Stack *st,int x){
    if(st->top==st->size-1){
        cout<<"stack overflow";
    }else{
        st->top++;
        st->s[st->top]=x;
    }
}

int pop(struct Stack *st){
    int x=-1;
    if(st->top==-1){
        cout<<"stack underflow";
    }
    else{
        x=st->s[st->top--];
    }
    return x;
}

int peek(struct Stack st,int index){
    int x=-1;
    if(st.top-index<0){
        cout<<"invalid index"<<endl;
    }else{
       x= st.s[st.top-index+1];
    }
    return x;
}

void isEmpty(struct Stack st){
    if(st.top==-1){
        cout<<"is empty";
    }
}
int isFull(struct Stack st){
    
    return st.top==st.size-1;
}   

int main() {
    struct Stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    display(st);

    return 0;
}