#include <iostream>
using namespace std;

template<typename type>
class LinkedList {
    struct Node {
        type data;
        Node *next = NULL;
        Node(type data) {
            this->data = data;
            next = NULL;
        }
    }; Node *head;
protected:
    Node* search(type key) {
        Node *t = head;
        while(t != NULL && t->data != key) {
            t = t->next;
        } return t;
    }
public:
    LinkedList() {
        head = NULL;
    }
    void takeInput() {
        while(true) {
            int data; cin >> data;
            if(data == -1) {
                break;
            } insertAtTail(data);
        }
    }
    void insertAtHead(type data) {
        Node *newNode = new Node(data);
        if(head != NULL) {
            newNode->next = head;
        } head = newNode;
    }
    void insertAtTail(type data) {
        Node *newNode = new Node(data);
        if(head == NULL) {
             head = newNode;
        } else {
            Node *t =head;
            while(t->next) {
                t = t->next;
            } t->next = newNode;
        }
    }
    void insertData(type data, type key) {
        Node *before = search(key);
        if(before != NULL) {
            Node *newNode = new Node(data);
            if(before->next == NULL) {
                insertAtTail(data);
            } else {
                newNode->next = before->next;
                before->next = newNode;
            }
        } else {
            cout << "Operation Failed: Key Not Found\n";
        }
    }
    
    void deleteHead() {
        if(head == NULL) {
            cout << "Linked List is already empty\n";
            return;
        } Node* t = head;
        head = head->next;
        delete t;
    }
    void deleteTail() {
        if(head == NULL) {
            cout << "Linked List is already empty\n";
            return;
        }
        Node *t = head;
        while(t->next) {
            t = t->next;
        } Node *toDelete = t->next;
        t->next = NULL;
        delete toDelete;
    }
    void deleteData(int data) {
        Node *t = search(data);
        if(t == NULL) {
            cout << "Operation Failed: Key Not Found\n";
        } else if (t->next == NULL) {
            deleteTail();
        } else if(t == head) {
            deleteHead();
        } else {
            Node *toDelete = t->next;
            t->data = t->next->data;
            t->next = t->next->next;
            delete toDelete;
        }
    }
    void displayList() {
        Node *t = head;
        while(t) {
            cout << t->data << " ";
            t = t->next;
        }
    }
    ~LinkedList() {
        while(head) {
            deleteHead();
        }
    }
};

int main() {
    LinkedList<int> list;
    list.takeInput();
    list.insertData(2, 1);
    list.insertData(9, 4);
    list.deleteData(9);
    list.displayList();
}
