#include <iostream>
using namespace std;
const int N = 1e5;
bool sieve[N];

int main() {
    int n; cin >> n;
    int cnt = 0; 
    // True-> Not Prime
    // False-> Prime
    sieve[0] = sieve[1] = true;
    for(int i = 2; i <= n; i++) {
        if(sieve[i] == false) {
            for(int j = i * 2; j <= n; j += i) 
                sieve[j] = true;
            }
        }
    } for(int i = 0; i <= n; i++) {
        if(sieve[i] == false) {
            cnt++; cout << i;
            cout << (cnt % 10 ? " " : "\n");
        }
    } cout << "\nNumber of Primes: " << cnt;
}