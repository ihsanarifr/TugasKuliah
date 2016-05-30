#include <iostream>

using namespace std;

struct node{
    int info;
    struct node *next;
    struct node *prev;
};
typedef struct node Node;

class DLL{
    Node *head;
    Node *tail;
public:
    DLL() { head=NULL;tail=NULL; }
    bool empty() { return head==NULL;}
    Node* make(int value);
    void push_back(int value);
    void print();
};

Node* DLL::make(int value){
    Node *temp=new(Node);
    temp->info=value;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

void DLL::push_back(int value){
    Node *ptr=make(value);
    if (empty()) {
        head=ptr; tail=ptr;
    } else {
        tail->next=ptr; tail=ptr;
    }
}

void DLL::print(){
    Node *ptr=head;
    for (; ptr!=NULL; ptr=ptr->next)
    cout << ptr->info << " -> ";
    cout << "NULL" << endl;
}

int main(){
    DLL list;
    int n,m,data;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> data;
        list.push_back(data);
    }

    //list.print();
    return 0;
}
