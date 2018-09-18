#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

void merge(int arr[], int si, int ei) {
	int mid = (si + ei) / 2;
	int i = si, j = mid + 1, temp, index = 0;
	int ans[ei - si + 1];

	while(i <= mid && j <= ei) {
		if(arr[i] < arr[j]) {
			ans[index++] = arr[i++];
		}
		else if(arr[j] < arr[i]) {
			ans[index++] = arr[j++];
		}
		else if(arr[i] == arr[j]) {
			ans[index++] = arr[i++];
			ans[index++] = arr[j++];
		}
	}

	while(i <= mid) {
		ans[index++] = arr[i++];
	}

	while(j <= ei) {
		ans[index++] = arr[j++];
	}

	int k = 0;
	for(int i = si; i <= ei; i++) {
		arr[i] = ans[k++]; 
	}
}

void merge_sort(int arr[], int si, int ei) {
	if(si >= ei)
		return;

	int mid = (si + ei) / 2;
	merge_sort(arr, si, mid);
	merge_sort(arr, mid + 1, ei);
	merge(arr, si, ei);
}

int main() {
	int n, arr[100];
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	merge_sort(arr, 0, n - 1);
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}