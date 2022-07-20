#include <iostream>
using namespace std;

void Merge(int *arr, int mid, int low, int high) {
    int i, j, k, left[mid - low + 1], right[high - mid];
    for(i = 0; i < mid - low + 1; i++) {
        left[i] = arr[i + low];
    } for(j = 0; j < high - mid; j++) {
        right[j] = arr[j + mid + 1];
    } for(k = low, i = 0, j = 0; i < mid - low + 1 && j < high - mid; k++) {
        if(left[i] <= right[j]) {
            arr[k] = left[i++];
        } else {
            arr[k] = right[j++];
        }
    } while(i < mid - low + 1) {
        arr[k++] = left[i++];
    } while(j < high - mid) {
        arr[k++] = right[j++];
    }
}

void MergeSort(int *arr, int low, int high) {
    if(low == high) return;
    int mid = low + (high - low)/2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge(arr, mid, low, high);
}

int main() {
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    } MergeSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } 
}
