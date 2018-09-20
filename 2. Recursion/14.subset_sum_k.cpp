#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

void print(int output[], int size) {
	for(int i = 0; i < size; i++) {
		cout << output[i] << " ";
	}
	cout << endl;
	return;
}

void printSubsetSumToKImpl(int input[], int size, int k, int cur_sum, int cur_index, int output[]) {
	if(size == 0)
	{
		if(cur_sum == k) 
			print(output, cur_index);
		return;

	}
	printSubsetSumToKImpl(input + 1, size - 1, k, cur_sum, cur_index, output);
	
	cur_sum += input[0];
	output[cur_index++] = input[0];
	printSubsetSumToKImpl(input + 1, size - 1, k, cur_sum, cur_index, output);
}

void printSubsetSumToK(int input[], int size, int k) {
	int output[1000];
	printSubsetSumToKImpl(input, size, k, 0, 0, output);
}

int main() {
	int arr[100], n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	printSubsetSumToK(arr, n, k);
	return 0;
}