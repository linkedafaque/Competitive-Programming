#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

int main() {
	int n, arr[100], output[1000][20];
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int count = subset(arr, n, output)
}