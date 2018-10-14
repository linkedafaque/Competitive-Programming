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

void init(bool *isprime, ll n) {
	isprime[0] = false;
	isprime[1] = false;

	for(ll i = 2; i <= n; i++) {
		*(isprime + i) = true;
	}
}

ll countPrimes(bool isprime[], ll n) {
	for(ll i = 2; i * i <= n; i++) {
		for(ll j = i * i; j <= n; j += i) {
			isprime[j] = false;
		}
	}

	ll count = 0;
	for(ll i = 2; i <= n; i++) {
		if(isprime[i])
			count++;
	}
	return count;
}

int main() {
	ll n;
	bool isprime[n + 1];
	cin >> n;
	
	init(isprime, n);
	cout << countPrimes(isprime, n) << endl;
}