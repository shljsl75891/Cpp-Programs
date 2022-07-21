/* 3 Basic Steps to approach 
* Optimal Solution Using DYNAMIC PROGRAMMING
* Top-Down -> Recursion + Memoization(storing the solution of overlapping subproblems)
* Botton-Up -> Tabulation
* Space Optimization -> here we need, Brain Storming
*/

#include <iostream>
#include <vector>
using namespace std;

// Using Memoization
int fibonacciM(int n, vector<int> &dp) {
    if(n == 0 || n == 1) {
        dp[n] = n;
    } if(dp[n] == -1) {
        dp[n] = fibonacciM(n - 1, dp) + fibonacciM(n - 2, dp);
    } return dp[n];
}

// Using Tabulation
int fibonacciT(int n, vector<int> &dp) {
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    } return dp[n];
}

// Space Optimization
int fibonacciSO(int n) {
    if(n == 0 || n == 1) {
        return n;
    } int curr, prev0 = 0, prev1 = 1;
    for(int i = 2; i <= n; i++) {
        curr = prev0 + prev1;
        prev0 = prev1;
        prev1 = curr;
    } return curr;
}


int main() {
    int n; cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fibonacciSO(n);
}