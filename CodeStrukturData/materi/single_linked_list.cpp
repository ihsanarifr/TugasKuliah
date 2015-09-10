#include <iostream>

using namespace std;

struct node {
   int value;
   struct node *next;
};
typedef struct node NODE;

class SLL {
    NODE *head;
    public:
        SLL() {
            head = NULL;
        };
        void insert_front(int newvalue) {
            NODE *newnode = new NODE;
            newnode->value = newvalue;
            newnode->next = head;
            head = newnode;
        };
        void insert_back(int newvalue) {
            NODE *newnode = new NODE;
            NODE *ptr = head;
            newnode->value = newvalue;
            while(ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        };
        void delete_front() {
            NODE *del = head;
            head = head->next;
            delete del;
        };
        void delete_back() {
            NODE *del = head;
            while(del->next != NULL && del->next->next != NULL) {
                del = del->next;
            }
            delete del->next;
            del->next = NULL;
        };
        NODE* get_node_at(int index) {
            NODE *n = head;
            for(int i = 0; i < index; i++) {
                n = n->next;
            }
            return n;
        };
        void insert_after(NODE* n, int newvalue) {
            NODE *newnode = new NODE;
            newnode->value = newvalue;
            newnode->next = n->next;
            n->next = newnode;
        };
        void delete_node(NODE* n) {
            if (n == head) {
                delete_front();
                return;
            }

            NODE *ptr = head;
            while(ptr->next != n) {
                ptr = ptr->next;
            }
            ptr->next = n->next;
            delete n;
        };
        void update_node(NODE *n, int newvalue) {
            n->value = newvalue;
        };
        void print() {
            NODE *ptr = head;
            while(ptr != NULL) {
                cout << ptr->value << " -> ";
                ptr = ptr->next;
            }
            cout << "NULL" << endl;
        };
};

int main() {
    SLL list;
    list.insert_front(3);
    list.insert_front(5);
    list.insert_front(10);
    list.insert_front(2);
    list.insert_back(7);
    list.insert_back(9);
    list.print();		// {2,10,5,3,7,9}

    NODE* n = list.get_node_at(0);
    list.delete_node(n);

    list.print();

    return 0;
}

