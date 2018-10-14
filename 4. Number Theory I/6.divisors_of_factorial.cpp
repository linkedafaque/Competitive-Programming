/*
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
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

void init(ll *primes, ll n) {
	primes[0] = 0;
	primes[1] = 0;
	for(ll i = 2; i <= n; i++)
		primes[i] = 1;
}

void sieve(ll *primes, ll n) {
	for(ll i = 2; i * i <= n; i++) {
		for(ll j = i * i; j <= n; j += i) {
			*(primes + j) = 0;
		}
	}
}

int main() {
	ll tc, primes[50001];
	cin >> tc;

	while(tc--) {
		ll n, possible_values = 1, count;
		cin >> n;

		init(primes, n);
		sieve(primes, n);

		//Power of 2 in 7!
		// =7/2 = 3
		// =3/2 = 1
		// =1/2 = 0
		//Total power of 2 = 3 + 1 + 0 = 4

		for(ll i = 2; i <= n; i++) {
			if(primes[i]) {
				ll copy = n, divisor;
				count = 0;
				while(true) {
					divisor = copy / i;
					copy = divisor;
					count += (divisor % MOD);
					if(divisor == 0)
						break;
				}
				possible_values = (((count + 1) % MOD) * (possible_values % MOD)) % MOD;
			}
		}
		cout << possible_values << endl;		
	}
}