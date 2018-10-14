/*
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, 
your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to 
be 0-factorful.

Input:
5
1 3 1
1 10 2
1 10 3
1 100 3
1 1000 0

Output:
2 
2
0
8
1
*/

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
#define MOD 1000000007
using namespace std;

//Have to run loop till n here, because, if we run till sqrt(n), it will cancel cover the
//numbers that its pair has to cover, eg: for 15, 3 will cover 15 once, but it also has to
//be covered by 5 to make it have 2 prime factors hence the loop has to atleast run till n/2 

void precomute_sieve(ll *arr, ll n) {
	arr[0] = -1;
	
  	for(ll i = 1; i < n; i++) {
		*(arr + i) = 0;
	}

	for(ll i = 2; i < n; i++) {
		if(arr[i] != 0)
			continue;
		arr[i]++;
		for(ll j = i * 2; j < n; j += i) {
			arr[j]++;
		}
	}
}

int main() {
	ll tc, arr[1000001];
	cin >> tc;

	precomute_sieve(arr, 1000001);

	while(tc--) {
		ll a, b, n, count = 0;
		cin >> a >> b >> n;

		for(ll i = a; i <= b; i++) {
			if(arr[i] == n) {
				count++;
			}
		}
		cout << count << endl;
	}
}