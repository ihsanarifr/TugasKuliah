/*
 Maskapai AgriAir adalah maskapai baru yang berlokasi di sebuah bandara di Bogor. Maskapai tersebut memiliki 1 loket pemeriksaan tiket yang harus dilalui penumpang sebelum menaiki pesawat. Karena masih baru, mekanisme pengecekan tiket di maskapai tersebut masih tidak efisien. Mekanisme tersebut ialah sebagai berikut:

    Ketika waktu check in telah tiba, petugas loket akan meminta seluruh penumpang membentuk satu barisan yang diurutkan berdasarkan nomor tiket yang mereka pegang. Nomor tiket berada pada rentang [1, 1000].
    Setelah itu, penumpang kelas eksekutif diminta untuk maju ke depan antrian, diikuti dengan penumpang kelas bisnis, dan terakhir penumpang kelas ekonomi.
    Setelah itu, penumpang mulai dari depan akan dilayani oleh petugas loket. Yang dilakukan oleh petugas loket ialah memeriksa identitas penumpang dan memastikan tiket penumpang.

Anda diminta untuk mensimulasikan antrian tersebut dalam bentuk program dengan menggunakan struktur data priority queue. Program Anda harus dapat mencetak waktu tunggu dari masing-masing penumpang. Waktu tunggu dari seorang penumpang dihitung sejak penumpang pertama mulai dilayani sampai ia mulai dilayani.

Selain berdasarkan test case, jawaban Anda juga akan diperiksa secara manual.
Format Masukan

Baris pertama merupakan jumlah penumpang N. N baris kemudian terdiri atas sebuah karakter dan sebuah bilangan bulat. Karakter ‘E’ untuk penumpang kelas ekonomi, ‘B’ untuk kelas bisnis, dan ‘X’ untuk kelas eksekutif. Bilangan bulat yang diberikan merupakan durasi pelayanan penumpang tersebut di loket pelayanan. Urutan penumpang telah diurutkan berdasarkan nomor tiket (penumpang pertama memiliki nomor tiket 1).
Format Keluaran

Keluaran lama waktu menunggu untuk setiap penumpang, diurutkan dari penumpang dengan nomor tiket terkecil. Keluaran diakhiri oleh karakter newline.
Contoh Masukan

6
E 3
E 2
B 3
X 2
X 2
B 1

Contoh Keluaran

8 11 4 0 2 7

Penjelasan

6
E 3    //penumpang dengan nomor tiket 1
E 2    //penumpang dengan nomor tiket 2
B 3    //penumpang dengan nomor tiket 3
X 2    //penumpang dengan nomor tiket 4
X 2    //penumpang dengan nomor tiket 5
B 1    //penumpang dengan nomor tiket 6

Setelah diurutkan dengan algoritme di atas, antrian berubah menjadi:
X 2    //penumpang dengan nomor tiket 4, waktu tunggu 0
X 2    //penumpang dengan nomor tiket 5, waktu tunggu 2
B 3    //penumpang dengan nomor tiket 3, waktu tunggu 4
B 1    //penumpang dengan nomor tiket 6, waktu tunggu 7
E 3    //penumpang dengan nomor tiket 1, waktu tunggu 8
E 2    //penumpang dengan nomor tiket 2, waktu tunggu 11

Dengan demikian, waktu tunggu pada antrian untuk setiap penumpang mulai dari nomor tiket terkecil ialah:
8 11 4 0 2 7
Kode Kerangka untuk Priority Queue

#include <iostream>
#include <queue>
#define ECONOMY_CLASS 0
#define BUSINESS_CLASS 1
#define EXECUTIVE_CLASS 2
#define MAX_PASSENGER 1000

using namespace std;

struct Passenger
{
    int id;
    int serviceTime;
    int priority;
};

typedef struct Node
{
    Passenger passenger;
    Node *prev, *next;
};

bool operator<(const Passenger a, const Passenger b)
{
    return a.priority < b.priority;
}

class Queue
{
    Node *Front, *Rear;
public:
    Queue() {
        Front = NULL;
        Rear = NULL;
    };
    bool empty(){return (Front == NULL);};
    void push(Passenger p);
    Passenger front();
    Passenger back();
    void pop();
};

int main()
{
    // TO DO
}

void Queue::push(Passenger p)
{
    Node *temp = new(Node);
    temp->passenger = p;
    temp->prev=NULL;
    temp->next=NULL;
    if(empty())
    {
         // TO DO
    }
    else
    {
         // TO DO
    }
}
void Queue::pop()
{
    if(empty())
        cout << "Queue is empty\n";
    else
        Front = Front -> next;

}

Passenger Queue::front()
{
    if(!empty())
        return Front -> passenger;
}

Passenger Queue::back()
{
    if(!empty())
        return Rear-> passenger;
}
*/
#include <iostream>
#include <queue>
#define ECONOMY_CLASS 0
#define BUSINESS_CLASS 1
#define EXECUTIVE_CLASS 2
#define MAX_PASSENGER 1000

using namespace std;

struct Passenger
{
    int id;
    int serviceTime;
    int priority;
};

typedef struct Node
{
    Passenger passenger;
    Node *prev, *next;
};

bool operator<(const Passenger a, const Passenger b)
{
    return a.priority < b.priority;
}

class Queue
{
    Node *Front, *Rear;
public:
    Queue() {
        Front = NULL;
        Rear = NULL;
    };
    bool empty(){return (Front == NULL);};
    void push(Passenger p);
    Passenger front();
    Passenger back();
    void pop();
};

int main()
{
    Queue antrian;
    int an,jumlah;
    string perintah;

    // TO DO
    cin >> an;
    for(int i=0;i<an;i++){
        Passenger pa;
        cin >> perintah >> jumlah;
        if(perintah=="E"){
           pa.priority = ECONOMY_CLASS;
        }else if(perintah=="B"){
            pa.priority = BUSINESS_CLASS;
        }else if(perintah=="X"){
            pa.priority = EXECUTIVE_CLASS;
        }
    }
}

void Queue::push(Passenger p)
{
    Node *temp = new(Node);
    temp->passenger = p;
    temp->prev=NULL;
    temp->next=NULL;

    if(empty())
    {
         // TO DO
         Front=temp;
         Rear=temp;
    }
    else
    {
         // TO DO
         if(front().priority < p.priority){
            temp->next=Front;
            Front->next=temp;
            Front=temp;
         }else{
             Node *ptr = Front;

             while(ptr->passenger.priority > p.priority && ptr->next != NULL){
                ptr = ptr->next;
             }
             while(ptr->next != NULL && ptr->next->passenger.priority == p.priority){
                ptr = ptr->next;
             }

             if(ptr->next==NULL){
                ptr->next=temp;
                temp->prev=ptr;

                while(ptr->next != NULL){
                    ptr= ptr->next;
                }
                Rear = ptr;
             }else{
                 Node *balik = ptr->next;

                 ptr->next=temp;
                 temp->prev=ptr;
                 temp->next=balik;
                 balik->prev= temp;
             }
         }
    }
}
void Queue::pop()
{
    if(empty())
        cout << "Queue is empty\n";
    else
        Front = Front -> next;

}

Passenger Queue::front()
{
    if(!empty())
        return Front -> passenger;
}

Passenger Queue::back()
{
    if(!empty())
        return Rear-> passenger;
}
