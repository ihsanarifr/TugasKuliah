/*
Buat ADT SLL2 yang memiliki kemampuan sama seperti SLL pada contoh di kuliah, tetapi informasi yang ditangani adalah nim dan ipk (float). Dapat dijalankan dengan driver seperti contoh berikut:

int main() {
   SLL2 list;
   list.make();
   list.push_back("G64204100", 3.14);
   list.push_back("G64204050", 3.67);
   list.push_front("G6420075", 2.05);
   list.print();
   list.push_after("G6420035", 2.89, "G64204100");
   list.print(); list.del("G64204100");
   list.print();
   return 0;
}
Format Masukan

Tidak ada data masukan, karena seluruh data untuk menguji ADT telah disimpan dalam driver.

Format Keluaran

Output sesuai dengan instruksi yang ada dalam driver.

Contoh Masukan

Tidak ada data masukan

Contoh Keluaran

(G6420075,2.05)->(G64204100,3.14)->(G64204050,3.67)->NULL
(G6420075,2.05)->(G64204100,3.14)->(G6420035,2.89)->(G64204050,3.67)->NULL
(G6420075,2.05)->(G6420035,2.89)->(G64204050,3.67)->NULL
*/

#include <iostream>

using namespace std;

struct node {
    string nama;
    float info;
    struct node *next;
};
typedef struct node Node;

class SLL {
    Node *head, *tail;
public:
    void make() { head=NULL; tail=NULL;}
    Node* make(string nam,float val); // make a node
    int isEmpty() { return (head==NULL); }
    void push_back(string nam,float val);
    void push_front(string nam,float val);
    void push_after(string nam, float val, string after);
    Node *find(string val);
    Node *find_before(string val);
    void del(string val);
    void print();
};

Node* SLL::make(string nam,float val) {
    Node *temp = new(Node);
    temp->info=val;
    temp->nama=nam;
    temp->next=NULL;
    return temp;
}

void SLL::push_back(string nam,float val) {
    Node *ptr=make(nam,val);
    if (isEmpty()) {
        head=ptr; tail=ptr;
    } else {
        tail->next=ptr; tail=ptr;
    }
}

void SLL::push_front(string nam,float val) {
    Node *ptr=make(nam,val);
    if (isEmpty()) {
        head=ptr; tail=ptr;
    } else {
        ptr->next=head; head=ptr;
    }
}

void SLL::print() {
    Node *ptr=head;
    for (; ptr!=NULL; ptr=ptr->next)
    cout << "(" << ptr->nama <<","<< ptr->info << ")"<< "->";
    cout << "NULL" << endl;
}

Node* SLL::find(string nam) {
    Node *ptr=head;
    if (isEmpty())
        return NULL;
    else {
        while (ptr->next!=NULL && ptr->nama!=nam) {
        ptr=ptr->next;
    }
    if (ptr->nama==nam) return ptr;
    else return NULL;
    }
}

void SLL::push_after(string nam, float val, string after) {
    Node *ptr = find(after);
    if (ptr!=NULL) {
    Node *temp = make(nam,val);
    temp->next = ptr->next;
    ptr->next = temp;
    }
}

Node* SLL::find_before(string nam) {
    Node *ptr=head; Node *pra=head;
    if (isEmpty()) return NULL;
    else {
    while (ptr->next!=NULL && ptr->nama!=nam) {
    pra=ptr; ptr=ptr->next;
    }
    if (ptr->nama==nam) return pra;
    else return NULL;
    }
}

void SLL::del(string val) {
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
   list.push_back("G64204100", 3.14);
   list.push_back("G64204050", 3.67);
   list.push_front("G6420075", 2.05);
   list.print();
   list.push_after("G6420035", 2.89, "G64204100");
   list.print(); list.del("G64204100");
   list.print();
   return 0;
}
