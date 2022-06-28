#include <iostream>
using namespace std;

void insertInHeap(int *arr, int n) {
	for(int index = 1; index < n; index++) {
		int temp = arr[index];
		int parentIndex = (index - 1)/2;
		while(temp > arr[parentIndex]) {
			arr[index] = arr[parentIndex];
			index = parentIndex;
			if(index == 0) {
				break;
			}
			parentIndex = (index - 1)/2;
		} arr[index] = temp;
	}
}

void deleteAndSort(int *arr, int &n) {
	int index = 0, leftIndex, rightIndex;
	int item = arr[0], last = arr[n - 1];
	leftIndex = 2 * index + 1;
	rightIndex = leftIndex + 1; 
	n--;
	while(leftIndex < n) {
		int childIndex = arr[leftIndex] > arr[rightIndex] ? leftIndex : rightIndex;
		if(last > arr[childIndex]) {
			arr[index] = last; 
			break;
		}	
		else {
			arr[index] = arr[childIndex];
			index = childIndex;
		}
		leftIndex = 2 * index + 1;
		rightIndex = leftIndex + 1; 
	} arr[index] = last;
	arr[n] = item;
}

void HeapSort(int *arr, int n) {
	insertInHeap(arr, n);
	while(n > 0) {
		deleteAndSort(arr, n);
	}
}

int main() {
	int n; cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	} 	
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	} cout << "\n";
	HeapSort(arr, n);
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	} cout << "\n";		
	delete[] arr;
}
