  0 #include <iostream>
  1 using namespace std;
  2 
  3 void insertionSort(int *arr, int size) {
  4         for(int i = 1; i < size; i++) {
  5                 int temp = arr[i];
  6                 int j = i - 1;
  7                 while(j >= 0 && arr[j] > temp) {
  8                         arr[j + 1] = arr[j];
  9                         j = j - 1;
 10                 } arr[j + 1] = temp;
 11         }
 12 }
 13 
 14 int main() {
 15         int n; cin >> n;
 16         int *arr = new int[n];
 17         for(int i = 0; i < n; i++) {
 18                 cin >> arr[i];
 19         } insertionSort(arr, n);
 20         for(int i = 0; i < n; i++) {
 21                 cout << arr[i] << " ";
 22         } delete[] arr;
 23 }
~              
