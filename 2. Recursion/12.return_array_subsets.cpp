#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

void swap(int *a, int * b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int subset(int input[], int size, int output[][20]) {

	if(size == 0) {
		output[0][0] = 0;
		return 1;
	}

	int count = subset(input + 1, size - 1, output);
	
	int i = 0;
	for(; i < count; i++) {
		for(int j = 0; j < (output[i][0] + 1); j++) {
			output[i + count][j] = output[i][j];
		}
	}

	for(; i < (2 * count); i++) {
		++output[i][0];
		output[i][output[i][0]] = input[0];
	}
	return 2 * count;
}


int main() {
	int n, arr[100], output[1000][20];
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int i = 0; j = n - 1;
	while(i > j) {
		swap(&arr[i], &arr[j]);
	}

	int count = subset(arr, n, output);

	for(int i = 0; i < count; i++) {
		int length = output[i][0];
		for(int j = 1; j <= length; j++) {
			cout << output[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}