#include<iostream>

typedef struct node{
    int value;
    struct node *prev, *next;
} NODE;

using namespace std;

class Queue{
    NODE *Front, *Rear;
public:
    Queue(){Front=NULL;Rear=NULL;}
    bool empty(){ return (Front==NULL);}
    void push(int nilai);
    int front();
    int back();
    void pop();
    void push_priority(int nilai);

    friend ostream& operator<< (ostream &out, Queue q){
        if(q.empty())
            out << "stack is empty\n";
        else{
            for(NODE *ptr=q.Front;ptr!=NULL;ptr=ptr->next)
                out << ptr->value << endl;
        }
        return out;
    }
};

void Queue::push(int nilai){
    NODE *temp= new(NODE);
    temp->value=nilai;

    temp->prev=NULL;
    temp->next=NULL;

    if(empty()){
        Front=temp;
        Rear=temp;
    }else{
        Rear->next=temp;
        temp->prev=Rear;
        Rear=temp;
    }
}

void Queue::push_priority(int nilai){
    NODE *temp=new(NODE);
    temp->value=nilai;
    temp->prev=NULL;
    temp->next=NULL;

    if(empty()){
        Front=temp;
        Rear=temp;
    }else{
        NODE *ptr=Front;
        if(Front->value<nilai){
            temp->next=Front;
            Front->prev=temp;
            Front=temp;
        }else{
            while(ptr!=NULL){
                if(ptr->value<nilai)
                    break;
                ptr=ptr->next;
            }
            if(ptr==NULL){
                // push back
                push(nilai);
            }else{
                // insert befor ptr
                (ptr->prev)->next=temp;
                temp->prev=ptr->prev;
                ptr->prev=temp;
                temp->next=ptr;
            }
        }
    }
}

void Queue::pop(){
    if(empty())
        cout << "Queue is empty\n";
    else
        Front=Front->next;
}

int Queue::front(){
    if(empty())
        cout << "Queue is empty\n";
    else
        return Front->value;
}

int Queue::back(){
    if(empty())
        cout << "Queue is empty\n";
    else
        return Rear->value;
}

int main(){
    Queue antrian;
    antrian.push(10);
    antrian.push(20);
    antrian.push(15);
    antrian.push(7);

    cout << "Queue awal:\n";
    cout << antrian;
    cout << "\nFront: " << antrian.front() << endl;
    cout << "\nRear: " << antrian.back() << endl;
    antrian.pop();
    antrian.pop();
    cout << antrian;
    return 0;
}
