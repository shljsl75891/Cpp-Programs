#include <iostream>
using namespace std;

void insertionSort(int *arr, int size) {
        for(int i = 1; i < size; i++) {
                int temp = arr[i];
                int j = i - 1;
                while(j >= 0 && arr[j] > temp) {
                        arr[j + 1] = arr[j];
                        j = j - 1;
                } arr[j + 1] = temp;
        }
}

int main() {
        int n; cin >> n;
        int *arr = new int[n];
        for(int i = 0; i < n; i++) {
                cin >> arr[i];
        } insertionSort(arr, n);
        for(int i = 0; i < n; i++) {
                cout << arr[i] << " ";
        } delete[] arr;
}