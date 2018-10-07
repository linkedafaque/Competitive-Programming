#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
#include<algorithm>
#include<climits>
#define ll long long int
#define MAX 1000000000
using namespace std;

ll checkMid(ll arr[], ll mid, ll c, ll n) {
	c--;
	ll last_pos = 0;
	for(ll i = 1; i < n; i++) {
		if((arr[i] - arr[last_pos]) >= mid) {
			c--;
			last_pos = i;
		}
		if(c == 0)
			break;
	}
	return (c == 0);
}

int main() {
	ll tc, n, c, arr[100000];
	cin >> tc;

	while(tc--) {
		cin >> n >> c;
		for(ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		ll start = 1, end = MAX, max = INT_MIN;

		while(start <= end) {
			ll mid = (start + end) / 2;
			ll check = checkMid(arr, mid, c, n);

			if(check) {
				max = mid > max ? mid : max;
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		cout << max << endl;
	}
}