#include <iostream>
#include <iomanip>

using namespace std;

struct node
{
	double info;
	struct node *next;
	struct node *prev;
};
typedef struct node Node;


class Ayam
{
private:
	Node *head, *tail;
public:
	void make() { head = NULL; tail = NULL; }
	Node *make(double val);
	int isEmpty(){ return (head == NULL); }
	void push_back(double val);
	void push_before(double val, Node *ptr);
	Node *find(double val);
	void print();
	void seleksi(double val);
	void alternatif(double val);
};

Node* Ayam::make(double val){
	Node *ptr = new(Node);
	ptr->info = val;
	ptr->next = NULL;
	ptr->prev = NULL;
	return ptr;
}

void Ayam::push_back(double val){
	Node *ptr = make(val);

	if (isEmpty())
		head = tail = ptr;
	else{
		ptr->prev = tail;
		tail->next = ptr;
		tail = ptr;
	}
}

void Ayam::push_before(double val, Node *ptr){
	Node *temp = make(val);
	//Node *pta = find_before(val);

	if (ptr != NULL){
		if (ptr == head){
			temp->next = head;
			head->prev = temp;
			head = temp;
			//push_front(val);
		}
		else{
			temp->next = ptr;
			(ptr->prev)->next = temp;
			temp->prev=ptr->prev;
			ptr->prev=temp;
		}
	}
}

Node* Ayam::find(double val){
	Node *ptr = head;
	Node *pta = head;
	if (isEmpty())
		return NULL;
	else{
		while (ptr->next != NULL && ptr->info<=val){
            pta = ptr;
			ptr = ptr->next;
		}
		if (ptr->info>val){
		    if(pta->info==val){
                return pta;
		    }else{
                return ptr;
		    }
		}else{
			return NULL;
		}
	}
}

void Ayam::seleksi(double val){
	Node *ptr;
	if (isEmpty()){
		push_back(val);
	}
	else{
		ptr = find(val);
		if (ptr != NULL){
			push_before(val, ptr);
		}
		else{
			push_back(val);
		}
	}
}

void Ayam::alternatif(double val){
	Node *ptr = make(val);
	Node *tunjuk;
	Node *akhir;
	if (isEmpty()){
		push_back(val);
	}else if (tail->info <= val){
		push_back(val);
	}else if (head->info > val){
		//push_front(val);
	}else{
		tunjuk = find(val);
		ptr->next = tunjuk;
		(tunjuk->prev)->next = ptr;
	}
}
void Ayam::print(){
	Node * ptr = head;
	for (; ptr != NULL; ptr = ptr->next){
		cout << fixed << setprecision(1) << ptr->info << "->";
	}
	cout << "NULL" << endl;
}

int main(){
    Ayam ay;
	int n,m;
	double data,add;

	ay.make();

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> data;
		//ay.seleksi(data);
		ay.push_back(data);
	}
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> add;
		ay.seleksi(add);
		//ay.alternatif(data);
	}
	ay.print();
    return 0;
}
