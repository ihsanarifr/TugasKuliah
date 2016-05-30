#include <iostream>
#include <queue>
typedef priority_queue<int> Queue;

int main(){
    Queue antrian;
    antrian.push(30);
    antrian.push(100);
    antrian.push(25);
    antrian.push(40);

    cout << "Queue awal:\n";
    cout << antrian;

    antrian.pop();
    antrian.pop();

    cout << "\nQueue akhir: \n";
    cout << antrian
    return 0;
}
