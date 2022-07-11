#include <iostream>
using namespace std;

void print_mazepath(int sr, int sc, int dr, int dc, string path = "") {
    // maze reached at destination -> base case
    if(sc == dc && sr == dr) {
        cout << path << "\n";
        return;
    } 
    // horizontal paths
    if(sc < dc) {
        print_mazepath(sr, sc + 1, dr, dc, path + 'h');
    } 
    // vertical paths
    if(sr < dr) {
        print_mazepath(sr + 1, sc, dr, dc, path + 'v');
    }
}

int main() {
    int n; cin >> n;
    print_mazepath(0, 0, n - 1, n - 1);
}