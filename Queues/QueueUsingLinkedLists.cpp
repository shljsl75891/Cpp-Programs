#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

class Queue {
    struct Node {
        int data; 
        Node *next;
        Node(int data) {
            this->data = data;
            next = NULL;
        }
    }; Node *front, *rear;
public:
    Queue() {
        front = rear = NULL;
    } void insertData(int data) {
        Node *newNode = new Node(data);
        if(front == NULL && rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    } void deleteData() {
        if(front == NULL && rear == NULL) {
            cout << "Queue is already empty";
        } else if(front == rear) {
            Node *t = front;
            front = rear = NULL;
            delete t;
        } else {
            Node *t = front;
            front = front->next;
            delete t;
        }
    } int displayFront() {
        if(front == NULL) {
            return -1;
        } return front->data;
    } int displayRear() {
        if(rear == NULL) {
            return -1;
        } return rear->data;
    }
};

int choice() {
    cout << "1.Insert Data in queue\n2. Delete Data\n3. Exit\n";
    cout << "Enter your choice: ";
    int choice; cin >> choice;
    return choice;
}

int main() {
    Queue Q;
    while(true) {
        system("cls");
        cout << "Front: " << Q.displayFront() << endl;
        cout << "Rear: " << Q.displayRear() << endl;
        switch(choice()) {
            case 1: {
                int data; cout << "Enter the data: ";
                cin >> data;
                Q.insertData(data);
                break;
            } case 2: {
                Q.deleteData();
                break;
            } case 3: {
                exit(0);
            } default: {
                cout << "Invalid Choice";
            }
        }
        getch();
    }
}