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
    int waiting;
};

typedef struct Node
{
    Passenger passenger;
    Node *prev, *next;
}NODE;

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
    void calculate();
    int get(int id);
};

int main()
{
    // TO DO

    Queue queue;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
    	Passenger p;
    	string kelas;
    	cin >> kelas;

		if(kelas == "E")
			p.priority = ECONOMY_CLASS;
		else if (kelas == "B")
			p.priority = BUSINESS_CLASS;
		else
			p.priority = EXECUTIVE_CLASS;

		p.id = i+1;
		cin >> p.serviceTime;

		queue.push(p);
    }

    queue.calculate();

    /*for(int i = 0; i < n; i++)
    {
    	cout << queue.front().id << " " << queue.front().priority << " " << queue.front().waiting << endl;
		queue.pop();
	}*/

	for(int i = 1; i < n; i++)
    {
		cout << queue.get(i) << " ";
	}
	cout << queue.get(n) << endl;
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
         Front = temp;
         Rear = temp;
    }
    else
    {
    	if(front().priority < p.priority)
    	{
    		// push front
    		temp->next = Front;
    		Front->prev = temp;
    		Front = temp;
    	}
    	else
    	{

	         // insert
	         Node * ptr = Front;

	         while(ptr->passenger.priority > p.priority && ptr->next != NULL)
	         	ptr = ptr->next;

	     	 while(ptr->next != NULL && ptr->next->passenger.priority == p.priority)
	     		ptr = ptr->next;

	     	// jika tidak belakang
	     	if(ptr->next == NULL)
	     	{

		     	// push back
		     	ptr->next = temp;
		     	temp->prev = ptr;

		     	while(ptr->next != NULL)
		     		ptr = ptr->next;

		     	Rear = ptr;
	   		}
	   		else
	   		{
	   			Node * after = ptr->next;

	   			ptr->next = temp;
	   			temp->prev = ptr;
	   			temp->next = after;
	   			after->prev = temp;
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

void Queue::calculate()
{
	Node * temp = Front;

	int wait = 0;

	while(temp!= NULL)
	{
		temp->passenger.waiting = wait;
		wait += temp->passenger.serviceTime;

		temp = temp->next;
	}

}

int Queue::get(int id)
{
	Node * temp = Front;

	while(temp != NULL && temp->passenger.id != id)
	{
		temp = temp->next;
	}

	return temp->passenger.waiting;
}
