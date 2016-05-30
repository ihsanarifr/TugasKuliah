/* belajar buat single linked list sendiri

Output
75 -> 100 -> 50 -> NULL
75 -> 100 -> 35 -> 50 -> NULL
75 -> 100 -> 35 -> NULL

*/
#include<iostream>

using namespace std;

struct node{
    int posisi;
    string warna;
    struct node *next;
};
typedef struct node Node;

class SLL{
    Node *head, *tail;
public:
    void make() { head=NULL;tail=NULL;}
    Node *make(string warna,int posisi);
    int isEmpty(){ return (head==NULL);}
    void push_back(string warna,int posisi);
    void push_front(string warna,int val);
    void push_after(string warna,int val,int after);
    Node *find_warna(string warna);
    Node *find_posisi(string warna, int posisi);
    Node *posisikan(string warna, int posisi);
    void print();
};

Node* SLL::make(string warna,int posisi)
{
    Node *ptr = new(Node);
    ptr->warna=warna;
    ptr->posisi=posisi;
    ptr->next=NULL;
    return ptr;
}

void SLL::push_back(string warna, int posisi){
    Node *ptr = make(warna,posisi);
    if(isEmpty()){
        head=ptr;
        tail=ptr;
    }else{
        tail->next=ptr;
        tail=ptr;
    }
}

void SLL::push_front(string warna,int posisi){
    Node *ptr = make(warna,posisi);
    if(isEmpty()){
        head=ptr;
        tail=ptr;
    }else{
        ptr->next=head;head=ptr;
    }
}
//void SLL::push_after(string warna,int posisi,int after){
//    Node *temp=make(warna,posisi);
//    //Node *ptr=find(warnaafter);
//    if(ptr!=NULL){
//        temp->next=ptr->next;
//        ptr->next=temp;
//    }
//}
Node* SLL::find_warna(string warna){
    Node* ptr=head;
    if(isEmpty()){
        return NULL;
    }else{
        while(ptr->next!=NULL && ptr->warna!=warna){
            ptr=ptr->next;
        }
        if(ptr->warna==warna){
            return ptr;
        }else{
            return NULL;
        }
    }
}
Node* SLL::find_posisi(string warna,int posisi){
    Node* ptr=head;
    if(isEmpty()){
        return NULL;
    }else{
        while(ptr->next!=NULL && (ptr->posisi>=posisi || ptr->warna!=warna){
            ptr=ptr->next;
        }
        if(ptr->info>warna){
            return ptr;
        }else{
            return NULL;
        }
    }
}

Node* SLL::posisikan(string warna,int posisi){
    Node* samawarna = find_warna(warna);
    Node* kurangdariposisi = find_posisi(posisi);
    if(isEmpty()){
        push_back(warna,posisi);
    }

    // cek jika ada warna yang sama
    if(samawarna!= NULL){
        // posisi kurang dari
        if(kurangdariposisi!=NULL)
    }else{
        push_back(warna,posisi)
    }
}

void SLL::print(){
    Node *ptr=head;
    for(;ptr!=NULL;ptr=ptr->next)
        cout << ptr->warna << ":" << ptr->posisi << "->";
    cout << "NULL" << endl;
}
int main()
{
    SLL list;
    int n,posisi;
    string data;
    list.make();

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> data >> posisi;
        list.posisikan(data,posisi);
        //list.find(data,posisi);
        //list.push_back(data,posisi);
    }
    list.print();
    return 0;
}
