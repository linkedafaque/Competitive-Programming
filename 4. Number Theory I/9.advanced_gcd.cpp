/*
Varun explained its friend Sanchit the algorithm of Euclides to calculate the GCD of two numbers. Then Sanchit 
implements the algorithm

int gcd(int a, int b)
{

    if (b==0)
    return a;
    else
    return gcd(b,a%b);
}

and challenges to Varun to calculate gcd of two integers, one is a little integer and other integer has 250 digits.
Your task is to help Varun an efficient code for the challenge of Sanchit.
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
#define ll unsigned long long int
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

ll euclid_gcd(ll a, ll b) {
	if(b > a) 
		return euclid_gcd(b, a);
	if(b == 0) 
		return a;
	return euclid_gcd(b, a % b);
}

ll reduceGcdPair(string a, ll m) {
	ll arr[10000];
	ll length = a.size();

	arr[0] = 1;
	ll start = 1;

	for(ll i = 1; i < length; i++) {
		arr[i] = ((start %m)  * (10 % m)) % m;
		start = arr[i];
	}

	ll i = 0, j = length - 1, sum = 0;
	while(i < length && j >= 0) {
		sum += ((arr[i]) % m *  (a[j] - '0') % m) % m;
		i++; j--;
	}
	return sum % m;
}

int main() {
	ll tc, a;
	string b;
	cin >> tc;

	while(tc--) {
		cin >> a >> b;
		if(a == 0) {
			cout << b << endl;
			continue;
		}
		ll x = reduceGcdPair(b, a);
		cout << euclid_gcd(a, x) << endl;
	}
	return 0;
}