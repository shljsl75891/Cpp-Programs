#include <iostream>
using namespace std;

class QueueUsingArrays {
    int capacity;
    int front, rear;
    int *ptr;
public:
    QueueUsingArrays(int capacity) {
        ptr = new int[capacity];
        front = rear = -1;
        this->capacity = capacity;
    }
    void insertData(int data) {
        if(front == 0 && rear == capacity - 1 || rear + 1 == front) {
            cout << "Operation Failed : Queue is Full\n";
        }
        else if(front == -1 && rear == -1) {
            front = rear = 0;
            ptr[rear] = data;
        }
        else if(rear == capacity - 1) {
            rear = 0;
            ptr[rear] = data;
        }
        else {
            rear++;
            ptr[rear] = data;
        }
    }
    void deleteData() {
        if(front == -1 && rear == -1) {
            cout << "Operation Failed : Queue is Empty\n";
        }
        else if(rear == front) {
            front = rear = -1;
        }
        else if(front == capacity - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }
    void displayFront() {
        if(front == -1) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front: " << front << "  Value: " << ptr[front] << "\n";
    }
    void displayRear() {
        if(rear == -1) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Rear: " << rear << "  Value: " << ptr[rear] << "\n";
    }
};

int main() {
    QueueUsingArrays Q(9);  
    
}