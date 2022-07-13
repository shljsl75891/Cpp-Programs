#include <iostream>
using namespace std;

void heapify(int *arr, int size, int index) {
    int largest = index;
    int left = 2 * index + 1, right = left + 1;
    if(left < size && arr[largest] < arr[left]) {
        largest = left;
    } if(right < size && arr[largest] < arr[right]) {
        largest = right;
    } if(largest != index) {
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}

void HeapSort(int *arr, int size) {
    for(int i = size/2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    } while(size > 0) {
        swap(arr[size - 1],arr[0]);
        size--;
        heapify(arr, size, 0);
    } 
}

int main() {
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    } HeapSort(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
}