#include <iostream>
#include <iomanip>
using namespace std;

struct node{
    double info;
    struct node *next;
    struct node *prev;
};
typedef struct node Node;

class DLL{
public:
    Node *head;
    Node *tail;
    DLL() { head=NULL;tail=NULL; }
    bool empty() { return head==NULL;}
    Node* make(double value);
    void push_back(double value);
    void push_before(double value);
    void push_front(double val);
    Node* find(double val);
    void print();
};

Node* DLL::make(double value){
    Node *temp=new(Node);
    temp->info=value;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

void DLL::push_back(double value){
    Node *ptr=make(value);
    if (empty()) {
        head=ptr; tail=ptr;
    } else {
        ptr->prev=tail;
        tail->next=ptr;
        tail=ptr;
    }
}

void DLL::print(){
    Node *ptr=head;
    for (; ptr!=NULL; ptr=ptr->next)
    cout << fixed << setprecision(1) << ptr->info << "->";
    cout << "NULL" << endl;
}

Node* DLL::find(double value){
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

void DLL::push_before(double val){
    Node *ptr=make(val);
    Node *tunjuk;
    Node *akhir;
    if(empty()){
        push_back(val);
    }else if(tail->info <= val){
        push_back(val);
    }else if(head->info > val){
        push_front(val);
    }else{
        tunjuk = find(val);
        ptr->next=tunjuk;
        (tunjuk->prev)->next=ptr;
    }

}

void DLL::push_front(double val){
    Node *ptr=make(val);
    ptr->next=head;
    (head->next)->prev=ptr;
    head=ptr;
}

int main(){
    DLL list;
    int n,m;
    double data,before;

    Node *contoh;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> data;
        list.push_back(data);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> before;
        list.push_before(before);
    }

    //list.push_back(10);
    //list.push_back(30);
    //list.push_back(50);
    //cout << list.tail->info;
    //contoh = list.find(10);
    //cout << contoh->info << endl;
    //list.push_before(50);
    list.print();
    return 0;
}
