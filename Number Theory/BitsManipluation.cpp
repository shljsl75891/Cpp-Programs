#include <iostream>
using namespace std;

void printBinary(int num) {
    for(int i = 3; i >= 0; i--) {
        // basically, shifting ith bit to 0th bit and printing
        cout << ((num >> i) & 1);
    } cout << "\n";
}

int main() {
    int num = 9;
    // printing binary representation -> 1001
    printBinary(num);
    // set 2nd bit -> 1101
    printBinary(num | (1 << 2)); 
    // unset 3rd bit -> 0001
    printBinary(num & (~(1 << 3)));
    // toggle 1st bit -> 1011
    printBinary(num ^ (1 << 1));
}