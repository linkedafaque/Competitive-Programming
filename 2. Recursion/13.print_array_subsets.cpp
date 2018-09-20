#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

void print(int output[], int cur_index) {
	for(int i = 0; i < cur_index; i++) {
		cout << output[i] << " ";
	}
	cout << endl;
}

void printSubsetsOfArrayImpl(int input[], int output[], int size, int cur_index) {
	if(size == 0) {
		print(output, cur_index);
		return;
	}
	printSubsetsOfArrayImpl(input + 1, output, size - 1, cur_index);
	output[cur_index++] = input[0];
	printSubsetsOfArrayImpl(input + 1, output, size - 1, cur_index);
	
}

void printSubsetsOfArray(int input[], int size) {
	int output[2000];
    printSubsetsOfArrayImpl(input, output, size, 0);
}

int main() {
	int input[100], n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}
	printSubsetsOfArray(input, n);
	return 0;
}