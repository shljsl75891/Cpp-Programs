#include <iostream>
#include <string>
using namespace std;

void print_permutations(string &str, int index = 0) {
    if(index == str.length() - 1) {
        cout << str << endl;
        return;
    }
    for(int i = index; i < str.length(); i++) {
        swap(str[index], str[i]);
        print_permutations(str, index + 1);
        swap(str[index], str[i]); // Back-Tracking
    }
}

int main() {
    string str; cin >> str;
    print_permutations(str);
}