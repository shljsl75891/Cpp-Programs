#include <iostream>
#include <string>
using namespace std;

void print_mazepaths_jump(int sr, int sc, int dc, int dr, string path = "") {
    if(sr == dr && sc == dc) {
        cout << path << "\n";
        return;
    } for(int ms = 1; ms <= dc - sc; ms++) { 
        print_mazepaths_jump(sr, sc + 1, dc, dr, path + 'h' + to_string(ms));
    } for(int ms = 1; ms <= dr - sr; ms++) { 
        print_mazepaths_jump(sr + 1, sc, dc, dr, path + 'v' + to_string(ms));
    } for(int ms = 1; ms <= dr - sr && ms <= dc - sc; ms++) { 
        print_mazepaths_jump(sr + 1, sc + 1, dc, dr, path + 'd' + to_string(ms));
    } 
}

int main() {
    int n; cin >> n;
    print_mazepaths_jump(0, 0, n - 1, n - 1);
}