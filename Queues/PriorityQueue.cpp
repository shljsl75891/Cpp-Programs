#include <iostream>
using namespace std;

class PriorityQueue {
    int capacity, priority;
    int *front, *rear;
    int **ptr;
public:
    PriorityQueue(int priority, int capacity) {
        ptr = new int*[priority];
        this->priority = priority;
        this->capacity = capacity;
        for(int i = 0; i < priority; i++) {
            ptr[i] = new int[capacity];
        }

        front = new int[capacity];
        for(int i = 0; i < capacity; i++) {
            front[i] = -1;
        }
        rear = new int[capacity];
        for(int i = 0; i < capacity; i++) {
            rear[i] = -1;
        }
    }
    void insertData(int data, int priority) {
        if(priority > this->priority) {
            cout << "Invalid Priority\n";
        }
        else {
            if(front[priority - 1] == 0 && rear[priority - 1] == capacity - 1 || rear[priority - 1] + 1 == front[priority - 1]) {
                cout << "Operation Failed : Queue of priority " << priority << " is Full\n";
            }
            else if(front[priority - 1] == -1 && rear[priority - 1] == -1) {
                front[priority - 1] = rear[priority - 1] = 0;
                ptr[priority - 1][rear[priority - 1]] = data;
            }
            else if(rear[priority - 1] == capacity - 1) {
                rear[priority - 1] = 0;
                ptr[priority - 1][rear[priority - 1]] = data;
            }
            else {
                rear[priority - 1]++;
                ptr[priority - 1][rear[priority - 1]] = data;
            }
        }
    }
    void deleteData() {
        while(front[priority - 1] == -1) {
            priority--;
        }
        if(priority == 0) {
            cout << "Operation Failed : Priority Queue is empty";
        }
        else {
            if(rear[priority - 1] == front[priority - 1]) {
                front[priority - 1] = rear[priority - 1] = -1;
            }
            else if(front[priority - 1] == capacity - 1) {
                front[priority - 1] = 0;
            }
            else {
                front[priority - 1]++;
            }
        }
    }
    void displayAllFront() {
        for(int i = 0; i < priority; i++) {
            cout << "Priority: " << i + 1 << " Front: " << front[i] << " Value: " << ptr[i][front[i]] << endl; 
        }
    }
    void displayAllRear() {
        for(int i = 0; i < priority; i++) {
            cout << "Priority: " << i + 1 << " Rear: " << rear[i] << " Value: " << ptr[i][rear[i]] << endl; 
        }
    }
    ~PriorityQueue() {
        for(int i = 0; i < priority; i++) {
            delete[] ptr[i];
        }
        delete[] ptr;
    }
};

int main() {
    PriorityQueue PQ(5, 5);
    PQ.insertData(5, 5);
    PQ.insertData(6, 1);
    PQ.insertData(18, 2);
    PQ.insertData(10, 3);
    PQ.insertData(13, 4);
    PQ.insertData(11, 5);
    PQ.insertData(9, 5);
    PQ.insertData(43, 5);
    PQ.insertData(23, 5);
    PQ.deleteData();
    PQ.deleteData();
    PQ.insertData(39,5);
    PQ.insertData(12, 5);
    PQ.displayAllFront();
    PQ.displayAllRear();
}