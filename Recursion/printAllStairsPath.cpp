#include <iostream>
#include <string>
using namespace std;

void print_stairs_path(int n, string path = "") {
    if(n < 0) {
        return;
    } else if(n == 0) {
        cout << path << "\n";
        return;
    } for(int i = 1; i <= n; i++) {
        string p_ch = to_string(i);
        print_stairs_path(n - i, path + p_ch);
    }
}

int main() {
    int n; cin >> n;
    print_stairs_path(n);
}
