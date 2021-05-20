void Delete(int x){
    Node *t,*q;
    t=head;
    q=nullptr;
    if(x==1){
        head=head->link;
        delete t;
    }
    else{
        for(int i=1;i<x-1;i++){
      q=t;
      t=t->link;
    }
    q->link=t->link;
    delete t;
        
    }