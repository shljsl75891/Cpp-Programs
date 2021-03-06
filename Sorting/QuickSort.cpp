#include <iostream>
using namespace std;

int Quick(int arr[], int left, int right) {
    int pivot = left;
    while(true) {
        while(left < right && arr[pivot] <= arr[right]) {
            right--; 
        }
        if(left == right) {
            break;
        }
        else {
            swap(arr[pivot], arr[right]);
            pivot = right;
        }
        while(left < right && arr[pivot] > arr[left]) {
            left++; 
        }
        if(left == right) {
            break;
        }
        else {
            swap(arr[pivot], arr[left]);
            pivot = left;
        }
    } return pivot;
}

void QuickSort(int arr[], int left, int right) {
    int pivot = Quick(arr, left, right); 
    if(left + 1 < pivot) {
        QuickSort(arr, left, pivot - 1);
    }
    if(right - 1 > pivot) {
        QuickSort(arr, pivot + 1, right);
    }
}

int main() {
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    } QuickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } 
}