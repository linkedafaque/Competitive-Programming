#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
#define ll long long int
using namespace std;

ll merge(ll arr[], ll si, ll mid, ll ei) {
	int i = si, j = mid + 1, count = 0, k = si, temp[ei - si + 1];

	while(i <= mid && j <= ei) {
		if(arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		}
		else if(arr[i] > arr[j]) {
			count += (mid - i + 1);
			temp[k++] = arr[j++];
		}
		else {
			i++; j++;
		}
	}

	while(i <= mid) {
		temp[k++] = arr[i++];
	}

	while(j <= ei) {
		temp[k++] = arr[j++];
	}

	for(int p = 0 ; i < k; i++) {
		arr[si++] = temp[p];
	}

	return count;
}

ll inversions_helper(ll arr[], ll si, ll ei) {
	if(si >= ei) {
		return 0;
	}

	int mid = (si + ei)/2;
	int count_left = inversions_helper(arr, si, mid);
	int count_right = inversions_helper(arr, mid + 1, ei);
	return count_left + count_right + merge(arr, si, mid, ei);
}

ll inversions(ll arr[], ll n) {
	return inversions_helper(arr, 0, n - 1);
} 

int main() {
	ll n, arr[100000];
	cin >> n;

	for(ll i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ll count = inversions(arr, n);
	cout << count << endl;

	return 0;
}