#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Heap {
	int capacity;
	int *ptr;
	int size;
protected:
	int left(int index) {
		return index * 2 + 1;
	}
	int parent(int index) {
		int halfIndex = index / 2;
		return index & 1 ? halfIndex : halfIndex - 1;
	}
public:
	Heap(int cap) {
		capacity = cap;
		ptr = new int[capacity];
		size = 0;	
	}
	void takeInput() {
		int n = capacity;
		while(n--) {
			int data; cin >> data;
			insertData(data);
		}
	}
	void insertData(int data) {
		if(size == capacity) {
			cout << "Heap is full\n";
			return;
		}
		int index = size, temp = data;
		int parentIndex = parent(index);
		if(size == 0) {
			ptr[0] = data;
			size++;
			return;
		}
		while(temp > ptr[parentIndex]) {
			ptr[index] = ptr[parentIndex];
			index = parentIndex;
			if(index == 0) {
				break;
			}
			parentIndex = parent(index);
		}		
		ptr[index] = temp;
		size++;
	}
	void deleteData() {
		if(size == 0) {
			cout << "Heap is already empty\n";
			return;
		}
		int index = 0, item = ptr[index], temp = ptr[size - 1]; size--;
		int leftIndex = left(index), rightIndex = leftIndex + 1;
	 	while(leftIndex < size) {
			if(ptr[leftIndex] >= ptr[rightIndex]) {
				if(temp > ptr[leftIndex]) {
					ptr[index] = temp;
					break;
				}
				else {
					ptr[index] = ptr[leftIndex];
					index = leftIndex;
				}
			}
			else {
				if(temp > ptr[rightIndex]) {
					ptr[index] = temp;
					break;
				}
				else {
					ptr[index] = ptr[rightIndex];
					index = rightIndex;
				}
			}
			leftIndex = left(index);
			rightIndex = leftIndex + 1;
		}
		ptr[index] = temp;
		ptr[size] = item;	
	}
	void print() {
		if(size == 0) {
			cout << "Heap is empty";
			return;
		}
		for(int i = 0; i < size; i++) {
			cout << ptr[i] << " ";
		}
	}
	void printAfterDeletion() {
		for(int i = 0; i < capacity; i++) {
			cout << ptr[i] << " ";
		}
	}
	~Heap() {
		delete[] ptr;
	}
};

int choice() {
	cout << "\n1. Take Input\n2. Insert Data\n3. Delete Data\n4. Print After deletion\n5. Exit\n";
	int choice; cout << "Enter your choice: ";
	cin >> choice; return choice;
}

int main() 	{
	int cap; cout << "Enter capacity: ";
	cin >> cap;
	Heap hp(cap);
	while(true) {
		system("cls");
		cout << "Heap: "; hp.print();
		switch(choice()) {
			case 1: {
                hp.takeInput();
                break;
			}
			case 2: {
                int data; cout << "Enter the data: ";
                cin >> data; hp.insertData(data);
                break;
			}
			case 3: {
                hp.deleteData();
                break;			
			}
			case 4: {
                hp.printAfterDeletion();
                break;
			}
			case 5: {
                exit(0);
			}
			default : {
                cout << "Invalid Choice";
			}
		}
		getch();
	}
}
