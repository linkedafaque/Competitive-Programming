#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

void printSubstrings(string s, string output) {
	if(s.empty()) {
		cout << output << endl;
		return;
	}
	printSubstrings(s.substr(1), output);
	printSubstrings(s.substr(1), output + s[0]);
}

int main() {
	string s;
	cin >> s;
	printSubstrings(s, "");
	return 0;
}