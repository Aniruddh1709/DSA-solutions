
#include <iostream>
using namespace std;

class Queue{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    
    public:
        Queue(){size=10;front=-1;rear=-1;Q=new int[size];}
        Queue(int size){this->size=size;rear=-1;Q=new int[this->size];}
        void enqueue(int x){
             if(rear==size-1){
                 cout<<"Queue is Full"<<endl;
                }else{
                    rear++;
                    Q[rear]=x;
                        }
                        }
        int dequeue(){
    int x=-1;
    if(rear==front){
        cout<<"Queue is Empty"<<endl;
    }else{
        front++;
        x=Q[front];
        }
    return x;
    }
        void display(){
    if(rear==front){
        cout<<"Queue is Empty"<<endl;
    }else{
        for(int i=front+1;i<=rear;i++){
            cout<<Q[i]<<endl;
        }
    }
} 
    
    
};




int main() {
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    
   
    cout << q.dequeue();
    q.display();

    return 0;
}