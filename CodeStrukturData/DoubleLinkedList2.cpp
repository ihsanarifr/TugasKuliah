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
    void push_front(int value);
    void push_before(int value);
    Node* find(int val);
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
        ptr->prev=tail;
        tail->next=ptr;
        tail=ptr;
    }
}
void DLL::push_front(int value){
    Node *ptr=make(value);
    if(empty()){
        head=ptr; tail=ptr;
    }else {
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
    }
}
void DLL::print(){
    Node *ptr=head;
    for (; ptr!=NULL; ptr=ptr->next)
    cout << ptr->info << "->";
    cout << "NULL" << endl;
}

Node* DLL::find(int value){
    Node *ptr=head;
    if (empty())
        return NULL;
    else {
        while (ptr->next!=NULL && ptr->info<=value) {
            ptr=ptr->next;
        }
        if (ptr->info>value)
            return ptr;
        else
            return NULL;
    }
}

void DLL::push_before(int val){
    Node *ptr=make(val);
    Node *tunjuk;
    if(empty()){
        push_back(val);
    }else{
        tunjuk = find(val);
        ptr->next=tunjuk;
        (tunjuk->prev)->next=ptr;
    }
}
int main(){
    DLL list;
    int n,m,data,before;

    Node *contoh;
    /*
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> data;
        list.push_back(data);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> before;
        list.push_before(data);
    }
    */
    list.push_back(10);
    list.push_back(30);
    list.push_back(50);

    contoh = list.find(10);
    cout << contoh->info << endl;
    //list.push_before(10);
    list.print();
    return 0;
}
