#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int partition(int arr[], int si, int ei) {
	int pivot = arr[ei];
	int low = si - 1;

	for(int j = si; j <= ei; j++) {
		if(arr[j] <= pivot) {
			low++;
			swap(&arr[low], &arr[j]);
		}
	}
	return low;
}

void quick_sort(int arr[], int si, int ei) {
	if(si >= ei) 
		return;

	int pivot = partition(arr, si, ei);
	quick_sort(arr, si, pivot - 1);
	quick_sort(arr, pivot + 1, ei);
}

int main() {
	int n, arr[100];
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	quick_sort(arr, 0, n - 1);
	
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}