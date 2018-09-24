#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k) {

	if(n == 0) {
		if(k == 0) {
			return 1;
		}
		return 0;
	}

	int o1[500][50];
	int s1 = subsetSumToK(input + 1, n - 1, o1, (k - input[0]));

	int o2[500][50];
	int s2 = subsetSumToK(input + 1, n - 1, o2, k);

	for(int i = 0; i < s1; i++) {
		++o1[i][0];
		o1[i][o1[i][0]] = input[0];
	}	

	if(s2 >= 1) {
		o2[0][0] = 0;
	}

	int i = 0, j = 0;
	while(i < s1) {
		while(j <= o1[i][0]) {
			output[i][j] = o1[i][j];
			j++;
		}
		i++;
	}

	i = 0; j = 0;
	while(i < s2) {
		while(j <= o2[i][0]) {
			output[i + s1][j] = o2[i][j];
			j++; 
		}
		i++;
	}

	return s1 + s2;
}

int main() {
	int n, arr[100], output[1000][50], k;
	cin >> n >> k;
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int count = subsetSumToK(arr, n, output, k);
	cout << "count: " << count << endl;

	for(int i = 0; i < count; i++) {
		int length = output[i][0];
		for(int j = 1; j <= length; j++) {
			cout << output[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}