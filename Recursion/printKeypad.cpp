#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> code = {",;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void print_keypad(string s, string ans = "") {
    if(s.length() == 0) {
        cout << ans << "\n";
        return;
    }
    char first = s.at(0);
    string rest = s.substr(1);
    string desired_code = code[first - '0'];
    for(int i = 0; i < desired_code.length(); i++) {
        char ch = desired_code.at(i);
        print_keypad(rest, ans + ch);
    }
}

int main() {
    string str; cin >> str;
    print_keypad(str);
}