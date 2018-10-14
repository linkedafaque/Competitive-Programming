/* Given two weights of a and b units, in how many different ways you can achieve a weight of d units 
using only the given weights? Any of the given weights can be used any number of times (including 0 
number of times).

Constraints:
1 ≤T≤ 10^5
1 ≤ a < b ≤ 10^9
0 ≤ d ≤ 10^9

Input:
4
2 3 7
4 10 6
6 14 0
2 3 6

Output:
1
0
1
2
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

class Triplet {
public:
	ll gcd;
	ll x;
	ll y;
};

Triplet extended_euclid(ll a, ll b) {
	Triplet ans;
	if(b == 0) {
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;
		return ans;
	}

	Triplet smallAns = extended_euclid(b, a % b);
	
	ans.gcd = smallAns.gcd;
	ans.x = smallAns.y;
	ans.y = smallAns.x - ((a/b) * smallAns.y);
	return ans;
}

ll modInverse(ll a, ll m) {
	Triplet ans = extended_euclid(a, m);
	return ((ans.x % m) + m) % m;
}

ll euclid_gcd(ll a, ll b) {
	if(a < b)
		return euclid_gcd(b, a);
	
	if(b == 0)
		return a;
	
	return euclid_gcd(b, a % b);
}

int main() {
	ll tc;
	cin >> tc;

	while(tc--) {
		ll a, b, d;
		cin >> a >> b >> d;

		ll gcd = euclid_gcd(a, b);
		
		if(d % gcd != 0) {
			cout << "0" << endl;
			continue;
		}

		if(d == 0) {
			cout << "1" << endl;
			continue;
		}

		//Dividing by gcd to make a & b co-prime as mod-inverse
		//has to be calculated. For calculating mod-inverse gcd(a, b)
		//has to be equal to 1.
		
		a /= gcd;
		b /= gcd;
		d /= gcd;
		
		ll inv = modInverse(b, a);
		ll y1 = ((d % a) * inv) % a;
		
		if(d < (b * y1)) {
			cout << "0" << endl;
			continue;
		}

		ll n = ((d/b) -  y1) / a;
		cout << n + 1 << endl;
	}
	return 0;
}