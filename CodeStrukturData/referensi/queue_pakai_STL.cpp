#include<iostream>
#include<queue>
typedef queue<int> Queue;

ostream& operator<< (ostream &out, Queue q){
    if(q.empty())
        out << "Queue is empty\n";
    else{
        while(!q.empty()){
            out << q.front() << endl;
            q.pop();
        }
    }
    return out;
}
