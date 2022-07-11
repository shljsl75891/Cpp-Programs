#include <iostream>
#include <string>
using namespace std;

void print_sub_sequences(string s, string ans = "") {
	if (!s.size()) {
		cout << ans << " ";
		return;
	} string smaller_s = s.substr(1);
	print_sub_sequences(smaller_s, ans);
	print_sub_sequences(smaller_s, ans + s[0]);
}

int main() {
	string s; cin >> s;
	print_sub_sequences(s);
}