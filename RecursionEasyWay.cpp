#include <iostream>
using namespace std;

// print n to 1 in decreasing order
void printDecreasing(int n) {
    if(n == 0) {
        return;
    }
    cout << n << " ";
    printDecreasing(n - 1);
}

// Print 1 to n in increasing order
void printIncreasing(int n) {
    if(n == 0) {
        return;
    } printIncreasing(n - 1);
    cout << n << " ";
}

// print increasing and decreasing both for n
void printDecreasingIncreasing(int n) {
    if(n == 0) {
        return;
    }
    cout << n << " ";
    printDecreasingIncreasing(n - 1);
    cout << n << " ";
}

// print power(num, pow) using linear expression
long long int powerOfX(int x, int n) {      // O(n)
    if(n == 0) {
        return 1;
    }
    return x * powerOfX(x, n - 1) * 1LL;
}

// print power(num, pow) using logarithmic expression
long long int powerOfXLog(int x, int n) {       // O(log(n))
    if(n == 0) {
        return 1;
    }
    long long int ansnb2 = powerOfXLog(x, n/2) * 1LL;
    long long int ans = ansnb2 * ansnb2;
    return n&1 ? ans * x : ans;
}

//print factorial of a number n
int factorial(int n){
    if(n == 0) {
        return 1;
    } return n * factorial(n - 1);
}

//print zigzag
void pzz(int n){
    if(n == 0) {
        return;
    }
    cout << n << " ";   // Pre
    pzz(n-1);   // Left Call
    cout << n << " ";   // In
    pzz(n-1);   // Right Call
    cout << n << " ";   // Post
}

// tower of hanoi problem
void towerOfHanoi(int nDisks, int beg = 1, int aux = 3, int end = 2) {
    if(nDisks == 0) {
        return;
    } towerOfHanoi(nDisks - 1, beg, end, aux);
    cout << nDisks << ": " << beg << "->" << end << endl;
    towerOfHanoi(nDisks - 1, aux, beg, end); 
}


// print array
void printArray(int *arr, int n, int index = 0) {
    if(index == n) {
        return;
    } cout << arr[index] << " ";
    printArray(arr, n, index + 1);
}

// print minimum element in the array
int maxOfArray(int *arr, int n) {
    if(n == 0) {
        return INT_MIN;
    } return max(arr[0], maxOfArray(arr + 1, n - 1));
}

// print maximum element in the array
int minOfArray(int *arr, int n) {
    if(n == 0) {
        return INT_MAX;
    } return min(arr[0], minOfArray(arr + 1, n - 1));
}