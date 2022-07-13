#include <iostream>
using namespace std;

int minIndex(int *arr, int size, int index) {
    int min_index = -1, minValue = INT_MAX;
    for(int i = index; i < size; i++) {
        if(minValue > arr[i]) {
            min_index = i;
            minValue = arr[i];
        }
    } return min_index;
}

void SelectionSort(int *arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        int min_index = minIndex(arr, size, i);
        swap(arr[i], arr[min_index]);
    }
}

int main() {
    int n; cin >> n; 
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    } SelectionSort(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}