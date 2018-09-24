#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

int returnPermutations(string input, string output[]) {
	if(input.empty())
		return 1;
	
	int start = 0, count;
	string o1[1000];
	
	for(int i = 0; i < input.size(); i++) {
		count = returnPermutations(input.substr(0, i) + input.substr(i + 1), o1);
		
		int k = 0;
		for(int j = start; j < (start + count); j++) {
			output[j] = input[i] + o1[k++];
		}
		
		start += count;
	}
	return start;
}

int main() {
	string input, output[1000];
	cin >> input;

	int count = returnPermutations(input, output);
	cout << count << endl;
	for(int i = 0; i < count; i++) {
		cout << output[i] << endl;
	}

	return 0;
}