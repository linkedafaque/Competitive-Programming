#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

string h(int num) {
	unordered_map<int, string> m;
	m.clear();
	m[0] = "";
	m[1] = "";
	m[2] = "abc";
	m[3] = "def";
	m[4] = "ghi";
	m[5] = "jkl";
	m[6] = "mno";
	m[7] = "pqrs";
	m[8] = "tuv";
	m[9] = "wxyz";
	return m[num];
}

void printKeypad(int num, string output) {
	if(num == 0)
		cout << output << endl;

	int lastdigit = num % 10;
	string curstring = h(lastdigit);

	for(int i = 0; i < curstring.size(); i++) {
		printKeypad(num / 10, curstring[i] + output);
	}
}

int main() {
	int num;
	cin >> num;
	printKeypad(num, "");
	return 0;
}