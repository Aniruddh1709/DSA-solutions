void SortedInsert(struct Node *p,int x){
    Node *t,*q=nullptr;

    t= new Node;
    t->data=x;
    t->link=nullptr;

    if(head==nullptr){
        head=t;
    }
    else{
        while(p && p->data<x){
            q=p;
            p=p->link;
        }
        if(p==head){
            t->link=head;
            head=t;
        }
        else{
            t->link=q->next;
            q->link=t;
        }
    }
}