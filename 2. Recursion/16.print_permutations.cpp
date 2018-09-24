#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

void printPermutationsImpl(string input, string output) {
	if(input.empty()) {
		cout << output << endl;
	}

	string altered_input = "";
	for(int i = 0; i < input.size(); i++) {
		altered_input = input.substr(0, i) + input.substr(i + 1);
		printPermutationsImpl(altered_input, output + input[i]);
	}
}

void printPermutations(string input) {
  	printPermutationsImpl(input, "");
}

int main() {
	string input;
	cin >> input;
	printPermutations(input);
	return 0;
}