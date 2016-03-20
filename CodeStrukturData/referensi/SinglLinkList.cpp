#include <iostream>

using namespace std;

struct node {
    int info;
    struct node *next;
};
typedef struct node Node;

class SLL {
    Node *head, *tail;
public:
    void make() { head=NULL; tail=NULL;}
    Node* make(int val); // make a node
    int isEmpty() { return (head==NULL); }
    void push_back(int val);
    void push_front(int val);
    void push_after(int val, int after);
    Node *find(int val);
    Node *find_before(int val);
    void del(int val);
    void print();
};

Node* SLL::make(int val) {
    Node *temp = new(Node);
    temp->info=val;
    temp->next=NULL;
    return temp;
}

void SLL::push_back(int val) {
    Node *ptr=make(val);
    if (isEmpty()) {
        head=ptr; tail=ptr;
    } else {
        tail->next=ptr; tail=ptr;
    }
}

void SLL::push_front(int val) {
    Node *ptr=make(val);
    if (isEmpty()) {
        head=ptr; tail=ptr;
    } else {
        ptr->next=head; head=ptr;
    }
}

void SLL::print() {
    Node *ptr=head;
    for (; ptr!=NULL; ptr=ptr->next)
    cout << ptr->info << " -> ";
    cout << "NULL" << endl;
}

Node* SLL::find(int val) {
    Node *ptr=head;
    if (isEmpty()) return NULL;
    else {
    while (ptr->next!=NULL && ptr->info!=val) {
    ptr=ptr->next;
    }
    if (ptr->info==val) return ptr;
    else return NULL;
    }
}

void SLL::push_after(int val, int after) {
    Node *ptr = find(after);
    if (ptr!=NULL) {
    Node *temp = make(val);
    temp->next = ptr->next;
    ptr->next = temp;
    }
}

Node* SLL::find_before(int val) {
    Node *ptr=head; Node *pra=head;
    if (isEmpty()) return NULL;
    else {
    while (ptr->next!=NULL && ptr->info!=val) {
    pra=ptr; ptr=ptr->next;
    }
    if (ptr->info==val) return pra;
    else return NULL;
    }
}

void SLL::del(int val) {
    Node *ptr = find(val);
    if (ptr==head) head=head->next;
    else {
    ptr = find_before(val);
    if (ptr!=NULL) {
    if (ptr->next==tail) tail=ptr;
    ptr->next=(ptr->next)->next;
    }
    }
}


int main() {
    SLL list;
    list.make();
    list.push_back(100); list.push_back(50);
    list.push_front(75); list.print();
    list.push_after(35,100); list.print();
    list.del(50); list.print();
    return 0;
}

