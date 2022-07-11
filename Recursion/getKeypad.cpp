#include <bits/stdc++.h>
using namespace std;

vector<string> getSubSeq(string s) {
    if (s.length() == 0) {
        return {" "};
    }
    vector<string> rresult = getSubSeq(s.substr(1));
    vector<string> finalResult;
    for (string i : rresult) {
        finalResult.push_back(i);
    }
    for (string i : rresult) {
        finalResult.push_back(s[0] + i);
    }
    return finalResult;
}

int main() {
    string s = "abc";
    for (string i : getSubSeq(s)) {
        cout << i << endl;
    }
}